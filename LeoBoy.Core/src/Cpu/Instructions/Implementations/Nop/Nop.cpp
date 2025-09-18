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
					registrator.Register(Opcodes::NOP, [](SystemReferences& systems)
						{
							// NOP does nothing
						});
				}
			}
		}
	}
}