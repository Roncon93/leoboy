#pragma once

#include "../../Libraries/catch_amalgamated.hpp"
#include "../../Libraries/fakeit.hpp"
#include "../../LeoBoy.Core/src/Memory/IMemory.h"
#include "../../LeoBoy.Core/src/Logging/ILogger.h"
#include "../../LeoBoy.Core/src/Cpu/Instructions/IInstructionLookUp.h"
#include "../../LeoBoy.Core/src/Cpu/Cpu.hpp"
#include "../../LeoBoy.Core/src/Cpu/IWriteCpu.h"
#include "../../LeoBoy.Core/src/Memory/Memory.hpp"
#include "../../LeoBoy.Core/src/Cpu/Instructions/InstructionLookUp.hpp"
#include "../../LeoBoy.Core/src/Cpu/Instructions/Opcodes.h"

class CpuTests
{
protected:
    const uint8_t zeroRegisterValue = 0x00;
    const uint8_t testRegisterValue = 0x42;

	Memory::MemoryImpl memory;
	Cpu::Instructions::InstructionLookUpImpl instructions;
    fakeit::Mock<Logging::ILogger> mockLogger;

    Cpu::CpuImpl cpu;

    CpuTests() : memory(), instructions(), cpu(memory, mockLogger.get(), instructions)
    {
		fakeit::Fake(Method(mockLogger, Log));
    }
};