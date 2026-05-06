#include <gtest/gtest.h>
#include <sstream>
#include "rational.hpp"

TEST(RationalTest, InputOutput) {
    std::istringstream input("2/5");
    Rational r1;
    input >> r1;
    EXPECT_EQ(r1.get_numerator(), 2);
    EXPECT_EQ(r1.get_denominator(), 5);

    Rational r2(3, 4);
    std::ostringstream output;
    output << r2;
    EXPECT_EQ(output.str(), "3/4");
}

TEST(RationalTest, ConstructorAndNormalization) 
{
    Rational r1;
    EXPECT_EQ(r1.get_numerator(), 0);
    EXPECT_EQ(r1.get_denominator(), 1);

    Rational r2(10,6);
    EXPECT_EQ(r2.get_numerator(), 5);
    EXPECT_EQ(r2.get_denominator(), 3);
}

TEST(RationalTest, CompoundOperator) {
    Rational r1(2,5);
    EXPECT_EQ(r1.get_numerator(), 2);
    EXPECT_EQ(r1.get_denominator(), 5);

    Rational r2(10, 6);
    EXPECT_EQ(r2.get_numerator(), 5);
    EXPECT_EQ(r2.get_denominator(), 3);

    r1 *= r2;
    EXPECT_EQ(r1.get_numerator(), 2);
    EXPECT_EQ(r1.get_denominator(), 3);

    r2 += 2;
    EXPECT_EQ(r2.get_numerator(), 11);
    EXPECT_EQ(r2.get_denominator(), 3);

    r2 -= 1;
    EXPECT_EQ(r2.get_numerator(), 8);
    EXPECT_EQ(r2.get_denominator(), 3);

    r2 /= r1;
    EXPECT_EQ(r2.get_numerator(), 4);
    EXPECT_EQ(r2.get_denominator(), 1);
}

TEST(RationalTest, UnaryOperator) {
    Rational r1(2,5);
    EXPECT_EQ(r1.get_numerator(), 2);
    EXPECT_EQ(r1.get_denominator(), 5);

    Rational r2 = -r1;
    EXPECT_EQ(r2.get_numerator(), -2);
    EXPECT_EQ(r2.get_denominator(), 5);

    r2 = +r1;
    EXPECT_EQ(r2.get_numerator(), 2);
    EXPECT_EQ(r2.get_denominator(), 5);
}

TEST(RationalTest, BinaryOperator) {
    Rational r1(2, 5);
    EXPECT_EQ(r1.get_numerator(), 2);
    EXPECT_EQ(r1.get_denominator(), 5);

    Rational r2 = r1 + 2;
    EXPECT_EQ(r2.get_numerator(), 12);
    EXPECT_EQ(r2.get_denominator(), 5);

    r2 = r1 - 1;
    EXPECT_EQ(r2.get_numerator(), -3);
    EXPECT_EQ(r2.get_denominator(), 5);

    r2 = r1 * 2;
    EXPECT_EQ(r2.get_numerator(), 4);
    EXPECT_EQ(r2.get_denominator(), 5);

    r2 = r2 / 4;
    EXPECT_EQ(r2.get_numerator(), 1);
    EXPECT_EQ(r2.get_denominator(), 5);
}

TEST(RationalTest, ComparisonOperator) {
    Rational r1(2, 5);
    EXPECT_EQ(r1.get_numerator(), 2);
    EXPECT_EQ(r1.get_denominator(), 5);

    Rational r2(4,5);
    EXPECT_EQ(r2.get_numerator(), 4);
    EXPECT_EQ(r2.get_denominator(), 5);

    bool status = (r1 == r2);
    EXPECT_EQ(status, false);

    status = (r1 != r2);
    EXPECT_EQ(status, true);

    status = (r1 < r2);
    EXPECT_EQ(status, true);

    status = (r1 <= r2);
    EXPECT_EQ(status, true);

    status = (r1 > r2);
    EXPECT_EQ(status, false);

    status = (r1 >= r2);
    EXPECT_EQ(status, false);
}
