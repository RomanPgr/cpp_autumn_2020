#include "allocator.h"
#include <iostream>

int main(){
    Allocator alc;
    char *chr0 = alc.alloc(100);    
    std::cout << (chr0 != nullptr) << "\n";
    alc.makeAllocator(1000);
    
    char *chr1 = alc.alloc(200);
    std::cout << (chr1 != nullptr) << "\n";
    chr1[150] = (char) 'a';
    
    char *chr2 = alc.alloc(700);
    std::cout << (chr2 != nullptr) << "\n";
    
    chr2[150] = (char) 'b';
    
    std::cout << chr1[150] << "\n";
    std::cout << chr2[150] << "\n";
    
    Allocator alc2;
    alc2.makeAllocator(37000);
    
    char *chr3 = alc2.alloc(200);
    std::cout << (chr3 != nullptr) << "\n";
    
    chr3[50] = (char) 'c';

    char *chr4 = alc2.alloc(101);
    std::cout << (chr4 != nullptr) << "\n";
    
    chr4[50] = (char) 'd';
    
    std::cout << chr3[50] << "\n";
    std::cout << chr4[50] << "\n";
    
    char *chr5 = alc2.alloc(100);
    std::cout << (chr5 != nullptr) << "\n";
    
    char *chr6 = alc2.alloc(1);
    std::cout << (chr6 != nullptr) << "\n";
    
    char *chr60 = alc2.alloc(10000000);
    std::cout << (chr60 != nullptr) << "\n";
    
    alc.reset();
    
    char *chr7 = alc.alloc(200);
    std::cout << (chr7 != nullptr) << "\n";
    
    char *chr8 = alc.alloc(1001);
    std::cout << (chr8 != nullptr) << "\n";
    
    return 0;
}
