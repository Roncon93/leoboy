#pragma once

#include <cstdint>

/// <summary>
/// Constants representing Game Boy CPU opcode values.
/// </summary>
namespace Cpu
{
	namespace Instructions
	{
		namespace Opcodes
		{
			/// <summary>
			/// No Operation - does nothing.
			/// </summary>
			/// <remarks>
			/// This opcode is used for timing adjustments and can be used to create delays
			/// without affecting the state of the CPU or memory.
			/// </remarks>
			static constexpr uint8_t NOP = 0x00;

			/// <summary>
			/// Represents the opcode for the "LD A, d8" instruction
			/// which loads an immediate 8-bit value into the accumulator register A.
			/// </summary>
			static constexpr uint8_t LD_A_d8 = 0x3E;
		}
	}
}