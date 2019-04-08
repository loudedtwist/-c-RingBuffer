#pragma once

#include <vector>

template <typename Type>
class IRingBuffer {

public:
    virtual unsigned CurrentSize() const;

    virtual bool IsEmpty() const;

    virtual unsigned int Capacity();

    virtual void PushBack(const Type& val);

    virtual unsigned int Increment(int value) const;

    virtual const Type& Back() const;

    virtual const Type& Front() const;

    virtual Type& PopBack();

public:
    std::vector<Type> _buffer;
    int a;
};