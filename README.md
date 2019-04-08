# cpp-RingBuffer

# Usage 

RingBuffer<int, 6> intRingBuffer;
        intRingBuffer.Push(12);
        intRingBuffer.Push(13);
        intRingBuffer.Push(14);
        intRingBuffer.Push(15);
        intRingBuffer.Push(16);
        intRingBuffer.Push(17);
        intRingBuffer.Push(18);
        
        

        REQUIRE(intRingBuffer.PopFront() == 18);
        REQUIRE(intRingBuffer.PopFront() == 17);
        REQUIRE(intRingBuffer.PopFront() == 16);
        REQUIRE(intRingBuffer.PopFront() == 15);
        REQUIRE(intRingBuffer.PopFront() == 14);
        REQUIRE(intRingBuffer.PopFront() == 13);
