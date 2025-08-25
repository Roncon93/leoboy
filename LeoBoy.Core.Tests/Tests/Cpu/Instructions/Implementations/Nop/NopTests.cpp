#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../../Libraries/fakeit.hpp"
#include "../../InstructionTestsFixture.h"
#include "../../../../../../LeoBoy.Core/src/Cpu/Instructions/Implementations/Nop/Nop.h"

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute NOP opcode does nothing", "[cpu], [instructions]")
{
	// Act
	Cpu::Instructions::Implementations::Nop::Nop(registrator);

	//// Assert
	AssertOpcode(Cpu::Instructions::Opcodes::NOP);
	fakeit::VerifyNoOtherInvocations(mockCpu);
	fakeit::VerifyNoOtherInvocations(mockMemory);
	fakeit::VerifyNoOtherInvocations(mockLogger);
}