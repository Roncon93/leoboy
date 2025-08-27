#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../../Libraries/fakeit.hpp"
#include "../../InstructionTestsFixture.h"
#include "../../../../../../LeoBoy.Core/src/Cpu/Instructions/Implementations/Ld/Ld.h"

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute \"LD A, d8\" should load the byte in the next address into register A", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = 0x1234;
	uint8_t immediateValue = 0x42;

	fakeit::When(Method(mockCpu, IncrementPc))
		.Return(testPc);
	fakeit::When(Method(mockMemory, Read).Using(testPc))
		.Return(immediateValue);
	fakeit::Fake(Method(mockCpu, SetA));

	// Act
	Cpu::Instructions::Implementations::Ld::Ld_A_d8(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::LD_A_d8);
	fakeit::Verify(Method(mockCpu, SetA).Using(immediateValue)).Once();
}

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute \"LD HL, d16\" should update HL with a new memory address", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = 0x9876;
	uint8_t firstImmediateValue = 0x12;
	uint8_t secondImmediateValue = 0x34;
	uint16_t expectedAddress = 0x3412;

	fakeit::When(Method(mockCpu, IncrementPc))
		.Return(testPc, testPc + 1);
	fakeit::When(Method(mockMemory, Read).Using(testPc))
		.Return(firstImmediateValue);
	fakeit::When(Method(mockMemory, Read).Using(testPc + 1))
		.Return(secondImmediateValue);
	fakeit::Fake(Method(mockCpu, SetHL));

	// Act
	Cpu::Instructions::Implementations::Ld::Ld_HL_d16(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::LD_HL_d16);
	fakeit::Verify(Method(mockCpu, SetHL).Using(expectedAddress)).Once();
}