#pragma once

#include <cstdint>
#include "Instruction.h"

namespace Cpu
{
	namespace Instructions
	{
		/// <summary>
		/// Interface for registering CPU instructions with their corresponding opcodes.
		/// </summary>
		class IInstructionRegistrator
		{
		public:
			/// <summary>
			/// Default virtual destructor.
			/// </summary>
			virtual ~IInstructionRegistrator() = default;

			/// <summary>
			/// Registers an instruction implementation for the specified opcode.
			/// </summary>
			/// <param name="opcode">The opcode of the instruction to register.</param>
			/// <param name="instruction">The instruction implementation to associate with the opcode.</param>
			virtual void Register(uint8_t opcode, InstructionHandler instruction) = 0;
		};
	}
}