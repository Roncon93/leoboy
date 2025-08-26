#include "CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Program Counter is initialized to 0x0100", "[cpu]")
{
	// Act
	uint16_t pc = cpu.GetPc();

	// Assert
	REQUIRE(pc == Cpu::CpuImpl::InitialPc);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Program Counter can be incremented", "[cpu]")
{
	// Arrange
	uint16_t initialPc = cpu.GetPc();

	// Act
	cpu.IncrementPc();
	uint16_t incrementedPc = cpu.GetPc();

	// Assert
	REQUIRE(incrementedPc == initialPc + 1);
}