#include "Ld.h"

#include "../../Opcodes.h"
#include "../../../../Utilities/BitOperations.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Ld
			{
				void Ld_A_a16(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::LD_A_a16, [](SystemReferences& systems)
						{
							Cpu::IWriteCpu& cpu = systems.GetCpu();
							Memory::IMemory& memory = systems.GetMemory();

							// Read the immediate 16-bit address
							uint8_t addressLowByte = memory.Read(cpu.IncrementPc());
							uint8_t addressHighByte = memory.Read(cpu.IncrementPc());
							uint16_t address = Utilities::BitOperations::CombineBytes(addressHighByte, addressLowByte);

							uint8_t value = memory.Read(address);

							// Load the value into register A
							cpu.SetA(value);
						});
				}
			}
		}
	}
}