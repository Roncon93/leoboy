#include "Instruction.h"

namespace Cpu
{
    namespace Instructions
    {
        SystemReferences::SystemReferences(Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger)
            : cpu(cpu), memory(memory), logger(logger)
        {
        }

        Cpu::IWriteCpu& SystemReferences::GetCpu()
        {
            return cpu;
        }

        Memory::IMemory& SystemReferences::GetMemory()
        {
            return memory;
        }

        Logging::ILogger& SystemReferences::GetLogger()
        {
            return logger;
        }
    }
}