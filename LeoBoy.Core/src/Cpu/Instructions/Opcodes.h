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
			/// Placeholder for unimplemented opcodes.
			/// </summary>
			static constexpr uint8_t UNIMPLEMENTED = 0xFF;

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

			/// <summary>
			/// Represents the opcode for the "LD A, (HL)" instruction
			/// which loads the value from the memory address pointed to by the HL register pair into register A.
			/// </summary>
			static constexpr uint8_t LD_A_HL = 0x7E;

			/// <summary>
			/// Represents the opcode for the "LD (HL), A" instruction
			/// which stores the value from register A into the memory address pointed to by the HL register pair.
			/// </summary>
			static constexpr uint8_t LD_HL_A = 0x77;

			/// <summary>
			/// Represents the opcode for the "LD (HL), d16" instruction
			/// which stores the value in a memory address into the HL register pair.
			/// </summary>
			static constexpr uint8_t LD_HL_d16 = 0x21;

			/// <summary>
			/// Represents the opcode for the "LD (a16), A" instruction
			/// which loads the value from register A into the memory address specified by the 16-bit immediate value.
			/// </summary>
			static constexpr uint8_t LD_a16_A = 0xEA;

			/// <summary>
			/// Represents the opcode for the "INC A" instruction
			/// which increments the value in register A by 1 and updates the flags in register F accordingly.
			/// </summary>
			static constexpr uint8_t Inc_A = 0x3C;
		}
	}
}