#include "Ld.h"
#include "../../IInstructionRegistrator.h"
#include "../../Opcodes.h"
#include "../../../IWriteCpu.h"
#include "../../../../Memory/IMemory.h"
#include "../../../../Logging/ILogger.h"
#include "../../../../Utilities/BitOperations.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Ld
			{
				void Ld_a16_A(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::LD_a16_A, [](SystemReferences& systems)
						{
							Cpu::IWriteCpu& cpu = systems.GetCpu();
							Memory::IMemory& memory = systems.GetMemory();

							// Read the next 2 immediate 8-bit values from the address pointed to by PC
							uint8_t addressLowByte = memory.Read(cpu.IncrementPc());
							uint8_t addressHighByte = memory.Read(cpu.IncrementPc());

							// Combine the two 8-bit values into a single 16-bit address and write the value of register A to that address
							memory.Write(Utilities::BitOperations::CombineBytes(addressHighByte, addressLowByte), cpu.GetA());
						});
				}
			}
		}
	}
}