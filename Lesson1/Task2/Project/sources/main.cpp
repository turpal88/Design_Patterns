
#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include "sql_query_builder.h"

int main(){
#ifdef _WIN32	
SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0002);
#endif 
	
    std::map<std::string, std::string> kv{ {"id", "42"}, { "name", "John" }, { "phone", "123568" } };
	
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    
    query_builder.AddWhere(kv);
    
   

    std::cout << query_builder.BuildQuery() << std::endl;

#ifdef _WIN32
system("pause");
#endif


return 0;
}