#pragma once
#include <cstdint>

/// <summary>
/// Represents the CPU registers and flags of the Game Boy's Sharp LR35902 processor.
/// </summary>
class Cpu
{
public:
    /// <summary>
    /// Initializes all registers to zero.
    /// </summary>
    Cpu();

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
    uint8_t a;
    uint8_t f;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
};
