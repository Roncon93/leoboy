#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Execute \"LD a16, A\" should write the value in register A to the specified memory address", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = cpu.GetPc();
	uint8_t addressLowByte = 0x34;
	uint8_t addressHighByte = 0x12;
	uint16_t targetAddress = 0x1234;
	uint8_t registerAValue = 0x56;

	cpu.SetA(registerAValue);
	memory.Write(testPc, Cpu::Instructions::Opcodes::LD_a16_A);
	memory.Write(testPc + 1, addressLowByte);
	memory.Write(testPc + 2, addressHighByte);

	// Act
	cpu.Step();

	// Assert
	memory.Read(targetAddress);
}