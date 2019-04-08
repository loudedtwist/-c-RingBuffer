#pragma once

#include <vector>

template <typename Type, unsigned N>
class RingBuffer {
public:

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
        friend bool operator==(const iterator& lhs, const iterator& rhs)
        {return lhs.parent==rhs.parent && lhs.index==rhs.index;}
        friend bool operator!=(const iterator& lhs, const iterator& rhs)
        {return lhs.parent!=rhs.parent || lhs.index!=rhs.index;}
    private:
        friend RingBuffer;
        explicit iterator(RingBuffer* container, int i=-1) :parent(container), index(i) {}
        RingBuffer* parent;
        int index;
    };
    iterator begin() {return iterator(this, 0);}
    iterator end() {return iterator(this, N);}

public:
    RingBuffer() {
        _buffer.reserve(N);
    }

    unsigned CurrentSize() const {
        if (IsEmpty()) {
            return 0;
        }

        if (HasOneElement()) {
            return 1;
        }

        if (_head > _tail) {
            return (unsigned int)(_head - _tail + 1);
        }

        if (_head < _tail) {
            return N - _tail + _head + 1;
        }

        throw std::logic_error("Not expected result");
    }

    bool HasOneElement() const {
        return _head == _tail;
    }

    bool IsEmpty() const {
        return _head == -1 || _tail == -1;
    }

    unsigned int Capacity() {
        return N;
    }

    void PushBack(const Type& val) {
        _head = Increment(_head);

        if (_head == _tail) {
            _tail = Increment(_tail);
        }

        if (_head == 0) {
            _tail = _head;
        }

        _buffer[_head] = val;
    }

    unsigned int Increment(int value) const {
        return (value + 1) % (N - 1);
    }

    const Type& Back() const {
        AssertNotEmpty();
        return _buffer[_tail];
    }

    const Type& Front() const {
        AssertNotEmpty();
        return _buffer[_tail];
    }

    Type& PopBack() {
        AssertNotEmpty();

        auto returnTail = _tail;

        if (HasOneElement()) _tail = _head = -1;
        else                 _tail = Increment(_tail);

        return _buffer[returnTail];
    }

    void AssertNotEmpty() const {
        if (IsEmpty()) throw std::logic_error("Ring Buffer is empty. Can not pop");
    };

private:
    std::vector<Type> _buffer;
    int _head{-1};
    int _tail{-1};
};