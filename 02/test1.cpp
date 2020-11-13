#include <string>
#include <iostream>
#include <cctype>
#include "parser.h"

void* num_f(Tokens type_token, std::string s){
    std::cout << "Type " << type_token << "\tNUMBER:\t" << s << std::endl;
    return nullptr;
}

void* end_f(Tokens type_token, [[maybe_unused]] std::string s){
    std::cout << "Type " << type_token << "\tEND" << std::endl;
    return nullptr;
}

void* beg_f(Tokens type_token, [[maybe_unused]] std::string s){
    std::cout << "Type " << type_token << "\tBEGIN" << std::endl;
    return nullptr;
}

void* str_f(Tokens type_token, std::string s){
    std::cout << "Type " << type_token << "\tSTRING:\t" << s << std::endl;
    return nullptr;
}

int main(){
    Parser p("123 jt 7676f 87 8 4 2 asd 1234");
    p.SetCallbackToken(Tokens::NUMBER, num_f);
    p.SetCallbackToken(Tokens::END, end_f);
    p.SetCallbackToken(Tokens::BEGIN, beg_f);
    p.SetCallbackToken(Tokens::STRING, str_f);

    p.init();
    
    do{
        p.next();
    } while (p.GetCurrentTypeToken() != Tokens::END);
}
