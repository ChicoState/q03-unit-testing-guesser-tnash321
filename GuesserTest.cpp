/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, match_test_match)
{
	Guesser test = Guesser("Hello");
    ASSERT_EQ(1, test.match("Hello"));
}

TEST(GuesserTest, match_test_one_greater)
{
	Guesser test = Guesser("Hello");
    ASSERT_EQ(1, test.match("Hello!"));
}

TEST(GuesserTest, match_test_one_off)
{
	Guesser test = Guesser("Hello");
    ASSERT_EQ(1, test.match("hello"));
}

TEST(GuesserTest, match_test_three_off)
{
	Guesser test = Guesser("Hello");
    ASSERT_EQ(0, test.match("Helloooo"));
}

TEST(GuesserTest, remaining_test_full)
{
	Guesser test = Guesser("Hello");
    ASSERT_EQ(3, test.remaining());
}

TEST(GuesserTest, remaining_test_one_fail)
{
	Guesser test = Guesser("Hello");
	test.match("hello");
    ASSERT_EQ(2, test.remaining());
}

TEST(GuesserTest, remaining_test_way_off)
{
	Guesser test = Guesser("Hello");
	test.match("helloooo");
    ASSERT_EQ(0, test.remaining());
}

TEST(GuesserTest, remaining_test_two_fail)
{
	Guesser test = Guesser("Birdy");
	test.match("Birdi");
	test.match("birdy");
    ASSERT_EQ(1, test.remaining());
}

TEST(GuesserTest, remaining_test_way_off_plus_one)
{
	Guesser test = Guesser("Birdy");
	test.match("Birdiiiiii");
	test.match("birdy");
    ASSERT_EQ(0, test.remaining());
}

TEST(GuesserTest, remaining_test_three_fail)
{
	Guesser test = Guesser("Duo-Mobile");
	test.match("duo-mobile");
	test.match("Duo-Mobiles");
	test.match("Duo-Mobily");
    ASSERT_EQ(0, test.remaining());
}