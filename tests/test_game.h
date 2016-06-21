/*  test_game.h
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#include <gtest/gtest.h>
#include "game.h"


using namespace high5;

class TestGame : public ::testing::Test{
  public:
      Dice my_game;


      TestGame();
      ~TestGame();

      void SetUp();
      void TearDown();
};

