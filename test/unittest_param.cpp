#include <iostream>
#include <thread>
#include "gtest/gtest.h"

// https://s15silvia.blog.ss-blog.jp/2013-05-12

namespace {

bool IsEven(int n) {
    return (n%2) == 0;
}
class ParamTestInt : public ::testing::TestWithParam<int> {};
TEST_P(ParamTestInt, IsEvenTest) {
    EXPECT_TRUE(IsEven(GetParam()));
}
INSTANTIATE_TEST_CASE_P(
    TestDataIntRange,
    ParamTestInt,
    ::testing::Range(0, 10, 2));
INSTANTIATE_TEST_CASE_P(
    TestDataIntValues,
    ParamTestInt,
    ::testing::Values(0, 2, 4, 6, 8));


struct TestData {
    int n;
    bool expected;
} test_data[] = {
    { 21, false, },
    { 22, true,  },
};

class ParamTestStruct : public ::testing::TestWithParam<TestData>
{};

TEST_P(ParamTestStruct, IsEvenTest)
{
    const int n = GetParam().n;
    const bool expected = GetParam().expected;

    EXPECT_EQ(expected, IsEven(n));
}

INSTANTIATE_TEST_CASE_P(
    TestDataSturct,
    ParamTestStruct,
    ::testing::ValuesIn(test_data)
);


} // namespace
