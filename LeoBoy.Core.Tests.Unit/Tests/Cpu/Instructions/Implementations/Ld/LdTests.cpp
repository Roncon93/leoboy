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

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute \"LD A, a16\" should load value stored in the immediate address into register A", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = 0x1234;
	uint16_t testAddress = 0x5678;
	uint8_t firstImmediateValue = 0x78;
	uint8_t secondImmediateValue = 0x56;
	uint8_t expectedValue = 0x9A;

	fakeit::When(Method(mockCpu, IncrementPc))
		.Return(testPc, testPc + 1);
	fakeit::When(Method(mockMemory, Read).Using(testPc))
		.Return(firstImmediateValue);
	fakeit::When(Method(mockMemory, Read).Using(testPc + 1))
		.Return(secondImmediateValue);
	fakeit::When(Method(mockMemory, Read).Using(testAddress))
		.Return(expectedValue);
	fakeit::Fake(Method(mockCpu, SetA));

	// Act
	Cpu::Instructions::Implementations::Ld::Ld_A_a16(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::LD_A_a16);
	fakeit::Verify(Method(mockCpu, SetA).Using(expectedValue)).Once();
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

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute \"LD a16, A\" should write the value in register A to a specified address", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = 0x2000;
	uint8_t addressLowByte = 0x78;
	uint8_t addressHighByte = 0x56;
	uint16_t targetAddress = 0x5678;
	uint8_t registerAValue = 0x9A;

	fakeit::When(Method(mockCpu, IncrementPc))
		.Return(testPc, testPc + 1);
	fakeit::When(Method(mockMemory, Read).Using(testPc))
		.Return(addressLowByte);
	fakeit::When(Method(mockMemory, Read).Using(testPc + 1))
		.Return(addressHighByte);
	fakeit::When(Method(mockCpu, GetA))
		.Return(registerAValue);
	fakeit::Fake(Method(mockMemory, Write));

	// Act
	Cpu::Instructions::Implementations::Ld::Ld_a16_A(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::LD_a16_A);
	fakeit::Verify(Method(mockMemory, Write).Using(targetAddress, registerAValue)).Once();
}