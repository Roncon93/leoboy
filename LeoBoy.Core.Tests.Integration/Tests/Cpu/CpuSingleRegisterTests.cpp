#include "CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: All registers are initialized to 0", "[integration], [cpu]")
{
    // Act
    uint8_t a = cpu.GetA();
    uint8_t b = cpu.GetB();
    uint8_t c = cpu.GetC();
    uint8_t d = cpu.GetD();
    uint8_t e = cpu.GetE();
    uint8_t f = cpu.GetF();
    uint8_t h = cpu.GetH();
    uint8_t l = cpu.GetL();

    // Assert
    REQUIRE(a == zeroRegisterValue);
    REQUIRE(b == zeroRegisterValue);
    REQUIRE(c == zeroRegisterValue);
    REQUIRE(d == zeroRegisterValue);
    REQUIRE(e == zeroRegisterValue);
    REQUIRE(f == zeroRegisterValue);
    REQUIRE(h == zeroRegisterValue);
    REQUIRE(l == zeroRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register A can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetA(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetA() == testRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register B can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetB(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetB() == testRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register C can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetC(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetC() == testRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register D can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetD(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetD() == testRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register E can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetE(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetE() == testRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register F can be set and read", "[integration], [cpu]")
{
    // Arrange
    uint8_t expectedValue = 0x40;

    // Act
    cpu.SetF(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetF() == expectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register H can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetH(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetH() == testRegisterValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Register L can be set and read", "[integration], [cpu]")
{
    // Act
    cpu.SetL(testRegisterValue);

    // Assert
    REQUIRE(cpu.GetL() == testRegisterValue);
}