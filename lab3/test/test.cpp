#include <gtest/gtest.h>
#include "../include/word.hpp"

TEST(WordConstructor, DefaultConstructor)
{
    word::words tmp;
    ASSERT_EQ(0, tmp.get_count());
}

TEST(WordConstructor, WordConstructor)
{
    word::words tmp("Hi");
    ASSERT_EQ(1, tmp.get_count());
    ASSERT_STREQ("Hi", tmp.ret_word(0));
    ASSERT_ANY_THROW(word::words tmp_1("Toomanylenofthiswordsoitwillbedenied"));
}

TEST(WordConstructor, MassConstructor)
{
    char *mass[] = {"ABC", "HI", "HALLO", "PROST"};
    unsigned n = 4;
    word::words tmp(n, mass);
    ASSERT_EQ(4, tmp.get_count());
    ASSERT_STREQ("ABC", tmp.ret_word(0));
    ASSERT_STREQ("Hi", tmp.ret_word(1));
    ASSERT_STREQ("HALLO", tmp.ret_word(2));
    ASSERT_STREQ("PROST", tmp.ret_word(3));
}

TEST(WordConstructor, MassConstructor)
{
    char *mass[] = {"ABC", "HI", "HALLO", "PROST"};
    unsigned n = 4;
    word::words tmp(n, mass);
    ASSERT_EQ(4, tmp.get_count());
    ASSERT_STREQ("ABC", tmp.ret_word(0));
    ASSERT_STREQ("Hi", tmp.ret_word(1));
    ASSERT_STREQ("HALLO", tmp.ret_word(2));
    ASSERT_STREQ("PROST", tmp.ret_word(3));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}