#include <error_handler.h>
#include <log_message_export.h>
#include <vector>

class Logging{
	
	private:
	std::vector<std::shared_ptr<LogMessage>> log_message_pointer_vector;
	
	//char index;
	//const std::string log_type;
	void set_next_handler(char& counter);
	protected:
	
	public:
	API_LOG_MESSAGE Logging();
	//API_LOG_MESSAGE std::shared_ptr<LogMessage> next_handler;
	API_LOG_MESSAGE void get_log(const std::string log_type, const std::string dest = "");
};