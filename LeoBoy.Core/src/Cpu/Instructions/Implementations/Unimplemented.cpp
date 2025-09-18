#include "Unimplemented.h"

#include <cstdint>
#include <sstream>
#include "../Opcodes.h"

namespace Cpu
{
	namespace Instructions
	{
		namespace Implementations
		{
			void Unimplemented(IInstructionRegistrator& registrator, uint8_t opcode)
			{
				registrator.Register(opcode, [opcode](SystemReferences& systems)
					{
						// Log unimplemented opcode usage
						std::stringstream stream;
						stream << "Unimplemented opcode: 0x" << std::hex << (int)opcode << "\n";
							
						systems.GetLogger().Log(1, stream.str());
					});
			}
		}
	}
}