#include <string>

enum Tokens{
    BEGIN,
    NUMBER,
    STRING,
    END
};

class Parser{
public:
    void* init();
    void* next();
    void* finish();

    void Reset();
    void Remake();
    void SetText(const std::string& new_text);
    void SetCallbackToken(const Parser& example);
    void SetCallbackToken(
         Tokens t, void* (*func)(Tokens type_token, std::string cur_lex));

    Tokens GetCurrentTypeToken();
    std::string GetCurrentToken();
    
    Parser(std::string text = "");
    ~Parser();

private:
    std::string text;
    std::string current_lex;
    Tokens current_lex_type;
    unsigned int current_position;
    void* (*CallbackTokenHandler[Tokens::END + 1])(Tokens type_token, 
          std::string cur_lex);
};
