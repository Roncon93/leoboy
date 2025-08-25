#pragma once

#include "../../Libraries/catch_amalgamated.hpp"
#include "../../Libraries/fakeit.hpp"
#include "../../LeoBoy.Core/src/Memory/IMemory.h"
#include "../../LeoBoy.Core/src/Logging/ILogger.h"
#include "../../LeoBoy.Core/src/Cpu/Instructions/IInstructionLookUp.h"
#include "../../LeoBoy.Core/src/Cpu/Cpu.hpp"
#include "../../LeoBoy.Core/src/Cpu/IWriteCpu.h"

class CpuTests
{
protected:
    const uint8_t zeroRegisterValue = 0x00;
    const uint8_t testRegisterValue = 0x42;

    fakeit::Mock<Memory::IMemory> mockMemory;
    fakeit::Mock<Logging::ILogger> mockLogger;
	fakeit::Mock<Cpu::Instructions::IInstructionLookUp> mockInstructionLookUp;

    Cpu::CpuImpl cpu;

    CpuTests() : cpu(mockMemory.get(), mockLogger.get(), mockInstructionLookUp.get())
    {
        fakeit::Fake(Method(mockLogger, Log));
    }
};