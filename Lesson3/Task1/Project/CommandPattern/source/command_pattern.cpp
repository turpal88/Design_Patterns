#include <command_pattern.h>

Printer::Printer(const std::string&& message, const std::string&& dest) : message(message), dest(dest) {}

void Printer::make_print_on_screen(){
	 std::cout << std::endl << message << std::endl;
	
	
	
	
}


void Printer::make_print_in_file(){
	
	std::ofstream out;
	out.open(dest);
		
	if(out.is_open()) out << message; else throw std::out_of_range("Wrong path to out-file");
	out.close();
	
}


PrintOnScreen::PrintOnScreen(Printer& printer) : printer(printer){}
void PrintOnScreen::print(){
	
	printer.make_print_on_screen();
}

PrintOnFile::PrintOnFile(Printer& printer) : printer(printer){}
void PrintOnFile::print(){
	try{
		
		printer.make_print_in_file();
	}
	catch(std::out_of_range& e){
		
		std::cout << e.what() << std::endl;
	}
	
}

PrintOnScreen::~PrintOnScreen() {}
PrintOnFile::~PrintOnFile() {}


Invoker::Invoker() {}

void Invoker::print(LogCommand* Cmd){
	
	Cmd -> print();
}