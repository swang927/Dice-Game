/*  test_game.h
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#include <gtest/gtest.h>
#include "game.h"


using namespace high5;

class TestGame : public ::testing::Test{
  public:
      Game my_game;
      std::set<int> myset;
      

      TestGame();
      ~TestGame();

      void SetUp();
      void TearDown();
};

