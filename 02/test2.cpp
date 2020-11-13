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
    Parser p("123# 763@Ffg ethtg TCGD5 RT5 765 thd5 9051@!\nhs \n 7 #@##@3 85 754444444444444444444444444444444444 8888888 $%^^ '777 r 35 98 98 aq 32 '");
    p.SetCallbackToken(Tokens::NUMBER, num_f);
    p.SetCallbackToken(Tokens::END, end_f);
    p.SetCallbackToken(Tokens::BEGIN, beg_f);
    p.SetCallbackToken(Tokens::STRING, str_f);
    p.init();
    
    do{
        p.next();
    } while (p.GetCurrentTypeToken() != Tokens::END);
    std::cout << std::endl;
    
    p.Reset();
    p.SetCallbackToken(Tokens::NUMBER, num_f);
    p.SetCallbackToken(Tokens::END, end_f);
    p.SetCallbackToken(Tokens::BEGIN, beg_f);
    p.SetCallbackToken(Tokens::STRING, str_f);
    p.init();
    
        do{
        p.next();
    } while (p.GetCurrentTypeToken() != Tokens::END);
    p.finish();
    std::cout << std::endl;
    
    p.SetText("");  
    do{
        p.next();
    } while (p.GetCurrentTypeToken() != Tokens::END);
    std::cout << std::endl;
    
    Parser pars2;
    pars2.SetCallbackToken(p);
    pars2.SetText("0 1 -1 23 hdcgeyhty tyrfugj rt4367 78874 ytr6 537 ; ) oy");
    
    do{
        pars2.next();
    } while (pars2.GetCurrentTypeToken() != Tokens::END);
    std::cout << std::endl;
    
    pars2.Remake();
    
    do{
        pars2.next();
    } while (pars2.GetCurrentTypeToken() != Tokens::END);
}
