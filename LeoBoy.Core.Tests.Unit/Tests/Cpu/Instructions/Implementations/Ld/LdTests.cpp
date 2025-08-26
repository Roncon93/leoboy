#include "../../../../../Libraries/catch_amalgamated.hpp"
#include "../../../../../Libraries/fakeit.hpp"
#include "../../InstructionTestsFixture.h"
#include "../../../../../../LeoBoy.Core/src/Cpu/Instructions/Implementations/Ld/Ld.h"

TEST_CASE_METHOD(InstructionTests, "[CPU]: Execute \"LD A, d8\" should load the byte in the next address into register A", "[cpu], [instructions]")
{
	// Arrange
	uint16_t testPc = 0x1234;
	uint8_t immediateValue = 0x42;

	fakeit::When(Method(mockCpu, GetPc))
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