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
				registrator.Register(opcode, [opcode](Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
					{
						// Log unimplemented opcode usage
						std::stringstream stream;
						stream << "Unimplemented opcode: 0x" << std::hex << (int)opcode << "\n";
							
						logger.Log(1, stream.str());
					});
			}
		}
	}
}