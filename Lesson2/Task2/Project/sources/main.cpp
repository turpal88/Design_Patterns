
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>




#include <veryheavydb.h>







int main() {
#ifdef _WIN32	
SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0002);
#endif 

auto real_db = VeryHeavyDatabase();
auto limit_db = OneShotDB(std::addressof(real_db), 2);
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;

    
	
#ifdef _WIN32
system("pause");
#endif

	
    return 0;
}