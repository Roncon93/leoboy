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
				void Ld_HL_d16(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::LD_HL_d16, [](Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
						{
							// Read the next 2 immediate 8-bit values from the address pointed to by PC
							uint8_t addressLowByte = memory.Read(cpu.IncrementPc());
							uint8_t addressHighByte = memory.Read(cpu.IncrementPc());

							// HL now points to the new address specified by the instruction's operands
							cpu.SetHL(Utilities::BitOperations::CombineBytes(addressHighByte, addressLowByte));
						});
				}
			}
		}
	}
}