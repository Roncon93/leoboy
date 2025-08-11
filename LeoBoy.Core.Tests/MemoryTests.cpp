#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memory.h"
#include "../LeoBoy.Core/src/Memory.h"

TEST_CASE("Memory basic read/write")
{
    Memory memory;

    SUBCASE("Default memory values are zero")
    {
        CHECK(memory.Read(0x0000) == 0x00);
        CHECK(memory.Read(0xFFFF) == 0x00);
    }

    SUBCASE("Writing then reading a value works")
    {
        memory.Write(0x1234, 0xAB);
        CHECK(memory.Read(0x1234) == 0xAB);
    }
}
