/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, isSafeMineExists)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ(false, minefield.isSafe(4,5));
}

TEST(FieldTest, isSafeMineDoesntExist)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ(true, minefield.isSafe(4,4));
}

TEST(FieldTest, isSafeOutOfBounds)
{
	Field minefield;

	ASSERT_EQ(false, minefield.isSafe(10,-1));
}

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ(MINE_HIDDEN, minefield.get(4,5));
}
