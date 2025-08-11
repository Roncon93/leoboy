#include "Memory.h"

Memory::Memory()
{
	data.fill(0); // Initialize all memory to zero
}

uint8_t Memory::Read(uint16_t address) const
{
	return data[address];
}

void Memory::Write(uint16_t address, uint8_t value)
{
	data[address] = value;
}