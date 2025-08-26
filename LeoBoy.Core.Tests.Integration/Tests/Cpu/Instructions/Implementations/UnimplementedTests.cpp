#include "../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../Libraries/fakeit.hpp"
#include"../../CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Executing an unimplemented opcode should log an error", "[integration], [cpu], [instructions]")
{
	// Arrange
	uint8_t testOpcode = Cpu::Instructions::Opcodes::UNIMPLEMENTED;
	uint16_t testPc = cpu.GetPc();

	memory.Write(testPc, testOpcode);

	fakeit::Fake(Method(mockLogger, Log));

	// Act
	cpu.Step();

	// Assert
	fakeit::Verify(Method(mockLogger, Log)).Once();
}