#include "Inc.h"
#include "../../Opcodes.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Inc
			{
				void Inc_A(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::Inc_A, [](Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
						{
							// Increment the value in register A
							uint8_t originalValue = cpu.GetA();
							uint8_t result = originalValue + 1;
							cpu.SetA(result);

							// Set Zero flag if result is zero
							if (result == 0)
							{
								cpu.SetZeroFlag(true);
							}

							// Set Half Carry flag if there was a carry from bit 3 to bit 4
							if ((originalValue & 0x0F) + 1 > 0x0F)
							{
								cpu.SetHalfCarryFlag(true);
							}

							// Reset Subtract flag (bit 6) since this is an addition operation
							cpu.SetSubtractFlag(false);
						});
				}
			}
		}
	}
}