#include "common.h"
#include "simplify_path.h"
#include <gtest/gtest.h>

TEST(simplfily_path, test1){
	Solution s;
	EXPECT_EQ("/home", s.simplifyPath("/home/"));
	EXPECT_EQ("/c", s.simplifyPath("/a/./b/../../c/"));
	EXPECT_EQ("/", s.simplifyPath("/../"));
	EXPECT_EQ("/home/foo", s.simplifyPath("/home//foo/"));
	EXPECT_EQ("/home/foo", s.simplifyPath("/////home//foo/"));
	EXPECT_EQ("/.hidden", s.simplifyPath("/.hidden"));
	EXPECT_EQ("/", s.simplifyPath("/."));
	EXPECT_EQ("/", s.simplifyPath("///eHx/.."));
}
