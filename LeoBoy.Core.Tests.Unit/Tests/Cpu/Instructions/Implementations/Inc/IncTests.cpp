#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../../Libraries/fakeit.hpp"
#include "../../../../../../LeoBoy.Core/src/Cpu/Instructions/Implementations/Inc/Inc.h"
#include "IncTestsFixture.h"

TEST_CASE_METHOD(IncTestsFixture, "[CPU]: Execute \"INC A\" should increment register A by 1", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint8_t testValue = 0;

	fakeit::When(Method(mockCpu, GetA))
		.AlwaysReturn(testValue);

	// Act
	Cpu::Instructions::Implementations::Inc::Inc_A(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::Inc_A);
	fakeit::Verify(Method(mockCpu, SetA).Using(testValue + 1)).Once();
	fakeit::Verify(Method(mockCpu, SetZeroFlag)).Never();
	fakeit::Verify(Method(mockCpu, SetSubtractFlag).Using(false)).Once();
	fakeit::Verify(Method(mockCpu, SetHalfCarryFlag)).Never();
	fakeit::Verify(Method(mockCpu, SetCarryFlag)).Never();
}

TEST_CASE_METHOD(IncTestsFixture, "[CPU]: Execute \"INC A\" should set the zero flag if the increment results in 0", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint8_t testValue = 0xFF;

	fakeit::When(Method(mockCpu, GetA))
		.Return(testValue, 0);

	// Act
	Cpu::Instructions::Implementations::Inc::Inc_A(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::Inc_A);
	fakeit::Verify(Method(mockCpu, SetZeroFlag).Using(true)).Once();
}

TEST_CASE_METHOD(IncTestsFixture, "[CPU]: Execute \"INC A\" should set the half-carry flag if the increment resulter in overflow from bit 3 to bit 4", "[unit], [cpu], [instructions]")
{
	// Arrange
	uint8_t testValue = GENERATE(0x0F, 0x1F, 0x2F, 0x3F, 0x4F, 0x5F, 0x6F, 0x7F, 0x8F, 0x9F, 0xAF, 0xBF, 0xCF, 0xDF, 0xEF);

	fakeit::When(Method(mockCpu, GetA))
		.Return(testValue, testValue + 1);

	// Act
	Cpu::Instructions::Implementations::Inc::Inc_A(registrator);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::Inc_A);
	fakeit::Verify(Method(mockCpu, SetHalfCarryFlag).Using(true)).Once();
}