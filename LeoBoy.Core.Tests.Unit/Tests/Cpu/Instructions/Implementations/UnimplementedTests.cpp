#include "../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../Libraries/fakeit.hpp"
#include "../InstructionTestsFixture.h"
#include "../../../../../LeoBoy.Core/src/Cpu/Instructions/Implementations/Unimplemented.h"

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute with invalid opcode should log error", "[cpu], [instructions]")
{
	// Arrange
	uint8_t testOpcode = 0x45;

	// Act
	Cpu::Instructions::Implementations::Unimplemented(registrator, testOpcode);

	// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::UNIMPLEMENTED);
	fakeit::Verify(Method(mockLogger, Log)).Once();
}