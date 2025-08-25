#pragma once

#include <iostream>
#include <sstream>
#include "ICpu.h"
#include "Instructions/Opcodes.h"
#include "../Memory/IMemory.h"
#include "../Logging/ILogger.h"

namespace Cpu
{
    class CpuImpl : public ICpu
    {
	public:
        /// <summary>
        /// Initializes all registers to zero.
        /// </summary>
        CpuImpl(Memory::IMemory& memory, ILogger& logger)
            : memory(memory), logger(logger), pc(InitialPc), sp(InitialSp),
            a(0), f(0), b(0), c(0), d(0), e(0), h(0), l(0)
        {
        }

        uint8_t Fetch() override
        {
            return memory.Read(pc++);
        }

        void Execute(uint8_t opcode)
        {
            switch (opcode)
            {
            case Cpu::Instructions::Opcodes::NOP:
                // Do nothing
                break;

            case Cpu::Instructions::Opcodes::LD_A_d8:
                SetA(memory.Read(pc++));
                break;

            default:
                std::stringstream stream;
                stream << "Unimplemented opcode: 0x" << std::hex << (int)opcode << "\n";

                logger.Log(1, stream.str());
                break;
            }
        }

        void Step() override
        {
            Execute(Fetch());
        }

        uint16_t GetAF() const override
        {
            return GetCombinedRegister(a, f);
        }

        void SetAF(uint16_t value) override
        {
            SetCombinedRegister(value, a, f);
            SetF(f);
        }

		uint16_t GetBC() const override
        {
            return GetCombinedRegister(b, c);
        }

		void SetBC(uint16_t value) override
        {
            SetCombinedRegister(value, b, c);
        }

		uint16_t GetDE() const override
        {
            return GetCombinedRegister(d, e);
        }

		void SetDE(uint16_t value) override
        {
            SetCombinedRegister(value, d, e);
        }

		uint16_t GetHL() const override
        {
            return GetCombinedRegister(h, l);
        }

		void SetHL(uint16_t value) override
        {
            SetCombinedRegister(value, h, l);
        }

        uint8_t GetA() const override
        {
            return a;
        }

		void SetA(uint8_t value) override
        {
            a = value;
        }

		uint8_t GetF() const override
        {
            return f;
        }

		void SetF(uint8_t value) override
        {
            f = value & 0xF0;
        }

        uint8_t GetB() const override
        {
            return b;
        }

		void SetB(uint8_t value) override
        {
            b = value;
        }

		uint8_t GetC() const override
        {
            return c;
        }

		void SetC(uint8_t value) override
        {
            c = value;
        }

		uint8_t GetD() const override
        {
            return d;
        }

		void SetD(uint8_t value) override
        {
            d = value;
        }

		uint8_t GetE() const override
        {
            return e;
        }

		void SetE(uint8_t value) override
        {
            e = value;
        }

		uint8_t GetH() const override
        {
            return h;
        }

		void SetH(uint8_t value) override
        {
            h = value;
        }

		uint8_t GetL() const override
        {
            return l;
        }

		void SetL(uint8_t value) override
        {
            l = value;
        }

    private:
        Memory::IMemory& memory;
        ILogger& logger;
        uint16_t pc;
        uint16_t sp;
        uint8_t a;
        uint8_t f;
        uint8_t b;
        uint8_t c;
        uint8_t d;
        uint8_t e;
        uint8_t h;
        uint8_t l;

        uint16_t GetCombinedRegister(uint8_t high, uint8_t low) const
        {
            return (static_cast<uint16_t>(high) << 8) | low;
        }

        void SetCombinedRegister(uint16_t value, uint8_t& high, uint8_t& low)
        {
            high = static_cast<uint8_t>((value >> 8) & 0xFF);
            low = static_cast<uint8_t>(value & 0xFF);
        }
    };
}