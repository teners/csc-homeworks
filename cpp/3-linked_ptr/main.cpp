#include "linked_ptr.hpp"

struct C;

int main()
{
    // Should compile. Completeness of C is not needed.
    smart_ptr::linked_ptr<C> p1;
    smart_ptr::linked_ptr<C> p2(p1);

    // Shouldn't compile:
    //smart_ptr::linked_ptr<C> p3(reinterpret_cast<C *>(123));
    //p1.reset(reinterpret_cast<C *>(123));
}