
#include <export.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class Observer {
protected:
    char message_type;
    
   
public:
    char get_message_type();
    virtual void onWarning(const std::string& message) = 0;
    virtual void onError(const std::string& message, const std::string& dest = "") = 0;
    virtual void onFatalError(const std::string& message, const std::string& dest = "") = 0;
	virtual ~Observer() = default;
};

class ObservedClass{
	private:
	std::vector<std::shared_ptr<Observer>> observer_vector;
	public:
	
	void API_OBSERVER push_observer_to_observer_vector(std::shared_ptr<Observer> observer_pointer);
	void API_OBSERVER warning(const std::string& message) const;
    void API_OBSERVER error(const std::string& message) const;
    void API_OBSERVER fatalError(const std::string& message) const;
	
};

class WarningObserver : public Observer{
	
    
	public:
	API_OBSERVER WarningObserver();
	void API_OBSERVER onWarning(const std::string& message) override;
	void API_OBSERVER onError(const std::string& message, const std::string& dest) override;
	void API_OBSERVER onFatalError(const std::string& message, const std::string& dest) override;
	API_OBSERVER ~WarningObserver();
	
};

class ErrorObserver : public Observer{
	public:
	API_OBSERVER ErrorObserver();
	void API_OBSERVER onWarning(const std::string& message) override;
	void API_OBSERVER onError(const std::string& message, const std::string& dest) override;
	void API_OBSERVER onFatalError(const std::string& message, const std::string& dest) override;
	API_OBSERVER ~ErrorObserver();
	
};

class FatalErrorObserver : public Observer{
	public:
	API_OBSERVER FatalErrorObserver();
	void API_OBSERVER onWarning(const std::string& message) override;
	void API_OBSERVER onError(const std::string& message, const std::string& dest) override;
	void API_OBSERVER onFatalError(const std::string& message, const std::string& dest) override;
	API_OBSERVER ~FatalErrorObserver();
	
};
    
