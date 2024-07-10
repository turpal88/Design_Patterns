
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
	
	
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
   

    std::cout << query_builder.BuildQuery() << std::endl;

#ifdef _WIN32
system("pause");
#endif


return 0;
}