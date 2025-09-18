#include "CpuTestsFixture.h"
#include "../../LeoBoy.Core/src/Cpu/Instructions/Opcodes.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Fetch reads memory and increases program counter", "[cpu]")
{
	// Arrange
	uint8_t firstExpectedValue = 0x74;
	uint8_t secondExpectedValue = 0x12;

	fakeit::When(Method(mockMemory, Read).Using(Cpu::CpuImpl::InitialPc))
		.Return(firstExpectedValue);

	fakeit::When(Method(mockMemory, Read).Using(Cpu::CpuImpl::InitialPc + 1))
		.Return(secondExpectedValue);

	// Act
	uint8_t firstResult = cpu.Fetch();
	uint8_t secondResult = cpu.Fetch();

	// Assert
	REQUIRE(firstResult == firstExpectedValue);
	REQUIRE(secondResult == secondExpectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Step should fetch, decode and execute an instruction", "[cpu]")
{
	// Arrange
	uint8_t testOpcode = 0xFF;
	bool instructionExecuted = false;

	fakeit::When(Method(mockMemory, Read).Using(Cpu::CpuImpl::InitialPc))
		.Return(testOpcode);

	fakeit::When(Method(mockInstructionLookUp, Get).Using(testOpcode))
		.Return([&instructionExecuted](Cpu::Instructions::SystemReferences& systems)
			{
				instructionExecuted = true;
			});

	// Act
	cpu.Step();

	// Assert
	REQUIRE(instructionExecuted == true);
}