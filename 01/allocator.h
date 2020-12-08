#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

class Allocator{
public:
    Allocator() noexcept;
    Allocator(size_t maxSize);
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size) noexcept;
    void reset() noexcept;
    ~Allocator();

private:
    size_t free_size;
    size_t cur_size;
    char* beg_mem;
};

#endif
