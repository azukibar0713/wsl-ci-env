#include <iostream>
#include <thread>
#include "my_thread.h"
#include "gtest/gtest.h"


namespace {
TEST(TestCaseMyThread, TestName){
    std::thread th1(ThreadFunc, 1);
    th1.join();
    EXPECT_EQ(1,1);

}
} // namespace


