#include "Ld.h"

#include "../../Opcodes.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Ld
			{
				void Ld_A_d8(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::LD_A_d8, [](Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
						{
							// Read the immediate 8-bit value from the address pointed to by PC and increment PC
							uint8_t value = memory.Read(cpu.GetPc());
							cpu.IncrementPc();

							// Load the value into register A
							cpu.SetA(value);
						});
				}
			}
		}
	}
}