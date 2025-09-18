#pragma once

#include <functional>
#include "../IWriteCpu.h"
#include "../../Memory/IMemory.h"
#include "../../Logging/ILogger.h"

namespace Cpu
{
    namespace Instructions
    {
        class SystemReferences
        {
        public:
            SystemReferences(Cpu::IWriteCpu& cpu, Memory::IMemory& memory, Logging::ILogger& logger);

            Cpu::IWriteCpu& GetCpu();

            Memory::IMemory& GetMemory();

            Logging::ILogger& GetLogger();

        private:
			Cpu::IWriteCpu& cpu;
			Memory::IMemory& memory;
			Logging::ILogger& logger;
        };

        // Define Instruction as a std::function type matching the lambda signature
        using InstructionHandler = std::function<void(SystemReferences&)>;
    }
}