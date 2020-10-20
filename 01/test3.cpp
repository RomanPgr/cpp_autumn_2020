#include "allocator.h"
#include <iostream>
#include <cstring>

int main(){
    Allocator alc;
    alc.makeAllocator(1000000000000);
    
    char *chr1 = alc.alloc(200);
    std::cout << (chr1 != nullptr) << "\n";
    
    alc.makeAllocator(10000000);
    
    char *chr2 = alc.alloc(700);
    strcpy(chr2 + 100, "abcqwerty");
    std::cout << (chr2 != nullptr) << "\n";
    
    alc.reset();
    char *chr3 = alc.alloc(200);
    std::cout << (chr3 + 100) << "\n";
    std::cout << (chr3 != nullptr) << "\n";

    char *chr4 = alc.alloc(1318);
    std::cout << (chr4 != nullptr) << "\n";
    
    char *chr5 = alc.alloc(186);
    std::cout << (chr5 != nullptr) << "\n";
    
    char *chr6 = alc.alloc(0);
    std::cout << (chr6 != nullptr) << "\n";
    
    alc.reset();
    
    return 0;
}
