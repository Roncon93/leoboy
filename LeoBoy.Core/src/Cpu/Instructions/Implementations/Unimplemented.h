#pragma once

#include <cstdint>
#include "../IInstructionRegistrator.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			/// <summary>
			/// Implementation of an unimplemented instruction handler.
			/// </summary>
			/// <remarks>
			/// This handler is used for opcodes that have not yet been implemented.
			/// When executed, it logs a message indicating the unimplemented opcode.
			/// </remarks>
			void Unimplemented(IInstructionRegistrator& registrator, uint8_t opcode);
		}
	}
}