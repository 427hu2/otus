#include "utils.h"

#include <gtest/gtest.h>

std::streambuf *SetMockCin(const std::istringstream &mock) {
    std::streambuf *old = std::cin.rdbuf();
    std::cin.rdbuf(mock.rdbuf());
    return old;
}

void RestoreOriginCin(std::streambuf *origin) {
    std::cin.rdbuf(origin);
}

// Demonstrate some basic assertions.
TEST(InputAndParse, ParseEmptyInput) {
    std::istringstream user_input("");
    std::streambuf *old_cin = SetMockCin(user_input);

    std::vector<std::string> res = input_command_line_data();

    EXPECT_EQ(res.size(), 0);

    RestoreOriginCin(old_cin);
}

TEST(InputAndParse, ParseValidOneLineInput) {
    std::istringstream user_input("12.12.32.43");
    std::streambuf *old_cin = SetMockCin(user_input);

    std::vector<std::string> res = input_command_line_data();

    EXPECT_EQ(res.size(), 1);

    RestoreOriginCin(old_cin);
}

TEST(InputAndParse, ParseValidMultiLineInput) {
    std::istringstream user_input(
        "12.12.32.43\n"
        "12.12.32.43");
    std::streambuf *old_cin = SetMockCin(user_input);

    std::vector<std::string> res = input_command_line_data();

    EXPECT_EQ(res.size(), 2);

    RestoreOriginCin(old_cin);
}

TEST(SeparateAndConver, ConverOneValue) {
    const std::vector<std::string> v = {"0.1.2.3"};
    std::vector<std::vector<int> > s = separate_and_convert_to_int(v);

    EXPECT_EQ(s.size(), 1);
    EXPECT_EQ(s[0].size(), 4);

    for (int i = 0; i < s[0].size(); i++) {
        EXPECT_EQ(s[0][i], i);
    }
}