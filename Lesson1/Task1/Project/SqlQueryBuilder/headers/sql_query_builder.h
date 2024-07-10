#include <vector>
#include <mutex>
#include <condition_variable>
#include <future>
#include <algorithm>
#include <regex>


#include <export.h>
class SqlSelectQueryBuilder;


struct query{
	friend class SqlSelectQueryBuilder;
	public:
	
	query(const query& q) = delete;
	query& operator=(const query& q) = delete;
	
private:
	std::string table_name;
	std::vector<std::string> columns;
	
	std::string final_query;
	query();
	std::regex txt_regex;
};

class SqlSelectQueryBuilder{
	public:
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder();
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddColumn(std::string field);
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddFrom(std::string table_name);
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddWhere(std::string key, std::string value);
	API_SQL_QUERY_BUILDER std::string BuildQuery();
	private:
	query q;
	std::mutex mtx;
	std::condition_variable cv;
	int count_of_add_where_calls;
	
	bool is_from_entered;
	bool is_at_least_one_column_entered;
};