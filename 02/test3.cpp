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
    const unsigned int len = 100;
    Parser p[len];
    p[0].SetCallbackToken(Tokens::NUMBER, num_f);
    p[0].SetCallbackToken(Tokens::END, end_f);
    p[0].SetCallbackToken(Tokens::BEGIN, beg_f);
    p[0].SetCallbackToken(Tokens::STRING, str_f);
    
    for (unsigned int i = 1; i < len; i++){
        p[i].SetCallbackToken(p[0]);
        p[i].SetText(std::to_string(i) + " " + (char)(i) + " " + "8h");
    }

    
    for (unsigned int i = 0; i < len; i++){
        p[i].init();
        do{
            p[i].next();
        } while (p[i].GetCurrentTypeToken() != Tokens::END);
        p[i].finish();
    }
}
