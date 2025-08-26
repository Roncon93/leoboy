#pragma once

#include <cstdint>

namespace Cpu
{
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
    class ICpu
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
        /// Default virtual destructor.
        /// </summary>
        virtual ~ICpu() = default;

        /// <summary>
        /// Fetches the next opcode from memory and increments PC.
        /// </summary>
        virtual uint8_t Fetch() = 0;

        /// <summary>
        /// Decodes and executes a single CPU instruction.
        /// </summary>
        /// <param name="opcode">The opcode byte fetched from memory.</param>
        virtual void Execute(uint8_t opcode) = 0;

        /// <summary>
        /// Runs one CPU instruction cycle: fetch, decode, and execute.
        /// </summary>
        virtual void Step() = 0;

		/// <summary>
		/// Gets the current value of the Program Counter (PC).
		/// </summary>
        virtual const uint16_t GetPc() = 0;

        /// <summary>
        /// Gets the combined 16-bit AF register.
        /// </summary>
        /// <returns>The 16-bit AF register value.</returns>
        virtual const uint16_t GetAF() = 0;

        /// <summary>
        /// Gets the combined 16-bit BC register.
        /// </summary>
        virtual const uint16_t GetBC() = 0;

        /// <summary>
        /// Gets the combined 16-bit DE register.
        /// </summary>
        virtual const uint16_t GetDE() = 0;

        /// <summary>
        /// Gets the combined 16-bit HL register.
        /// </summary>
        virtual const uint16_t GetHL() = 0;

        /// <summary>
        /// Gets the value of the accumulator register (A).
        /// </summary>
        virtual const uint8_t GetA() = 0;

        /// <summary>
        /// Gets the value of the flags register (F).
        /// </summary>
        virtual const uint8_t GetF() = 0;

        /// <summary>
        /// Gets the value of the B register.
        /// </summary>
        virtual const uint8_t GetB() = 0;

        /// <summary>
        /// Gets the value of the C register.
        /// </summary>
        virtual const uint8_t GetC() = 0;

        /// <summary>
        /// Gets the value of the D register.
        /// </summary>
        virtual const uint8_t GetD() = 0;

        /// <summary>
        /// Gets the value of the E register.
        /// </summary>
        virtual const uint8_t GetE() = 0;

        /// <summary>
        /// Gets the value of the H register.
        /// </summary>
        virtual const uint8_t GetH() = 0;

        /// <summary>
        /// Gets the value of the L register.
        /// </summary>
        virtual const uint8_t GetL() = 0;
    };
}
