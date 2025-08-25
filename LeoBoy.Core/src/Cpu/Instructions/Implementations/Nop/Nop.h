#pragma once

#include "../../IInstructionRegistrator.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Nop
			{
				/// <summary>
				/// Implementation of the NOP (No Operation) instruction.
				/// </summary>
				/// <remarks>
				/// The NOP instruction does nothing and is often used for timing adjustments.
				/// It does not affect any CPU registers or flags.
				/// </remarks>
				void Nop(IInstructionRegistrator& registrator);
			}
		}
	}
}