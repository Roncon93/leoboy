#pragma once

#include "ICpu.h"

namespace Cpu
{
	/// <summary>
	/// Interface for CPU operations that modify the CPU state (registers, program counter, etc).
	/// </summary>
	class IWriteCpu : public ICpu
	{
	public:
		/// <summary>
		/// Default virtual destructor.
		/// </summary>
		virtual ~IWriteCpu() = default;

		/// <summary>
		/// Retrieves the current program counter (PC) value and increments it by 1.
		/// </summary>
		/// <returns>The current value of the program counter before it is incremented.</returns>
		virtual uint16_t IncrementPc() = 0;

		/// <summary>
		/// Sets the combined 16-bit AF register.
		/// </summary>
		/// <param name="value">The 16-bit value to set.</param>
		virtual void SetAF(uint16_t value) = 0;

		/// <summary>
		/// Sets the combined 16-bit BC register.
		/// </summary>
		/// <param name="value">The 16-bit value to set.</param>
		virtual void SetBC(uint16_t value) = 0;

		/// <summary>
		/// Sets the combined 16-bit DE register.
		/// </summary>
		/// <param name="value">The 16-bit value to set.</param>
		virtual void SetDE(uint16_t value) = 0;

		/// <summary>
		/// Sets the combined 16-bit HL register.
		/// </summary>
		/// <param name="value">The 16-bit value to set.</param>
		virtual void SetHL(uint16_t value) = 0;

		/// <summary>
		/// Sets the value of the accumulator register (A).
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetA(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the flags register (F).
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetF(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the B register.
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetB(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the C register.
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetC(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the D register.
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetD(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the E register.
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetE(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the H register.
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetH(uint8_t value) = 0;

		/// <summary>
		/// Sets the value of the L register.
		/// </summary>
		/// <param name="value">The 8-bit value to set.</param>
		virtual void SetL(uint8_t value) = 0;

		/// <summary>
		/// Sets or clears the zero flag in the F register.
		/// </summary>
		/// <param name="isSet">True to set the flag, false to clear it.</param>
		virtual void SetZeroFlag(bool isSet) = 0;

		/// <summary>
		/// Sets or clears the substract flag in the F register.
		/// </summary>
		/// <param name="isSet">True to set the flag, false to clear it.</param>
		virtual void SetSubtractFlag(bool isSet) = 0;

		/// <summary>
		/// Sets or clears the half-carry flag in the F register.
		/// </summary>
		/// <param name="isSet">True to set the flag, false to clear it.</param>
		virtual void SetHalfCarryFlag(bool isSet) = 0;

		/// <summary>
		/// Sets or clears the carry flag in the F register.
		/// </summary>
		/// <param name="isSet">True to set the flag, false to clear it.</param>
		virtual void SetCarryFlag(bool isSet) = 0;
	};
}