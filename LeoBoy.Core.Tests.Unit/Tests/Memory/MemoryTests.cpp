#include "MemoryTestsFixture.h"

TEST_CASE_METHOD(MemoryTests, "[Memory]: All addresses are initialized to 0", "[memory]")
{
	// Arrange
	bool allZeroes = true;

	// Act
    for (uint16_t address = 0; address < Memory::MemoryImpl::MemorySize - 1; address++)
	{
		if (memory.Read(address) != 0)
		{
			allZeroes = false;
			break;
		}
	}

	// Assert
	REQUIRE(allZeroes == true);
}

TEST_CASE_METHOD(MemoryTests, "[Memory]: Writing to memory updates the value at the address", "[memory]")
{
	// Arrange
	uint16_t testAddress = 0x1234;
	uint8_t testValue = 0xAB;

	// Act
	memory.Write(testAddress, testValue);
	uint8_t readValue = memory.Read(testAddress);

	// Assert
	REQUIRE(readValue == testValue);
}