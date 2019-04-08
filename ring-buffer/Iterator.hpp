#pragma once

#include <iterator>
#include <vector>
#include <Iterator.hpp>
#include "IRingBuffer.hpp"

template <typename Type>
struct iterator {
    typedef Type value_type;
    typedef Type& reference_type;
    typedef Type* pointer_type;
    typedef int difference_type;
    typedef std::output_iterator_tag iterator_category;

    iterator& operator++() {++index; return *this;}
    iterator operator++(int) {return iterator(parent, index++);}
    reference_type operator*() const {
        return parent->_buffer[index];
    }
    friend void swap(iterator& lhs, iterator& rhs) {
        std::swap(lhs.parent, rhs.parent);
        std::swap(lhs.index, rhs.index);
    }
    friend bool operator==(const iterator& lhs, const iterator& rhs) {
        return lhs.parent==rhs.parent && lhs.index==rhs.index;}
    friend bool operator!=(const iterator& lhs, const iterator& rhs)
    {return lhs.parent!=rhs.parent || lhs.index!=rhs.index;}

public:
    explicit iterator(IRingBuffer<Type>* container, int i=-1) : parent(container), index(i) {}
    IRingBuffer<Type>* parent;
    int index;
};