#include <new>
#include "allocator.h"

Allocator::Allocator(){
    free_size = 0;
    cur_size = 0;
    beg_mem = nullptr;
}

Allocator::Allocator(size_t maxSize){
    try{
        beg_mem = new char[maxSize];
    }
    catch (const std::bad_alloc&){
        beg_mem = nullptr;
    }
    cur_size = 0;
    free_size = (beg_mem != nullptr) ? maxSize : 0;
}

void Allocator::makeAllocator(size_t maxSize){
    delete[] beg_mem;
    try{
        beg_mem = new char[maxSize];
    }
    catch (const std::bad_alloc&){
        beg_mem = nullptr;
    }
    cur_size = 0;
    free_size = (beg_mem != nullptr) ? maxSize : 0;
}

char* Allocator::alloc(size_t size){
    if (size == 0){
        return nullptr;
    }
    if (size <= free_size){
        cur_size += size;
        free_size -= size;
        return (beg_mem + cur_size - size);
    }
    else{
        return nullptr;
    }
}

void Allocator::reset(){
    free_size += cur_size;
    cur_size = 0;
}

Allocator::~Allocator(){
    delete[] beg_mem;
}
