#pragma once
#include <decorator.h>




void Text::render(const std::string& data) const {
        std::cout << data;
    }




DecoratedText::DecoratedText(Text* text) : text_(text) {}
    



ItalicText::ItalicText(Text* text) : DecoratedText(text) {}
void ItalicText::render(const std::string& data) const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }



BoldText::BoldText(Text* text) : DecoratedText(text) {}
    void BoldText::render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }


Paragraph::Paragraph(Text* text) : DecoratedText(text) {}
void Paragraph::render(const std::string& data) const{
	std::cout << "<p>";
	text_->render(data);
	std::cout << "</p>";
	
}

Reversed::Reversed(Text* text) : DecoratedText(text){}
void Reversed::render(std::string&& data) {
	std::reverse(data.begin(), data.end());
	//text_ -> render(data);
	std::cout << data;
	
}

Link::Link(Text* text) : DecoratedText(text) {}

void Link::render(const std::string& data1, const std::string& data2) const {
	std::cout << "<a href=" + data1 + ">";
	text_ -> render(data2);
	std::cout << "</a>";
	
}





