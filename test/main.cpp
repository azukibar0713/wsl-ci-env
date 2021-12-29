#include "gtest/gtest.h"

bool is_even(const int x) {
    if(x%2) {
        return false;
    }
    else{
        return true;
    }
}
TEST(TestCaseName, TestName){
    EXPECT_EQ(1, 1);
}

TEST(MainFile, IS_EVEN){
    EXPECT_EQ(true, is_even(10));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


