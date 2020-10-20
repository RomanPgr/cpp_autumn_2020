#include "allocator.h"
#include <iostream>

int main(){
    Allocator alc;
    alc.makeAllocator(1000);
    
    char *chr1 = alc.alloc(200);
    std::cout << (chr1 != nullptr) << "\n";
    
    char *chr2 = alc.alloc(700);
    std::cout << (chr2 != nullptr) << "\n";
    
    char *chr3 = alc.alloc(200);
    std::cout << (chr3 != nullptr) << "\n";

    char *chr4 = alc.alloc(101);
    std::cout << (chr4 != nullptr) << "\n";
    
    char *chr5 = alc.alloc(100);
    std::cout << (chr5 != nullptr) << "\n";
    
    char *chr6 = alc.alloc(1);
    std::cout << (chr6 != nullptr) << "\n";
    
    alc.reset();
    
    char *chr7 = alc.alloc(200);
    std::cout << (chr7 != nullptr) << "\n";
    
    char *chr8 = alc.alloc(1001);
    std::cout << (chr8 != nullptr) << "\n";
    
    return 0;
}
