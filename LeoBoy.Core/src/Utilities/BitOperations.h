#include <cstdint>

namespace Utilities
{
	namespace BitOperations
	{
		/// <summary>
		/// Combines two bytes (8-bit) into a word (16-bit).
		/// </summary>
		/// <param name="high">The high byte (first 4 bits of the word from the left).</param>
		/// <param name="low">The low byte (first 4 bits of the word from the right).</param>
		/// <returns></returns>
		uint16_t CombineBytes(uint8_t high, uint8_t low)
		{
			return (static_cast<uint16_t>(high) << 8) | low;
		}
	}
}