#pragma once

#include "../../catch_amalgamated.hpp"
#include "../../fakeit.hpp"
#include "../../LeoBoy.Core/src/IMemory.h"
#include "../../LeoBoy.Core/src/Cpu.h"

class CpuTests
{
protected:
    const uint8_t zeroRegisterValue = 0x00;
    const uint8_t testRegisterValue = 0x42;

    fakeit::Mock<IMemory> mockMemory;
    fakeit::Mock<ILogger> mockLogger;

    Cpu cpu;

    CpuTests() : cpu(mockMemory.get(), mockLogger.get())
    {
        fakeit::Fake(Method(mockLogger, Log));
    }
};