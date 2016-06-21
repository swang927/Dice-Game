#include <gtest/gtest.h>
#include "dice.h"


class TestDice : public ::testing::Test{
  private:


  public:
  	TestDice();
  	~TestDice();

  	void SetUp();
  	void TearDown();


};

TEST_F( TestDice, something ){
	EXPECT_EQ( 1, 1 );
}