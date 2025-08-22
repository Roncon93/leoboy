#include "CpuTestsFixture.h"
#include "../../LeoBoy.Core/src/Opcodes.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Fetch reads memory and increases program counter", "[cpu]")
{
	// Arrange
	uint8_t firstExpectedValue = 0x74;
	uint8_t secondExpectedValue = 0x12;

	fakeit::When(Method(mockMemory, Read).Using(Cpu::InitialPc))
		.Return(firstExpectedValue);

	fakeit::When(Method(mockMemory, Read).Using(Cpu::InitialPc + 1))
		.Return(secondExpectedValue);

	// Act
	uint8_t firstResult = cpu.Fetch();
	uint8_t secondResult = cpu.Fetch();

	// Assert
	REQUIRE(firstResult == firstExpectedValue);
	REQUIRE(secondResult == secondExpectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute NOP opcode does nothing", "[cpu]")
{
	// Arrange
	uint8_t nopOpcode = Opcodes::NOP;

	// Act
	cpu.Execute(nopOpcode);

	// Assert
	REQUIRE(cpu.GetAF() == 0x0000);
	REQUIRE(cpu.GetBC() == 0x0000);
	REQUIRE(cpu.GetDE() == 0x0000);
	REQUIRE(cpu.GetHL() == 0x0000);
	REQUIRE(cpu.GetA() == 0x00);
	REQUIRE(cpu.GetB() == 0x00);
	REQUIRE(cpu.GetC() == 0x00);
	REQUIRE(cpu.GetD() == 0x00);
	REQUIRE(cpu.GetE() == 0x00);
	REQUIRE(cpu.GetH() == 0x00);
	REQUIRE(cpu.GetL() == 0x00);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute with invalid opcode should throw error", "[cpu]")
{
	// Arrange
	uint8_t invalidOpcode = 0xFF;

	// Act
	cpu.Execute(invalidOpcode);

	// Assert
	fakeit::Verify(Method(mockLogger, Log)).Exactly(fakeit::Once);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Step should fetch, decode and execute an instruction", "[cpu]")
{
	// Arrange
	uint8_t invalidOpcode = 0xFF;

	fakeit::When(Method(mockMemory, Read).Using(Cpu::InitialPc))
		.Return(invalidOpcode);

	// Act
	cpu.Step();

	// Assert
	fakeit::Verify(Method(mockLogger, Log)).Exactly(fakeit::Once);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"LD A, d8\" should load the byte in the next address into register A", "[cpu]")
{
	// Arrange
	uint8_t immediateValue = 0x42;

	fakeit::When(Method(mockMemory, Read).Using(Cpu::InitialPc))
		.Return(Opcodes::LD_A_d8);
	fakeit::When(Method(mockMemory, Read).Using(Cpu::InitialPc + 1))
		.Return(immediateValue);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetA() == immediateValue);
}