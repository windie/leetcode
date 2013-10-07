#include "common.h"
#include "remove_Element.h"
#include <gtest/gtest.h>

TEST(remove_Element, removeElement) {
  Solution s;
  int a[]  = {1, 2, 4, 5, 2};
  EXPECT_EQ(3, s.removeElement(a, 5, 2));
  EXPECT_EQ(4, s.removeElement(a, 5, 1));
}
