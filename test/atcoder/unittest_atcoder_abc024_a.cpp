#include <iostream>
#include <thread>

#include "gtest/gtest.h"

namespace {
class Abc024A {
 public:
  Abc024A(int children_fee, int adult_fee)
      : m_children_fee(children_fee),
        m_adult_fee(adult_fee),
        discount_free(50) {}

  int calc_sum(int children_num, int adult_num) {
    int ret = 0;
    ret += children_num * m_children_fee;
    ret += adult_num * m_adult_fee;
    int all_num = children_num + adult_num;
    if (all_num >= 20) ret -= (children_num + adult_num) * discount_free;
    return ret;
  }

 private:
  int m_children_fee;
  int m_adult_fee;
  const int discount_free;
};

class AtcoderAbc024A_CalculateFeeUnder20People : public ::testing::Test {
 protected:
  virtual void SetUp() { abc_024_a_ = new Abc024A(100, 200); };
  virtual void TearDown() { delete abc_024_a_; };

 public:
  Abc024A* abc_024_a_;
};

TEST_F(AtcoderAbc024A_CalculateFeeUnder20People, OnlyChildre) {
  EXPECT_EQ(300, abc_024_a_->calc_sum(3, 0));
}
TEST_F(AtcoderAbc024A_CalculateFeeUnder20People, OnlyAdult) {
  EXPECT_EQ(600, abc_024_a_->calc_sum(0, 3));
}
TEST_F(AtcoderAbc024A_CalculateFeeUnder20People, ChildrenAndAdult) {
  EXPECT_EQ(900, abc_024_a_->calc_sum(3, 3));
}

class AtcoderAbc024A_CalculateFeeOver20People : public ::testing::Test {
 protected:
  virtual void SetUp() { abc_024_a_ = new Abc024A(100, 200); };
  virtual void TearDown() { delete abc_024_a_; };

 public:
  Abc024A* abc_024_a_;
};

TEST_F(AtcoderAbc024A_CalculateFeeOver20People, OnlyChildren) {
  EXPECT_EQ(100 * 30 - 30 * 50, abc_024_a_->calc_sum(30, 0));
}
TEST_F(AtcoderAbc024A_CalculateFeeOver20People, OnlyAdult) {
  EXPECT_EQ(200 * 30 - 30 * 50, abc_024_a_->calc_sum(0, 30));
}
TEST_F(AtcoderAbc024A_CalculateFeeOver20People, ChildrenAndAdult) {
  EXPECT_EQ(100 * 30 + 200 * 30 - 50 * 60, abc_024_a_->calc_sum(30, 30));
}

}  // namespace