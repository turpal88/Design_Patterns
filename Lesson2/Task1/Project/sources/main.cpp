
#ifdef _WIN32
#include <windows.h>
#endif


#include <decorator.h>

int main(){
#ifdef _WIN32	
SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0002);
#endif 
	
auto text_block = new ItalicText(new BoldText(new Text()));
text_block->render("Hello world");

std::cout << std::endl;

auto text_block1 = new Paragraph(new Text());
text_block1->render("Hello world");

std::cout << std::endl;

auto text_block2 = new Reversed(new Text());
text_block2->render("Hello world");

std::cout << std::endl;

auto text_block3 = new Link(new Text());
text_block3->render("netology.ru", "Hello world");

std::cout << std::endl;

#ifdef _WIN32
system("pause");
#endif


return 0;
}