#include "Ld.h"
#include "../../IInstructionRegistrator.h"
#include "../../Opcodes.h"
#include "../../../IWriteCpu.h"
#include "../../../../Memory/IMemory.h"
#include "../../../../Logging/ILogger.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			namespace Ld
			{
				void Ld_HL_A(IInstructionRegistrator& registrator)
				{
					registrator.Register(Opcodes::LD_HL_A, [](IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
						{
							uint16_t address = cpu.GetHL();
							memory.Write(address, cpu.GetA());
						});
				}
			}
		}
	}
}