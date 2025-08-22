#include "Cpu.h"
#include "Opcodes.h"
#include <iostream>
#include <sstream>

Cpu::Cpu(IMemory& memory, ILogger& logger)
    : memory(memory), logger(logger), pc(InitialPc), sp(InitialSp), a(0), f(0), b(0), c(0), d(0), e(0), h(0), l(0)
{
}

uint8_t Cpu::Fetch()
{
    return memory.Read(pc++);
}

void Cpu::Execute(uint8_t opcode)
{
    switch (opcode)
    {
        case Opcodes::NOP:
            // Do nothing
            break;

        case Opcodes::LD_A_d8:
            SetA(memory.Read(pc++));
			break;

        default:
			std::stringstream stream;
            stream << "Unimplemented opcode: 0x" << std::hex << (int)opcode << "\n";

			logger.Log(1, stream.str());
            break;
    }
}

void Cpu::Step()
{
    Execute(Fetch());
}

uint16_t Cpu::GetAF() const
{
    return GetCombinedRegister(a, f);
}

void Cpu::SetAF(uint16_t value)
{
	SetCombinedRegister(value, a, f);
    SetF(f);
}

uint16_t Cpu::GetBC() const
{
    return GetCombinedRegister(b, c);
}

void Cpu::SetBC(uint16_t value)
{
	SetCombinedRegister(value, b, c);
}

uint16_t Cpu::GetDE() const
{
    return GetCombinedRegister(d, e);
}

void Cpu::SetDE(uint16_t value)
{
	SetCombinedRegister(value, d, e);
}

uint16_t Cpu::GetHL() const
{
	return GetCombinedRegister(h, l);
}

void Cpu::SetHL(uint16_t value)
{
	SetCombinedRegister(value, h, l);
}

uint8_t Cpu::GetA() const
{
    return a;
}

void Cpu::SetA(uint8_t value)
{
    a = value;
}

uint8_t Cpu::GetF() const
{
    return f;
}

void Cpu::SetF(uint8_t value)
{
    f = value & 0xF0;
}

uint8_t Cpu::GetB() const
{
    return b;
}

void Cpu::SetB(uint8_t value)
{
    b = value;
}

uint8_t Cpu::GetC() const
{
    return c;
}

void Cpu::SetC(uint8_t value)
{
    c = value;
}

uint8_t Cpu::GetD() const
{
    return d;
}

void Cpu::SetD(uint8_t value)
{
    d = value;
}

uint8_t Cpu::GetE() const
{
    return e;
}

void Cpu::SetE(uint8_t value)
{
    e = value;
}

uint8_t Cpu::GetH() const
{
    return h;
}

void Cpu::SetH(uint8_t value)
{
    h = value;
}

uint8_t Cpu::GetL() const
{
    return l;
}

void Cpu::SetL(uint8_t value)
{
    l = value;
}

uint16_t Cpu::GetCombinedRegister(uint8_t high, uint8_t low) const
{
	return (static_cast<uint16_t>(high) << 8) | low;
}

void Cpu::SetCombinedRegister(uint16_t value, uint8_t& high, uint8_t& low)
{
    high = static_cast<uint8_t>((value >> 8) & 0xFF);
    low = static_cast<uint8_t>(value & 0xFF);
}
