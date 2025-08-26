#pragma once

#include <array>
#include <cstdint>
#include "IInstructionLookUp.h"
#include "IInstructionRegistrator.h"
#include "Instruction.h"
#include "Implementations/Unimplemented.h"
#include "Implementations/Nop/Nop.h"
#include "Implementations/Ld/Ld.h"

namespace Cpu
{
	namespace Instructions
	{
		/// <summary>
		/// Concrete implementation of the instruction lookup and registration system.
		/// </summary>
		/// <remarks>
		/// The following family of instructions are registered:
		///		- NOP: No Operation
		///		- LD: Load instructions
		/// </remarks>
		class InstructionLookUpImpl : public Cpu::Instructions::IInstructionLookUp, public Cpu::Instructions::IInstructionRegistrator
		{
		public:
			/// <summary>
			/// Initializes the instruction lookup table by registering all instruction implementations.
			/// </summary>
			InstructionLookUpImpl()
			{
				// Initialize all instructions to a default no-op to handle unimplemented opcodes gracefully
				for (uint16_t opcode = 0; opcode < 0x100; opcode++)
				{
					Implementations::Unimplemented(*this, static_cast<uint8_t>(opcode));
				}

				// NOP
				Implementations::Nop::Nop(*this);

				// LD
				Implementations::Ld::Ld_A_d8(*this);
				Implementations::Ld::Ld_A_HL(*this);
				Implementations::Ld::Ld_HL_A(*this);
				Implementations::Ld::Ld_HL_d16(*this);
			}

			void Register(uint8_t opcode, Instruction instruction) override
			{
				instructions[opcode] = instruction;
			}

			Instruction Get(uint8_t opcode) override
			{
				return instructions[opcode];
			}

		private:
			/// <summary>
			/// Array mapping opcodes (0x00 to 0xFF) to their corresponding instruction implementations.
			/// </summary>
			std::array<Instruction, 256> instructions;
		};
	}
}