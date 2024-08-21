#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <print_save.h>

int main(){
	#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	#endif

	DataAsText data_as_text("It is a text");
	DataAsHTML data_as_html("It is html");
	DataAsJSON data_as_json("It is json");

	std::cout << data_as_text.print() << std::endl;
	 
	std::cout << data_as_html.print() << std::endl;
	
	std::cout << data_as_json.print() << std::endl;
	
	
	
	std::ofstream as_text, as_html, as_json;
	as_text.open("as_text.txt"); as_html.open("as_html.txt"); as_json.open("as_json.txt");
	if(as_text.is_open()) saveTo(as_text, &data_as_text);
	if(as_html.is_open()) saveTo(as_html, &data_as_html);
	if(as_json.is_open()) saveTo(as_json, &data_as_json);
	
	as_text.close(); as_html.close(); as_json.close();
	

	#ifdef _WIN32
	system("pause");
	#endif

	return 0;
}