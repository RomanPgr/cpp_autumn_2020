#include <iostream>
#include <string>
#include "format.h"

int main(void)
{
    int a = 4;
    const int k = 8;
    double d = 2.3;
    std::string str = "jknfjgy";
    float f = 0.4f;
    bool b = true;
    try{
        std::cout << "1 " << format("{", b) << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
        
    try{
        std::cout << "2 " << format("{}", f) << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
        
    try{
        std::cout << "3 " << format("{0a}", str) << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try{
        std::cout << "4 " << format("{0}") << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try{
        std::cout << "5 " << format("ab{11}cd{1}ef{2}jh{4}{2}{0}{5}{3}{6}", a, b, str, k, 1.2, d, b, b, b, b, b) << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try{
        std::cout << "6 " << format("sdbhtrdt {1000000}", str) << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try{
        std::cout << "7 " << format("{1}{1}{1}{1+1}", 7, "qwerty") << std::endl;
    }
    catch(const exception_parantheses& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const out_of_range_param& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
