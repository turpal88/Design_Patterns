#include <fstream>


class Printable
{
public:
    virtual std::string print() const = 0;
    //virtual std::string printAsText() const = 0;
    //virtual std::string printAsJSON() const = 0;
protected:
	enum class Format
    {
        kText,
        kHTML,
        kJSON
	};
	//virtual DataAs(std::string data, Format format) const = 0;
    virtual ~Printable() = default;
    
    
	std::string data_;
    Format format_;
	
};

class DataAsText : public Printable
{
public:
    DataAsText(std::string data) {
		
		data_ = data;
		format_ = Format::kText;
		
	}
	std::string print() const override{
		return data_;
		
	}
	~DataAsText(){}
};

class DataAsHTML : public Printable
{
public:
    DataAsHTML(std::string data) {
		data_ = data;
		format_ = Format::kHTML;
		
	}
	std::string print() const override{
		return "<html>" + data_ + "<html/>";
		
	}
	~DataAsHTML(){}
};


class DataAsJSON : public Printable
{
public:
    DataAsJSON(std::string data) {
		data_ = data;
		format_ = Format::kJSON;
		
	}
	std::string print() const override{
		return "{ \"data\": \"" + data_ + "\"}";
		
	}
	~DataAsJSON(){}
	
};

	
void saveTo(std::ofstream &file, const Printable* printable){
	
	file << printable -> print();
}






/*
class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};

void saveTo(std::ofstream &file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream &file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}
*/