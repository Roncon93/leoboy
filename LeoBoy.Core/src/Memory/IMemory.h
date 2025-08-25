#pragma once

#include <cstdint>

namespace Memory
{
	/// <summary>
	/// Represents the memory map of the Game Boy system.
	/// This class provides an interface to read and write bytes
	/// to a 64 KB address space, mimicking the behavior of the
	/// Game Boy's memory bus.
	/// </summary>
	/// <remarks>
	/// The Game Boy has a 16-bit address bus, meaning it can
	/// address 65,536 (0x10000) individual bytes of memory.  
	/// Memory is accessed via the read and write methods, which
	/// will later handle different regions like ROM, RAM, VRAM,
	/// and I/O registers based on address ranges.
	///
	/// Internally, the memory is stored as a fixed-size array
	/// of bytes (uint8_t), representing the flat memory space.
	/// </remarks>
	class IMemory
	{
	public:
		/// <summary>
		/// Default virtual destructor.
		/// </summary>
		virtual ~IMemory() = default;

		/// <summary>
		/// Reads an 8-bit value from the specified address.
		/// </summary>
		/// <param name="address">The 16-bit address from which to read the value.</param>
		/// <returns>The 8-bit value read from the given address.</returns>
		virtual uint8_t Read(uint16_t address) const = 0;

		/// <summary>
		/// Writes an 8-bit value to the specified 16-bit address.
		/// </summary>
		/// <param name="address">The 16-bit address to which the value will be written.</param>
		/// <param name="value">The 8-bit value to write.</param>
		virtual void Write(uint16_t address, uint8_t value) = 0;
	};
}