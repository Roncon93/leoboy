#pragma once

#include <iostream>
#include <sstream>
#include "ICpu.h"
#include "IWriteCpu.h"
#include "Instructions/Opcodes.h"
#include "Instructions/IInstructionLookUp.h"
#include "../Memory/IMemory.h"
#include "../Logging/ILogger.h"

namespace Cpu
{
	class CpuImpl : public IWriteCpu
    {
	public:
        /// <summary>
        /// Initializes all registers to zero.
        /// </summary>
        CpuImpl(Memory::IMemory& memory, Logging::ILogger& logger, Instructions::IInstructionLookUp& instructions)
            : memory(memory), logger(logger), instructions(instructions), pc(InitialPc), sp(InitialSp),
            a(0), f(0), b(0), c(0), d(0), e(0), h(0), l(0)
        {
        }

        uint8_t Fetch() override
        {
            return memory.Read(pc++);
        }

        void Execute(uint8_t opcode)
        {
			Instructions::Instruction instruction = instructions.Get(opcode);
			instruction(*this, memory, logger);
        }

        void Step() override
        {
            Execute(Fetch());
        }

        const uint16_t GetPc() override
        {
            return pc;
		}

        uint16_t IncrementPc() override
        {
            return pc++;
		}

        const uint16_t GetAF() override
        {
            return GetCombinedRegister(a, f);
        }

        void SetAF(uint16_t value) override
        {
            SetCombinedRegister(value, a, f);
            SetF(f);
        }

        const uint16_t GetBC() override
        {
            return GetCombinedRegister(b, c);
        }

		void SetBC(uint16_t value) override
        {
            SetCombinedRegister(value, b, c);
        }

        const uint16_t GetDE() override
        {
            return GetCombinedRegister(d, e);
        }

		void SetDE(uint16_t value) override
        {
            SetCombinedRegister(value, d, e);
        }

        const uint16_t GetHL() override
        {
            return GetCombinedRegister(h, l);
        }

		void SetHL(uint16_t value) override
        {
            SetCombinedRegister(value, h, l);
        }

        const uint8_t GetA() override
        {
            return a;
        }

		void SetA(uint8_t value) override
        {
            a = value;
        }

        const uint8_t GetF() override
        {
            return f;
        }

		void SetF(uint8_t value) override
        {
            f = value & 0xF0;
        }

        const uint8_t GetB() override
        {
            return b;
        }

		void SetB(uint8_t value) override
        {
            b = value;
        }

        const uint8_t GetC() override
        {
            return c;
        }

		void SetC(uint8_t value) override
        {
            c = value;
        }

        const uint8_t GetD() override
        {
            return d;
        }

		void SetD(uint8_t value) override
        {
            d = value;
        }

        const uint8_t GetE() override
        {
            return e;
        }

		void SetE(uint8_t value) override
        {
            e = value;
        }

        const uint8_t GetH() override
        {
            return h;
        }

		void SetH(uint8_t value) override
        {
            h = value;
        }

        const uint8_t GetL() override
        {
            return l;
        }

		void SetL(uint8_t value) override
        {
            l = value;
        }

    private:
		// References to memory and logger
        Memory::IMemory& memory;
        Logging::ILogger& logger;

		// Program Counter and Stack Pointer
        uint16_t pc;
        uint16_t sp;

		// 8-bit registers
        uint8_t a;
        uint8_t f;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t h;
        uint8_t l;

		// Instruction lookup service
		Instructions::IInstructionLookUp& instructions;
        
        /// <summary>
        /// Returns the current value of PC and then increments it.
        /// </summary>
        /// <returns>The value of PC before it is incremented.</returns>
        uint16_t GetAndIncrementPc()
        {
            return pc++;
		}

        /// <summary>
		/// Returns a combined 16-bit register from two 8-bit high and low parts.
        /// </summary>
        /// <param name="high">The high part of the register.</param>
        /// <param name="low">The low part of the register.</param>
        /// <returns>The combined register value.</returns>
        uint16_t GetCombinedRegister(uint8_t high, uint8_t low) const
        {
            return (static_cast<uint16_t>(high) << 8) | low;
        }

		/// <summary>
		/// Sets the high and low parts of a combined 16-bit register.
		/// </summary>
		/// <param name="value">The 16-bit value to set.</param>
		/// <param name="high">Reference to the high part of the register to set.</param>
		/// <param name="low">Reference to the low part of the register to set.</param>
        void SetCombinedRegister(uint16_t value, uint8_t& high, uint8_t& low)
        {
            high = static_cast<uint8_t>((value >> 8) & 0xFF);
            low = static_cast<uint8_t>(value & 0xFF);
        }
    };
}