#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../../Libraries/fakeit.hpp"
#include "../../../../../../LeoBoy.Core/src/Cpu/Instructions/Implementations/Inc/Inc.h"
#include "../../../CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"INC A\" should increment register A by 1", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint16_t initialPc = cpu.GetPc();
	uint8_t testValue = 0x00;

	cpu.SetA(testValue);
	memory.Write(initialPc, Cpu::Instructions::Opcodes::Inc_A);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetA() == testValue + 1);
	REQUIRE(cpu.GetZeroFlag() == false);
	REQUIRE(cpu.GetSubtractFlag() == false);
	REQUIRE(cpu.GetHalfCarryFlag() == false);
	REQUIRE(cpu.GetCarryFlag() == false);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"INC A\" should set the zero flag if the increment results in 0", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint16_t initialPc = cpu.GetPc();
	uint8_t testValue = 0xFF;

	cpu.SetA(testValue);
	memory.Write(initialPc, Cpu::Instructions::Opcodes::Inc_A);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetZeroFlag() == true);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"INC A\" should set the half-carry flag if the increment resulter in overflow from bit 3 to bit 4", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint8_t testValue = GENERATE(0x0F, 0x1F, 0x2F, 0x3F, 0x4F, 0x5F, 0x6F, 0x7F, 0x8F, 0x9F, 0xAF, 0xBF, 0xCF, 0xDF, 0xEF);
	uint16_t initialPc = cpu.GetPc();

	cpu.SetA(testValue);
	memory.Write(initialPc, Cpu::Instructions::Opcodes::Inc_A);

	// Act
	cpu.Step();

	// Assert
	REQUIRE(cpu.GetHalfCarryFlag() == true);
}