#ifdef _WIN32
#include <windows.h>
#endif


#include <command_pattern.h>

int main(){
	#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	#endif
	
	Printer p1("This is P1 printer");
	Printer p2("This is P2 printer", "out2.txt");
	Printer p3("This is P3 printer");
	Printer p4("This is P4 printer", "out4.txt");
	Printer p5("This is P5 printer");
	
	PrintOnScreen pos1(p1);
	PrintOnScreen pos3(p3);
	PrintOnScreen pos5(p5);
	PrintOnFile pos2(p2);
	PrintOnFile pos4(p4);
	
	Invoker inv;
	
	inv.print(&pos1);
	inv.print(&pos2);
	inv.print(&pos3);
	inv.print(&pos4);
	inv.print(&pos5);
	
	
	
	
	#ifdef _WIN32
	system("pause");
	#endif
	
	return 0;
}