#include <vector>
#include <mutex>
#include <condition_variable>
#include <future>
#include <map>
#include <regex>
#include <algorithm>
//#include <utility>

#include <export.h>
class SqlSelectQueryBuilder;


struct query{
	friend class SqlSelectQueryBuilder; friend class AdvancedSqlSelectQueryBuilder;
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
		//API_SQL_QUERY_BUILDER SqlSelectQueryBuilder();
		API_SQL_QUERY_BUILDER std::string BuildQuery();
		//API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddWhere(std::map<std::string, std::string>& kv);
		//API_SQL_QUERY_BUILDER std::string BuildQuery();
protected:
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder();
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddColumn(std::string field);
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddFrom(std::string table_name);
	API_SQL_QUERY_BUILDER SqlSelectQueryBuilder& AddWhere(std::map<std::string, std::string>& kv);
		
		
	query q;
	std::mutex mtx;
	std::condition_variable cv, cv1;
	int count_of_add_where_calls;
	
	bool is_from_entered;
	bool is_at_least_one_column_entered;
	bool is_where_entered;
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {

public:
	API_SQL_QUERY_BUILDER AdvancedSqlSelectQueryBuilder& AddColumn(std::string field);
	API_SQL_QUERY_BUILDER AdvancedSqlSelectQueryBuilder& AddFrom(std::string table_name);
	API_SQL_QUERY_BUILDER AdvancedSqlSelectQueryBuilder& AddWhere(std::map<std::string, std::string>& kv);
	
	API_SQL_QUERY_BUILDER AdvancedSqlSelectQueryBuilder& SomeMethod(char mark);

private:
	std::vector<char> marks{ '>', '<' };
};