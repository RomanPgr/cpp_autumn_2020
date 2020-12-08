#include <iostream>
#include <string>
#include "format.h"

int main(void)
{
    int a = 4;
    int b = 6;
    double d = 2.3;
    std::string str = "jknfjgy";
    try{
        std::cout << format("qwertyui") << std::endl;
        std::cout << format("\\{}") << std::endl;
        std::cout << format("}") << std::endl;
        std::cout << format("\\{") << std::endl;
        std::cout << format("ab{3}cd{1}ef{2}jh{4}{2}{0}{3}", a, b, str, 1.2, d) << std::endl;
        std::cout << format("sdbhtrdt") << std::endl;
        std::cout << format("") << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}
