#pragma once

#include <functional>
#include "../IWriteCpu.h"
#include "../../Memory/IMemory.h"
#include "../../Logging/ILogger.h"

namespace Cpu
{
    namespace Instructions
    {
        // Define Instruction as a std::function type matching the lambda signature
        using Instruction = std::function<void(Cpu::IWriteCpu&, Memory::IMemory&, Logging::ILogger&)>;
    }
}