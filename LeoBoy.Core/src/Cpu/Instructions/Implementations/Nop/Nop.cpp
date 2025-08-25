#include "Nop.h"
#include "../../Opcodes.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Nop
			{
				void Nop(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::NOP, [](Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
						{
							// NOP does nothing
						});
				}
			}
		}
	}
}