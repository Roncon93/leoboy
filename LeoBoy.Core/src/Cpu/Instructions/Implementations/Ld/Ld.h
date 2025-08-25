#pragma once

#include "../../IInstructionRegistrator.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Ld
			{
				/// <summary>
				/// Implementation of the "LD A, d8" instruction.
				/// </summary>
				/// <remarks>
				/// This instruction loads an immediate 8-bit value into the accumulator register A.
				/// It is represented by the opcode 0x3E.
				/// </remarks>
				void Ld_A_d8(IInstructionRegistrator& registrator);
			}
		}
	}
}