#include <gtest/gtest.h>
#include "headers/romanos.hpp"

TEST(Validations, ShouldReturnNegative_WhenStringIsBiggerThan30Chars)
{
  // length: 34
  int value = RomanNumbers::GetValue("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
  ASSERT_LT(value, 0);
  // length: 31
  value = RomanNumbers::GetValue("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
  ASSERT_LT(value, 0);
  // length: 30
  value = RomanNumbers::GetValue("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
  ASSERT_GE(value, 0);
  // length: 20
  value = RomanNumbers::GetValue("MMMMMMMMMMMMMMMMMMMM");
  ASSERT_GE(value, 0);
}

TEST(Validations, ShouldReturnNegative_WhenANumeralIsUnknown)
{
  int value = RomanNumbers::GetValue("A");
  ASSERT_LT(value, 0);
  value = RomanNumbers::GetValue("XXIB");
  ASSERT_LT(value, 0);
  value = RomanNumbers::GetValue("DXXI");
  ASSERT_GE(value, 0);
  value = RomanNumbers::GetValue("MDCLXI");
  ASSERT_GE(value, 0);
}

TEST(RomanNumbersConversion, ShouldReturnNumeralValue_WhenNumberIsOneNumeralOnly)
{
  int value = RomanNumbers::GetValue("M");
  ASSERT_EQ(value, M);
  value = RomanNumbers::GetValue("D");
  ASSERT_EQ(value, D);
  value = RomanNumbers::GetValue("C");
  ASSERT_EQ(value, C);
  value = RomanNumbers::GetValue("L");
  ASSERT_EQ(value, L);
  value = RomanNumbers::GetValue("X");
  ASSERT_EQ(value, X);
  value = RomanNumbers::GetValue("V");
  ASSERT_EQ(value, V);
  value = RomanNumbers::GetValue("I");
  ASSERT_EQ(value, I);
}

TEST(RomanNumbersConversion, ShouldReturnNumeralValue_WhenStringIsValid)
{
  int value = RomanNumbers::GetValue("MCI");
  ASSERT_EQ(value, M + C + I);
  value = RomanNumbers::GetValue("MXCI");
  ASSERT_EQ(value, 1091);
  value = RomanNumbers::GetValue("XXIX");
  ASSERT_EQ(value, 29);
  value = RomanNumbers::GetValue("CCCLXXIII");
  ASSERT_EQ(value, 373);
  value = RomanNumbers::GetValue("DCLXXX");
  ASSERT_EQ(value, 680);
}

int main()
{
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}