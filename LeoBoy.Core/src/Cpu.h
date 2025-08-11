#pragma once
#include <cstdint>
#include "Memory.h"

/// <summary>
/// Emulates the Game Boy CPU registers and basic operations.
/// </summary>
/// <remarks>
/// The Game Boy CPU (a modified Z80-like 8-bit processor) has eight 8-bit registers:
/// A, F, B, C, D, E, H, and L. Some instructions use these registers combined into
/// 16-bit pairs for addressing or arithmetic:
/// - AF: Accumulator (A) and Flags (F)
/// - BC: B and C
/// - DE: D and E
/// - HL: H and L
///
/// Combined registers are represented as 16-bit values, formed by placing the high
/// byte in the upper 8 bits and the low byte in the lower 8 bits.
///
/// Example:
/// - BC combined register: B is the high byte, C is the low byte.
/// - GetBC() returns (B << 8) | C.
/// - SetBC(value) splits the 16-bit value into high and low bytes:
///   B = value >> 8; C = value & 0xFF.
///
/// The F register is special: it stores CPU flags in its upper nibble,
/// and the lower nibble is always zero. Thus, when setting F,
/// the lower 4 bits are masked out to ensure correctness.
///
/// These operations mimic the behavior of the Game Boy hardware registers
/// and are fundamental to accurate CPU emulation.
/// </remarks>
class Cpu
{
public:
	/// <summary>
	/// Program Counter initialized to 0x0100, where the BIOS ends
	/// </summary>
	static constexpr uint16_t InitialPc = 0x0100;

    /// <summary>
    /// Stack Pointer initialized to 0xFFFE, pointing to the top of the memory
	/// </summary>
	static constexpr uint16_t InitialSp = 0xFFFE;

    /// <summary>
    /// Initializes all registers to zero.
    /// </summary>
    Cpu(Memory& memory);

    /// <summary>
    /// Fetches the next opcode from memory and increments PC.
    /// </summary>
    uint8_t Fetch();

    /// <summary>
    /// Decodes and executes a single CPU instruction.
    /// </summary>
    /// <param name="opcode">The opcode byte fetched from memory.</param>
    void Execute(uint8_t opcode);

    /// <summary>
    /// Runs one CPU instruction cycle: fetch, decode, and execute.
    /// </summary>
    void Step();

    /// <summary>
    /// Gets the combined 16-bit AF register.
    /// </summary>
    /// <returns>The 16-bit AF register value.</returns>
    uint16_t GetAF() const;

    /// <summary>
    /// Sets the combined 16-bit AF register.
    /// </summary>
    /// <param name="value">The 16-bit value to set.</param>
    void SetAF(uint16_t value);

    /// <summary>
    /// Gets the combined 16-bit BC register.
    /// </summary>
    uint16_t GetBC() const;

    /// <summary>
    /// Sets the combined 16-bit BC register.
    /// </summary>
    /// <param name="value">The 16-bit value to set.</param>
    void SetBC(uint16_t value);

    /// <summary>
    /// Gets the combined 16-bit DE register.
    /// </summary>
    uint16_t GetDE() const;

    /// <summary>
    /// Sets the combined 16-bit DE register.
    /// </summary>
    /// <param name="value">The 16-bit value to set.</param>
    void SetDE(uint16_t value);

    /// <summary>
    /// Gets the combined 16-bit HL register.
    /// </summary>
    uint16_t GetHL() const;

    /// <summary>
    /// Sets the combined 16-bit HL register.
    /// </summary>
    /// <param name="value">The 16-bit value to set.</param>
    void SetHL(uint16_t value);

    /// <summary>
    /// Gets the value of the accumulator register (A).
    /// </summary>
    uint8_t GetA() const;

    /// <summary>
    /// Sets the value of the accumulator register (A).
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetA(uint8_t value);

    /// <summary>
    /// Gets the value of the flags register (F).
    /// </summary>
    uint8_t GetF() const;

    /// <summary>
    /// Sets the value of the flags register (F).
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetF(uint8_t value);

    /// <summary>
    /// Gets the value of the B register.
    /// </summary>
    uint8_t GetB() const;

    /// <summary>
    /// Sets the value of the B register.
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetB(uint8_t value);

    /// <summary>
    /// Gets the value of the C register.
    /// </summary>
    uint8_t GetC() const;

    /// <summary>
    /// Sets the value of the C register.
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetC(uint8_t value);

    /// <summary>
    /// Gets the value of the D register.
    /// </summary>
    uint8_t GetD() const;

    /// <summary>
    /// Sets the value of the D register.
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetD(uint8_t value);

    /// <summary>
    /// Gets the value of the E register.
    /// </summary>
    uint8_t GetE() const;

    /// <summary>
    /// Sets the value of the E register.
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetE(uint8_t value);

    /// <summary>
    /// Gets the value of the H register.
    /// </summary>
    uint8_t GetH() const;

    /// <summary>
    /// Sets the value of the H register.
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetH(uint8_t value);

    /// <summary>
    /// Gets the value of the L register.
    /// </summary>
    uint8_t GetL() const;

    /// <summary>
    /// Sets the value of the L register.
    /// </summary>
    /// <param name="value">The 8-bit value to set.</param>
    void SetL(uint8_t value);

private:
	Memory& memory;
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

    /// <summary>
    /// Combines two 8-bit values into a single 16-bit register value.
    /// </summary>
    /// <param name="high">The high 8 bits of the register.</param>
    /// <param name="low">The low 8 bits of the register.</param>
    /// <returns>A 16-bit value formed by combining the high and low bytes.</returns>
    uint16_t GetCombinedRegister(uint8_t high, uint8_t low) const;

    /// <summary>
    /// Splits a 16-bit value into high and low 8-bit register values.
    /// </summary>
    /// <param name="value">The 16-bit value to be split.</param>
    /// <param name="high">Reference to the variable that will receive the high 8 bits.</param>
    /// <param name="low">Reference to the variable that will receive the low 8 bits.</param>
    void SetCombinedRegister(uint16_t value, uint8_t& high, uint8_t& low);
};
