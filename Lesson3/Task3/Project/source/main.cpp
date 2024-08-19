#ifdef _WIN32
#include <windows.h>
#endif

#include <log_message.h>

int main(){
	#ifdef _WIN32
	SetConsoleCP(CP_UTF8)
	SetConsoleOutputCP(CP_UTF8)
	#endif
	
	Logging my_log;
	
	my_log.get_log("Warning");
	my_log.get_log("Error");
	my_log.get_log("FatalError");
	my_log.get_log("UnknownMessage");
	
	#ifdef _WIN32
	system("pause")
	#endif
	
	return 0;
}