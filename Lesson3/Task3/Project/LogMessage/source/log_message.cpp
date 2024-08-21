#include <log_message.h>

Logging::Logging() {
	log_message_pointer_vector.push_back(std::make_shared<WarningLogMessage>());
	log_message_pointer_vector.push_back(std::make_shared<ErrorLogMessage>());
	log_message_pointer_vector.push_back(std::make_shared<FatalErrorLogMessage>());
	log_message_pointer_vector.push_back(std::make_shared<UnknownMessageLog>());
	
	log_message_pointer_vector.at(0) -> next_handler = log_message_pointer_vector.at(1);
	log_message_pointer_vector.at(1) -> next_handler = log_message_pointer_vector.at(2);
	log_message_pointer_vector.at(2) -> next_handler = log_message_pointer_vector.at(3);
	log_message_pointer_vector.at(3) -> next_handler = log_message_pointer_vector.at(0);
	
}


void Logging::set_next_handler(char& counter){ ++counter; }


void Logging::get_log(const std::string log_type, const std::string dest){
	
	char counter = 0;
	
	while(counter <= 3){
		//try{
			if(log_type == log_message_pointer_vector.at(counter) -> type()) {
			try{
				log_message_pointer_vector.at(counter) -> pop_log_info(dest);
			}catch(std::invalid_argument& e){
				std::cout << "Exception generated: " << e.what() << std::endl;
			}
			catch (std::out_of_range& e) {

					std::cout << "Exception generated: " << e.what() << std::endl;
			}
				
		
			
			break;
		}else if(counter < 3) set_next_handler(counter); 
		else log_message_pointer_vector.at(3) -> pop_log_info(dest);
			
	//	}catch(std::out_of_range& e){
			
		//	std::cout << "Exception generated: " << e.what() << std::endl;
	//	}
		
			
		
			
		
			
			
		
	}
}