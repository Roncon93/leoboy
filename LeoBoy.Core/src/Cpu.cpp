#include "Cpu.h"

Cpu::Cpu()
    : a(0), f(0), b(0), c(0), d(0), e(0), h(0), l(0)
{
}

uint16_t Cpu::GetAF() const
{
    return (static_cast<uint16_t>(a) << 8) | (f & 0xF0);
}

void Cpu::SetAF(uint16_t value)
{
    a = static_cast<uint8_t>((value >> 8) & 0xFF);
    f = static_cast<uint8_t>(value & 0xF0);
}

uint16_t Cpu::GetBC() const
{
    return (static_cast<uint16_t>(b) << 8) | c;
}

void Cpu::SetBC(uint16_t value)
{
    b = static_cast<uint8_t>((value >> 8) & 0xFF);
    c = static_cast<uint8_t>(value & 0xFF);
}

uint16_t Cpu::GetDE() const
{
    return (static_cast<uint16_t>(d) << 8) | e;
}

void Cpu::SetDE(uint16_t value)
{
    d = static_cast<uint8_t>((value >> 8) & 0xFF);
    e = static_cast<uint8_t>(value & 0xFF);
}

uint16_t Cpu::GetHL() const
{
    return (static_cast<uint16_t>(h) << 8) | l;
}

void Cpu::SetHL(uint16_t value)
{
    h = static_cast<uint8_t>((value >> 8) & 0xFF);
    l = static_cast<uint8_t>(value & 0xFF);
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
