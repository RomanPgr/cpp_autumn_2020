#include <iostream>
#include <string>
#include "format.h"

int main(void)
{
    int a = 4;
    double d = 2.3;
    std::string str = "jknfjgy";
    float f = 0.4f;
    bool b = true;
    try{
        std::cout << format("qwertyui{0}", b) << std::endl;
        std::cout << format("\\{}{0}", f) << std::endl;
        std::cout << format("}{0}", str) << std::endl;
        std::cout << format("\\{") << std::endl;
        std::cout << format("ab{3}cd{1}ef{2}jh{4}{2}{0}{3}", a, b, str, 1.2, d, b, b, b, b, b) << std::endl;
        std::cout << format("sdbhtrdt{0}", str) << std::endl;
        std::cout << format("{1}{1}{1}", 7, "qwerty") << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}
