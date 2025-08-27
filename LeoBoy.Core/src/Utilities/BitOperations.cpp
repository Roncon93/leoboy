#include "BitOperations.h"

namespace Utilities
{
	namespace BitOperations
	{
		uint16_t CombineBytes(uint8_t high, uint8_t low)
		{
			return (static_cast<uint16_t>(high) << 8) | static_cast<uint16_t>(low);
		}
	}
}