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
				/// <param name="registrator">The instruction registrator.</param>
				/// <remarks>
				/// This instruction loads an immediate 8-bit value into the accumulator register A.
				/// It is represented by the opcode 0x3E.
				/// </remarks>
				void Ld_A_d8(IInstructionRegistrator& registrator);

				/// <summary>
				/// Implementation of the "LD A, (HL)" instruction.
				/// </summary>
				/// <param name="registrator">The instruction registrator.</param>
				/// <remarks>
				/// This instruction loads the value from the memory address pointed to by the HL register pair into register A.
				/// </remarks>
				void Ld_A_HL(IInstructionRegistrator& registrator);

				/// <summary>
				/// Implementation of the "LD (HL), A" instruction.
				/// </summary>
				/// <param name="registrator">The instruction registrator.</param>
				/// <remarks>
				/// This instruction stores the value from register A into the memory address pointed to by the HL register pair.
				/// </remarks>
				void Ld_HL_A(IInstructionRegistrator& registrator);

				/// <summary>
				/// Implementation of the "LD (HL), d16" instruction.
				/// </summary>
				/// <param name="registrator">The instruction registrator.</param>
				/// <remarks>
				/// This instruction stores the value stored in a memory address into the combined HL registry.
				/// </remarks>
				void Ld_HL_d16(IInstructionRegistrator& registrator);

				/// <summary>
				/// Implementation of the "LD A, (a16)" instruction.
				/// </summary>
				/// <param name="registrator">The instruction registrator.</param>
				/// <remarks>
				/// This instruction loads the value from the memory address specified by the 16-bit immediate value into register A.
				/// </remarks>
				void Ld_a16_A(IInstructionRegistrator& registrator);
			}
		}
	}
}