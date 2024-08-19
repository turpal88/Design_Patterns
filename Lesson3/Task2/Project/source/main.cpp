#ifdef _WIN32
#include <windows.h>
#endif

#include <observer.h>

int main(){
	#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	#endif
	
	
	ObservedClass oc;
	WarningObserver wo;
	ErrorObserver eo;
	FatalErrorObserver feo;
	
	oc.push_observer_to_observer_vector(std::make_shared<WarningObserver>(wo));
	oc.push_observer_to_observer_vector(std::make_shared<ErrorObserver>(eo));
	oc.push_observer_to_observer_vector(std::make_shared<FatalErrorObserver>(feo));
	
	oc.warning("warning message");
	oc.error("error message");
	oc.fatalError("Fatal error message");
	
	
	#ifdef _WIN32
	system("pause");
	#endif
	
	
	return 0;
}