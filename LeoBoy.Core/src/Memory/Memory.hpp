#pragma once

#include <array>
#include "IMemory.h"

namespace Memory
{
	class MemoryImpl : public Memory::IMemory
	{
	public:
		/// <summary>
		/// Total size of the addressable memory space.
		/// </summary>
		static constexpr size_t MemorySize = 0x10000; // 64 KB

		/// <summary>
		/// Initializes all memory addresses to zero.
		/// </summary>
		MemoryImpl()
		{
			data.fill(0);
		}

		uint8_t Read(uint16_t address) const override
		{
			return data[address];
		}

		void Write(uint16_t address, uint8_t value) override
		{
			data[address] = value;
		}

	private:
		/// <summary>
		/// Defines a fixed-size array of 65,536 bytes
		/// which represents the memory of the device.
		/// </summary>
		std::array<uint8_t, MemorySize> data;
	};
}