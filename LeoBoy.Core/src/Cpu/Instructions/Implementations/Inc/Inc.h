#pragma once

#include "../../IInstructionRegistrator.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Inc
			{
				/// <summary>
				/// Implementation of the "INC A" instruction.
				/// </summary>
				/// <param name="registrator">The instruction registrator.</param>
				/// <remarks>
				/// This instruction increases the value of the A register by 1 and sets
				/// the register F flags with the results.
				/// </remarks>
				void Inc_A(IInstructionRegistrator& registrator);
			}
		}
	}
}