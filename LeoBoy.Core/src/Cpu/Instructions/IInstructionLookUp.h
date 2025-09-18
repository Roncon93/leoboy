#pragma once

#include "Instruction.h"

namespace Cpu
{
	namespace Instructions
	{
		/// <summary>
		/// Interface for looking up and executing CPU instructions based on opcodes.
		/// </summary>
		class IInstructionLookUp
		{
		public:
			/// <summary>
			/// Default virtual destructor.
			/// </summary>
			virtual ~IInstructionLookUp() = default;

			/// <summary>
			/// Retrieves the registered instruction implementation for the specified opcode.
			/// </summary>
			/// <param name="opcode">The opcode of the instruction to look up.</param>
			virtual InstructionHandler Get(uint8_t opcode) = 0;
		};
	}
}