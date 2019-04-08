#define CATCH_CONFIG_MAIN
#include "../Catch2/single_include/catch2/catch.hpp"
#include <RingBuffer.hpp>
//#include <catch2/catch.hpp>

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Ring buffer init", "[ring-buffer]" ) {
RingBuffer<int, 6> intRingBuffer;
REQUIRE(intRingBuffer.CurrentSize() == 0);
REQUIRE(intRingBuffer.Capacity() == 6);

    SECTION( "push one element" ) {
        intRingBuffer.PushBack(11);
        REQUIRE(intRingBuffer.CurrentSize() == 1);
        REQUIRE(intRingBuffer.Capacity() == 6);
    }

    SECTION( "push two element" ) {
        intRingBuffer.PushBack(11);
        REQUIRE(intRingBuffer.CurrentSize() == 1);
        intRingBuffer.PushBack(12);
        intRingBuffer.PushBack(13);
        intRingBuffer.PushBack(14);
        intRingBuffer.PushBack(15);
        intRingBuffer.PushBack(16);
        intRingBuffer.PushBack(17);
        intRingBuffer.PushBack(18); 

        for (const auto &item : intRingBuffer) {
            std::cout << item << std::endl;
        }

        REQUIRE(intRingBuffer.PopBack() == 11);
        REQUIRE(intRingBuffer.CurrentSize() == 1);
        REQUIRE(intRingBuffer.PopBack() == 12);
        REQUIRE(intRingBuffer.CurrentSize() == 0);
    }
}


TEST_CASE( "Factorials are computed", "[factorial]" ) {
REQUIRE( Factorial(1) == 1 );
REQUIRE( Factorial(2) == 2 );
REQUIRE( Factorial(3) == 6 );
REQUIRE( Factorial(10) == 3628800 );
}
