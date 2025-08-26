#include "CpuTestsFixture.h"
#include "../../LeoBoy.Core/src/Cpu/Instructions/Opcodes.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Fetch reads memory and increases program counter", "[integration], [cpu]")
{
	// Arrange
	uint8_t firstExpectedValue = 0x74;
	uint8_t secondExpectedValue = 0x12;
	uint16_t initialPc = cpu.GetPc();

	memory.Write(initialPc, firstExpectedValue);
	memory.Write(initialPc + 1, secondExpectedValue);

	// Act
	uint8_t firstResult = cpu.Fetch();
	uint8_t secondResult = cpu.Fetch();

	// Assert
	REQUIRE(firstResult == firstExpectedValue);
	REQUIRE(secondResult == secondExpectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Step should fetch, decode and execute an instruction", "[integration], [cpu]")
{
	// Arrange
	uint8_t testOpcode = Cpu::Instructions::Opcodes::NOP;
	uint16_t initialPc = cpu.GetPc();

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetPc() == initialPc + 1);
}