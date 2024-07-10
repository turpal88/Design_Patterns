#pragma once
#include <sql_query_builder.h>


query::query() {
	this->final_query = "SELECTFROMWHERE";
	
	txt_regex = "[А-ЯA-Z]+[a-zа-я]+";
}

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
	
	count_of_add_where_calls = 0;
	is_from_entered = false;
	is_at_least_one_column_entered = false;
	is_where_entered = false;
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
		
		lk.unlock();
		
		return *this;

		});
	
	this->is_where_entered = true;
	cv1.notify_one();
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


AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddColumn(std::string field) {
	SqlSelectQueryBuilder::AddColumn(field);
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddFrom(std::string table_name) {
	SqlSelectQueryBuilder::AddFrom(table_name);
	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhere(std::map<std::string, std::string>& kv) {
	SqlSelectQueryBuilder::AddWhere(kv);
	return *this;
}


AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::SomeMethod(char mark) {
	
	std::future<AdvancedSqlSelectQueryBuilder&> ft = std::async(std::launch::deferred, [&mark, this]() -> AdvancedSqlSelectQueryBuilder& {
		std::unique_lock<std::mutex> lk(mtx);
		cv1.wait(lk, [this]() {return this->is_where_entered; });

		std::string::iterator it = std::find(this->q.final_query.begin(), this->q.final_query.end(), '=');
		std::vector<char>::iterator it1 = std::find(marks.begin(), marks.end(), mark);
		if (it1 == marks.end()) {
			throw std::out_of_range("Передан невалидный знак в метод SomeMetod");
			return *this;
		}
		else if(it == this->q.final_query.end()) {
			throw std::out_of_range("В финальном запросе не найден знак '='");
			return *this;
		}
		else {
			std::vector<std::pair<char, int>> query_mark_array;
			for (int i = 0; i < this->q.final_query.size(); ++i) {
				if (this->q.final_query[i] == '=') query_mark_array.push_back({ this->q.final_query[i] , i });

			}
			for (auto& t : query_mark_array) this->q.final_query[t.second] = mark;


		}
		return *this;
		});
	
	return ft.get();
	
	
}
