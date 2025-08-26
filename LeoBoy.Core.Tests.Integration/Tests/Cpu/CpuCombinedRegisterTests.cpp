#include "CpuTestsFixture.h"

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers A and F combined read test", "[cpu]")
{
    // Arrange
    cpu.SetA(0x12);
    cpu.SetF(0x34);

    uint16_t expectedValue = 0x1230;

    // Act
    uint16_t result = cpu.GetAF();

    // Assert
    REQUIRE(result == expectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers A and F combined write test", "[cpu]")
{
    // Arrange
    uint16_t testValue = 0x5678;
    uint8_t expectedRegisterAValue = 0x56;
    uint8_t expectedRegisterFValue = 0x70;

    // Act
    cpu.SetAF(testValue);
    uint8_t resultA = cpu.GetA();
    uint8_t resultF = cpu.GetF();

    // Assert
    REQUIRE(resultA == expectedRegisterAValue);
    REQUIRE(resultF == expectedRegisterFValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers B and C combined read test", "[cpu]")
{
    // Arrange
    cpu.SetB(0x12);
    cpu.SetC(0x34);

    uint16_t expectedValue = 0x1234;

    // Act
    uint16_t result = cpu.GetBC();

    // Assert
    REQUIRE(result == expectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers B and C combined write test", "[cpu]")
{
    // Arrange
    uint16_t testValue = 0x5678;
    uint8_t expectedRegisterBValue = 0x56;
    uint8_t expectedRegisterCValue = 0x78;

    // Act
    cpu.SetBC(testValue);
    uint8_t resultB = cpu.GetB();
    uint8_t resultC = cpu.GetC();

    // Assert
    REQUIRE(resultB == expectedRegisterBValue);
    REQUIRE(resultC == expectedRegisterCValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers D and E combined write test", "[cpu]")
{
    // Arrange
    uint16_t testValue = 0x5678;
    uint8_t expectedRegisterDValue = 0x56;
    uint8_t expectedRegisterEValue = 0x78;

    // Act
    cpu.SetDE(testValue);
    uint8_t resultD = cpu.GetD();
    uint8_t resultE = cpu.GetE();

    // Assert
    REQUIRE(resultD == expectedRegisterDValue);
    REQUIRE(resultE == expectedRegisterEValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers D and E combined read test", "[cpu]")
{
    // Arrange
    cpu.SetD(0x12);
    cpu.SetE(0x34);

    uint16_t expectedValue = 0x1234;

    // Act
    uint16_t result = cpu.GetDE();

    // Assert
    REQUIRE(result == expectedValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers H and L combined write test", "[cpu]")
{
    // Arrange
    uint16_t testValue = 0x5678;
    uint8_t expectedRegisterHValue = 0x56;
    uint8_t expectedRegisterLValue = 0x78;

    // Act
    cpu.SetHL(testValue);
    uint8_t resultH = cpu.GetH();
    uint8_t resultL = cpu.GetL();

    // Assert
    REQUIRE(resultH == expectedRegisterHValue);
    REQUIRE(resultL == expectedRegisterLValue);
}

TEST_CASE_METHOD(CpuTests, "[CPU]: Registers H and L combined read test", "[cpu]")
{
    // Arrange
    cpu.SetH(0x12);
    cpu.SetL(0x34);

    uint16_t expectedValue = 0x1234;

    // Act
    uint16_t result = cpu.GetHL();

    // Assert
    REQUIRE(result == expectedValue);
}