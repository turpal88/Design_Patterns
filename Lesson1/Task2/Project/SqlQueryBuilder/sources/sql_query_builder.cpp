#pragma once
#include <sql_query_builder.h>


query::query() {
	this->final_query = "SELECTFROMWHERE";
	
	txt_regex = "[À-ßA-Z]+[a-zà-ÿ]+";
}

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
	count_of_add_where_calls = 0;
	is_from_entered = false;
	is_at_least_one_column_entered = false;
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string field){
	
	
	
	std::future<SqlSelectQueryBuilder&> ft = std::async(std::launch::deferred, [&field, this]() -> SqlSelectQueryBuilder& {
		std::lock_guard<std::mutex> lk(mtx);
		
		std::size_t it =  this->q.final_query.find("SELECT");
		
		this->q.final_query.insert(it + 6, " " + field + ", ");
		if (this->is_at_least_one_column_entered) this->q.final_query.erase(this->q.final_query.find(',') + 1, 1);
		
		
		if (!this->is_at_least_one_column_entered) this->is_at_least_one_column_entered = true;
		
		return *this;

		});

	

	
	return ft.get();
	
}



SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string table_name){
	
	std::future<SqlSelectQueryBuilder&> ft = std::async(std::launch::deferred, [&table_name, this]() -> SqlSelectQueryBuilder& {
		std::unique_lock<std::mutex> lk(mtx);
		size_t it = this->q.final_query.find("FROM");
		this->q.final_query.insert(it + 4, " " + table_name + " ");
		
		lk.unlock();
		cv.notify_one();
		return *this;

		});

	
	this->is_from_entered = true;
	
	
	return ft.get();
	
	
	
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::map<std::string, std::string>& kv){
	
	
	std::future<SqlSelectQueryBuilder&> ft = std::async(std::launch::deferred, [&kv, this]() -> SqlSelectQueryBuilder& {
		std::unique_lock<std::mutex> lk(mtx);
		cv.wait(lk, [this]() {return this->is_from_entered; });
		size_t it = this->q.final_query.size() - 1;
		
		for (const auto& t : kv) {
			std::string where_string = (std::regex_match(t.second, this->q.txt_regex)) ? " " + t.first + "='" + t.second + "'" : " " + t.first + "=" + t.second;
			if (count_of_add_where_calls > 0) where_string += " AND";
			this->q.final_query.insert(it + 1, where_string);
			++count_of_add_where_calls;
		}
		
		
		
		return *this;

		});
	
	
	
	return ft.get();
	
}





std::string SqlSelectQueryBuilder::BuildQuery() {
	
	size_t it2 = this->q.final_query.find("FROM") - 2;
	
		if (this->q.final_query.at(it2) == ',') this->q.final_query.erase(it2, 1);
		if (!this->is_at_least_one_column_entered) {

			size_t it = this->q.final_query.find("SELECT");
			this->q.final_query.insert(it + 6, " * ");
		}

		
		this->q.final_query.insert(this->q.final_query.size(), ";");

	
	return this->q.final_query;
 
}
