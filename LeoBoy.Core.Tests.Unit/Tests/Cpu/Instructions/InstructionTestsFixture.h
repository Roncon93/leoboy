#pragma once

#include <functional>
#include "../../../Libraries/catch_amalgamated.hpp"
#include "../../../Libraries/fakeit.hpp"
#include "../../../../LeoBoy.Core/src/Cpu/Instructions/IInstructionRegistrator.h"
#include "../../../../LeoBoy.Core/src/Cpu/Instructions/Opcodes.h"

class InstructionTests
{
public:
	class TestInstructionRegistrator : public Cpu::Instructions::IInstructionRegistrator
	{
	public:
		uint8_t registeredOpcode;
		Cpu::Instructions::SystemReferences systems;

        // Replace the initialization of assertOpcode in TestInstructionRegistrator's constructor with the correct lambda assignment
        TestInstructionRegistrator(Cpu::Instructions::SystemReferences systems)
									: systems(systems), registeredOpcode(0)
        {
        }

		void Register(uint8_t opcode, Cpu::Instructions::InstructionHandler instruction) override
		{
			registeredOpcode = opcode;

			// For testing, we can directly invoke the instruction to verify its behavior
			instruction(systems);
		}
	};
protected:
	fakeit::Mock<Cpu::IWriteCpu> mockCpu;
	fakeit::Mock<Memory::IMemory> mockMemory;
	fakeit::Mock<Logging::ILogger> mockLogger;

	TestInstructionRegistrator registrator;

	InstructionTests() : registrator(Cpu::Instructions::SystemReferences(mockCpu.get(), mockMemory.get(), mockLogger.get()))
	{
		fakeit::Fake(Method(mockCpu, IncrementPc));
		fakeit::Fake(Method(mockLogger, Log));
	}

	void AssertOpcode(uint8_t expectedOpcode) const
	{
		REQUIRE(registrator.registeredOpcode == expectedOpcode);
	}
};