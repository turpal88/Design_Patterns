#include <export.h>
#include <iostream>
#include <fstream>

class Printer{
	private:
	//const std::string name;
	const std::string message;
	const std::string dest;
	public:
	
	API_COMMAND_PATTERN Printer(const std::string&& message, const std::string&& dest = "");
	void API_COMMAND_PATTERN make_print_on_screen();
	void API_COMMAND_PATTERN make_print_in_file();
	
};


class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print() = 0;
}; 


class PrintOnScreen : public LogCommand{
	private:
	Printer& printer;
	public:
	API_COMMAND_PATTERN PrintOnScreen(Printer& printer);
	API_COMMAND_PATTERN ~PrintOnScreen();
	virtual void API_COMMAND_PATTERN print() override;
};

class PrintOnFile : public LogCommand{
	private:
	Printer& printer;
	public:
	API_COMMAND_PATTERN PrintOnFile(Printer& printer);
	API_COMMAND_PATTERN ~PrintOnFile();
	virtual void API_COMMAND_PATTERN print() override;
};

class Invoker{
	//private:
	//LogCommand* Cmd;
	public:
	API_COMMAND_PATTERN Invoker();
	API_COMMAND_PATTERN void print(LogCommand* Cmd);
};