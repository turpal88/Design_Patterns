

#include <export.h>

#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void API_DECORATOR render(const std::string& data) const;
};

class DecoratedText : public Text {
public:
    API_DECORATOR DecoratedText(Text* text);
    API_DECORATOR Text* text_;
};

class ItalicText : public DecoratedText {
public:
    API_DECORATOR ItalicText(Text* text);
    void API_DECORATOR render(const std::string& data) const;
};

class BoldText : public DecoratedText {
public:
    API_DECORATOR BoldText(Text* text);
    void API_DECORATOR render(const std::string& data) const;
};

class Paragraph : public DecoratedText{
public:
API_DECORATOR Paragraph(Text* text);
void API_DECORATOR render(const std::string& data) const;
	
};


class Reversed : public DecoratedText{
public:
API_DECORATOR Reversed(Text* text);
void API_DECORATOR render(std::string&& data);
	
};

class Link : public DecoratedText {
public:
API_DECORATOR Link(Text* text);
void API_DECORATOR render(const std::string& data1, const std::string& data2) const;
	
};
