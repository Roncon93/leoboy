#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "../LeoBoy.Core/src/IMemory.h"
#include "../LeoBoy.Core/src/Cpu.h"

class MockMemory : public IMemory
{
    uint8_t Read(uint16_t address) const override
    {
        return 0;
    }
    void Write(uint16_t address, uint8_t value) override
    {
    }
};

TEST_CASE("CPU register A can be set and read", "[cpu]") {
	MockMemory memory;
    Cpu cpu(memory);
    cpu.SetA(0x42);
    REQUIRE(cpu.GetA() == 0x42);
}

TEST_CASE("CPU registers B and C combined work correctly", "[cpu]") {
    MockMemory memory;
    Cpu cpu(memory);
    cpu.SetB(0x12);
    cpu.SetC(0x34);
    REQUIRE(cpu.GetBC() == 0x1234);
}