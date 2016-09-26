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

TEST(FieldTest, getOnMine)
{
	Field minefield;
   minefield.placeMine(2,3);

	ASSERT_EQ(MINE_HIDDEN, minefield.get(2,3));
}

TEST(FieldTest, getOnNoMine)
{
	Field minefield;

	ASSERT_EQ(EMPTY_HIDDEN, minefield.get(2,3));
}

TEST(FieldTest, getOnException)
{
	Field minefield;
  
   throw std::invalid_argument("Out of bounds");

   ASSERT_THROW(minefield.get(-1,0), std::invalid_argument);
}

TEST(FieldTest, revealAdj) {
   Field minefield;
   minefield.placeMine(4,5);
   minefield.revealAdjacent(4,6);
   ASSERT_EQ(EMPTY_SHOWN, minefield.get(4,7));
}

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ(MINE_HIDDEN, minefield.get(4,5));
}
