#pragma once
#include <cstdint>

/// <summary>
/// Constants representing Game Boy CPU opcode values.
/// </summary>
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
}