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