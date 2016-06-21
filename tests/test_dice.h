/*  test_dice.h
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#include <gtest/gtest.h>
#include "dice.h"

using namespace high5;

// my gtest class
class TestDice : public ::testing::Test{ 
  public:
        Dice mydice;
	std::set<int> myset;

  	TestDice();
  	~TestDice();

  	void SetUp();
  	void TearDown();
};

