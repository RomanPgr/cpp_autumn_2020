#ifndef ALLOCATOR
#define ALLOCATOR
#include <cstddef>

class Allocator{
public:
    Allocator();
    Allocator(size_t maxSize);
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();

private:
    size_t free_size;
    size_t cur_size;
    char* beg_mem;
};
#endif
