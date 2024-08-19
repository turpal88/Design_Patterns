
#include <observer.h>



char Observer::get_message_type(){
	return message_type;
	
}


WarningObserver::WarningObserver() {
	message_type = 1;
	//Условимся что для наблюдателя за Warning message_type = 1;
	//if(message_type != 1) throw std::out_of_range("Wrong warning-type-message transfered");
}

ErrorObserver::ErrorObserver() {
	message_type = 2;
	//Условимся что для наблюдателя за Error message_type = 2;
	//if(message_type != 2) throw std::out_of_range("Wrong error-type-message transfered");
}

FatalErrorObserver::FatalErrorObserver() {
	message_type = 3;
	//Условимся что для наблюдателя за FatalError message_type = 3;
	//if(message_type != 3) throw std::out_of_range("Wrong FatalError-type-message transfered");
}

void ObservedClass::push_observer_to_observer_vector(std::shared_ptr<Observer> observer_pointer){
	observer_vector.push_back(observer_pointer);
	 
	
}

void ObservedClass::warning(const std::string& message) const {
	
	//std::cout << message << std::endl;
	char message_type = -1;
	for(int i = 0; i < observer_vector.size(); ++i) {
		
		if(observer_vector.at(i) -> get_message_type() == 1) {
			
			observer_vector.at(i) -> onWarning(message);
		}
	}
	
}

void ObservedClass::error(const std::string& message) const {
	
	
	
	char message_type = -1;
	for(int i = 0; i < observer_vector.size(); ++i) {
		
		if(observer_vector.at(i) -> get_message_type() == 2) {
			
			observer_vector.at(i) -> onError(message);
		}
	}
}

void ObservedClass::fatalError(const std::string& message) const {
	
	//std::cout << message << std::endl;
	char message_type = -1;
	for(int i = 0; i < observer_vector.size(); ++i) {
		
		if(observer_vector.at(i) -> get_message_type() == 3) {
			
			observer_vector.at(i) -> onFatalError(message);
		}
	}
}

void WarningObserver::onWarning(const std::string& message) {
std::cout << message << std::endl; 	
}

void WarningObserver::onError(const std::string& message, const std::string& dest) {}
void WarningObserver::onFatalError(const std::string& message, const std::string& dest) {}

void ErrorObserver::onError(const std::string& message, const std::string& dest) {
	
	std::cout << message << std::endl; 
	std::ofstream output_stream;
	if(dest == "") output_stream.open("onError.txt"); else output_stream.open(dest);
	if(output_stream.is_open()) {
		output_stream << message;
		output_stream.close();
		
	}else throw std::out_of_range("Wrong path to onError file");
}

void ErrorObserver::onWarning(const std::string& message) {}
void ErrorObserver::onFatalError(const std::string& message, const std::string& dest) {}

void FatalErrorObserver::onFatalError(const std::string& message, const std::string& dest) {
	
	std::cout << message << std::endl;
	std::ofstream output_stream;
	if(dest == "") output_stream.open("onFatalError.txt"); else output_stream.open(dest);
	if(output_stream.is_open()) {
		output_stream << message;
		output_stream.close();
		
	}else throw std::out_of_range("Wrong path to onFatalError file");
}

void FatalErrorObserver::onWarning(const std::string& message) {}
void FatalErrorObserver::onError(const std::string& message, const std::string& dest) {}


WarningObserver::~WarningObserver() {}
ErrorObserver::~ErrorObserver() {}
FatalErrorObserver::~FatalErrorObserver() {}