#pragma once

#include "../../../../../Libraries/fakeit.hpp"
#include "../../InstructionTestsFixture.h"

class IncTestsFixture : public InstructionTests
{
public:
	IncTestsFixture() : InstructionTests()
	{
		fakeit::Fake(Method(mockCpu, SetA));
		fakeit::Fake(Method(mockCpu, SetZeroFlag));
		fakeit::Fake(Method(mockCpu, SetSubtractFlag));
		fakeit::Fake(Method(mockCpu, SetHalfCarryFlag));
		fakeit::Fake(Method(mockCpu, SetCarryFlag));
	}
};