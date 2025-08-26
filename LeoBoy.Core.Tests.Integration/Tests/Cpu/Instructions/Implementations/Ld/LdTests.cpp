#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"LD A, d8\" should load the byte in the next address into register A", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint8_t testOpcode = Cpu::Instructions::Opcodes::LD_A_d8;
	uint8_t testValue = 0xAF;
	uint16_t testPc = cpu.GetPc();

	memory.Write(testPc, testOpcode);
	memory.Write(testPc + 1, testValue);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetA() == testValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"LD A, HL\" should load the byte in the address stored by HL into register A", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint8_t testOpcode = Cpu::Instructions::Opcodes::LD_A_HL;
	uint8_t testValue = 0x33;
	uint16_t testAddress = 0x2000;
	uint16_t testPc = cpu.GetPc();

	memory.Write(testPc, testOpcode);
	memory.Write(testAddress, testValue);
	cpu.SetHL(testAddress);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetA() == testValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"LD HL, A\" should load the byte stored in register A into the address specified by HL", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint8_t testOpcode = Cpu::Instructions::Opcodes::LD_HL_A;
	uint8_t testValue = 0x8E;
	uint16_t testAddress = 0x1234;
	uint16_t testPc = cpu.GetPc();

	memory.Write(testPc, testOpcode);
	cpu.SetA(testValue);
	cpu.SetHL(testAddress);

	// Act
	cpu.Step();	

	// Assert
	uint16_t result = memory.Read(cpu.GetHL());
	REQUIRE(result == testValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"LD HL, d16\" should update HL with a new memory address", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = cpu.GetPc();
	uint8_t firstImmediateValue = 0x12;
	uint8_t secondImmediateValue = 0x34;
	uint16_t expectedAddress = 0x3412;

	memory.Write(testPc, Cpu::Instructions::Opcodes::LD_HL_d16);
	memory.Write(testPc + 1, firstImmediateValue);
	memory.Write(testPc + 2, secondImmediateValue);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetHL() == expectedAddress);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Example program with multiple instructions", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint16_t initialPc = cpu.GetPc();
	uint16_t expectedPc = initialPc + 7;
	uint16_t testAddress = 0xC000;
	uint8_t testValue = 0x42;

	// HL = C000
	memory.Write(initialPc, Cpu::Instructions::Opcodes::LD_HL_d16);
	memory.Write(initialPc + 1, testAddress & 0xFF);
	memory.Write(initialPc + 2, testAddress >> 8);

	// A = 42
	memory.Write(initialPc + 3, Cpu::Instructions::Opcodes::LD_A_d8);
	memory.Write(initialPc + 4, testValue);

	// (HL) = A
	memory.Write(initialPc + 5, Cpu::Instructions::Opcodes::LD_HL_A);

	// A = (HL)
	memory.Write(initialPc + 6, Cpu::Instructions::Opcodes::LD_A_HL);

	// Act
	for (int i = 0; i < 4; i++)
	{
		cpu.Step();
	}

	// Assert
	REQUIRE(cpu.GetPc() == expectedPc);
	REQUIRE(cpu.GetHL() == testAddress);
	REQUIRE(memory.Read(testAddress) == testValue);
	REQUIRE(cpu.GetA() == testValue);
}