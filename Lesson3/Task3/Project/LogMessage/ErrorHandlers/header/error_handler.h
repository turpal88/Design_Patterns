#include <export.h>
#include <fstream>
#include <memory>
#include <iostream>

API_ERROR_HANDLERS typedef std::string Type;

class LogMessage {
	private:
	
protected:
    //LogMessage();
    API_ERROR_HANDLERS Type _type;
    API_ERROR_HANDLERS std::string _message;
    API_ERROR_HANDLERS Type type();
	API_ERROR_HANDLERS std::string message();
	
	
	public:
	API_ERROR_HANDLERS virtual void pop_log_info(const std::string dest = "");
	API_ERROR_HANDLERS std::shared_ptr<LogMessage> next_handler;
};


class WarningLogMessage : public LogMessage{
	private:
	
	protected:
	
	public:
	API_ERROR_HANDLERS WarningLogMessage();
	
	API_ERROR_HANDLERS void pop_log_info(const std::string dest = "") override;
	//Type type() const override;
	//const std::string& message() const override;
	
};

class ErrorLogMessage : public LogMessage{
	private:
	
	protected:
	
	public:
	 API_ERROR_HANDLERS ErrorLogMessage();
	//API_ERROR_HANDLERS std::shared_ptr<LogMessage> next_handler;
	API_ERROR_HANDLERS void pop_log_info(const std::string dest = "") override;
	//Type type() const override;
	//const std::string& message() const override;
	
};


class FatalErrorLogMessage : public LogMessage{
	private:
	
	protected:
	
	public:
	API_ERROR_HANDLERS FatalErrorLogMessage();
	//API_ERROR_HANDLERS std::shared_ptr<LogMessage> next_handler;
	API_ERROR_HANDLERS void pop_log_info(const std::string dest = "") override;
	//Type type() const override;
	//const std::string& message() const override;
	
};

class UnknownMessageLog : public LogMessage{
	private:
	
	protected:
	
	public:
	 API_ERROR_HANDLERS UnknownMessageLog();
	//API_ERROR_HANDLERS std::shared_ptr<LogMessage> next_handler;
	 API_ERROR_HANDLERS void pop_log_info(const std::string dest = "") override;
	//Type type() const override;
	//const std::string& message() const override;
	
};
