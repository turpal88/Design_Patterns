#include <error_handler.h>



WarningLogMessage::WarningLogMessage() {
	
	_type = "Warning";
	_message = "Warning occured";
}
	
ErrorLogMessage::ErrorLogMessage() {
	
	_type = "Error";
	_message = "Error occured";
}	

FatalErrorLogMessage::FatalErrorLogMessage() {
	_type = "FatalError";
	_message = "FatalError occured";
	
}	

UnknownMessageLog::UnknownMessageLog() {
	_type = "UnknownMessage";
	_message = "UnknownMessage occured";
	
}



Type LogMessage::type() {
	
	return _type;
}

std::string LogMessage::message() {
	return _message;
}

void WarningLogMessage::pop_log_info(const std::string dest){
	
	std::cout << "Type of message - " << this->type() << " " << this->message() << std::endl;
}

void ErrorLogMessage::pop_log_info(const std::string dest){
	std::ofstream of;
	if(dest == "") of.open("error_message.txt"); else of.open(dest);
	if(of.is_open()) of << "Type of message - " << this->type() << " " << this->message();
	else throw std::out_of_range("Wrong path of output file");
}

void FatalErrorLogMessage::pop_log_info(const std::string dest){
	const std::string str = "Type of message " + this->type() + " " + this->message();
	throw std::out_of_range(str);
	
}

void UnknownMessageLog::pop_log_info(const std::string dest){
	
	const std::string str = "Type of message " + this->type() + " " + this->message();
	throw std::invalid_argument(str);
}