#include "parser.h"

enum state_machine{
    H,
    H_NUMBER,
    H_STRING,
    H_OK
};

void GetNextTokenMachine(std::string& token, Tokens& t, 
    const std::string& str, unsigned int& position){

    token = "";
    state_machine state = H;
    unsigned int len = str.length();
    char c;
    while (state != H_OK){
        if (position == len){
            if (state == H){
                t = END;
                return;
            }
            else{
                state = H_OK;
            }
        }
        else {
            c = str[position];
        }
        switch (state) {
        case H:
            if (std::isspace(c)){
                t = END;
            }
            else if (std::isdigit(c)) {
                state = H_NUMBER;
                t = NUMBER;
                token += c;
            }
            else{
                state = H_STRING;
                t = STRING;
                token += c;
            }
            break;

        case H_NUMBER:
            if (std::isspace(c)){
                t = NUMBER;
                state = H_OK;
            }
            else if (std::isdigit(c)) {
                token += c;
            }
            else{
                state = H_STRING;
                t = STRING;
                token += c;
            }
            break;

        case H_STRING:
            if (std::isspace(c)){
                t = STRING;
                state = H_OK;
            }
            else{
                token += c;
            }
            break;


        case H_OK:
            return;
        }
        ++position;
    }
}

void* Parser::init(){
    if (current_position == 0 && CallbackTokenHandler[0] != nullptr){
        return (*CallbackTokenHandler[0])(Tokens::BEGIN, "");
    }
    return nullptr;
}

void* Parser::next(){
    GetNextTokenMachine(current_lex, current_lex_type, text, current_position);
    if (CallbackTokenHandler[current_lex_type] != nullptr){
        return (*CallbackTokenHandler[current_lex_type])
            (current_lex_type, current_lex);
    }
    return nullptr;
}

void* Parser::finish(){
    current_position = text.length();
    if (CallbackTokenHandler[Tokens::END] != nullptr){
        return (*CallbackTokenHandler[Tokens::END])(Tokens::END, "");
    }
    return nullptr;
}

void Parser::Reset(){
    text = "";
    current_position = 0;
    current_lex_type = Tokens::BEGIN;
    current_lex = "";
    for (unsigned int i = 0; i <= Tokens::END; i++){
        CallbackTokenHandler[i] = nullptr;
    }
}

void Parser::Remake(){
    current_position = 0;
    current_lex_type = Tokens::BEGIN;
    current_lex = "";
}

void Parser::SetText(const std::string& new_text){
    text = new_text;
    current_position = 0;
    current_lex_type = Tokens::BEGIN;
    current_lex = "";
}

void Parser::SetCallbackToken(const Parser& example){
    for (unsigned int i = 0; i < Tokens::END; i++){
        CallbackTokenHandler[i] = example.CallbackTokenHandler[i];
    }
}

void Parser::SetCallbackToken(
     Tokens t, void* (*func)(Tokens type_token, std::string cur_lex)){
    CallbackTokenHandler[t] = func;
}

Tokens Parser::GetCurrentTypeToken(){
    return current_lex_type;
}

std::string Parser::GetCurrentToken(){
    return current_lex;
}

Parser::Parser(std::string text):
    text(text),
    current_lex(""),
    current_lex_type(Tokens::BEGIN),
    current_position(0){
    for (unsigned int i = 0; i <= Tokens::END; i++){
        CallbackTokenHandler[i] = nullptr;
    }
}

Parser::~Parser(){}
