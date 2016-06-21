#include <gtest/gtest.h>
#include "game.h"


class TestGame : public ::testing::Test{
  private:


  public:
  	TestGame();
  	~TestGame();

  	void SetUp();
  	void TearDown();


};

TEST_F( TestGame, something ){
	EXPECT_EQ( 1, 1 );
}