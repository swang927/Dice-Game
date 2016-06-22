/*  test_game.cpp
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#include "test_game.h"


TestGame::TestGame(){}

TestGame::~TestGame(){}

void TestGame::SetUp(){
   srand((int)time(NULL));
   int myints[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
		   53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107 };
   myset = std::set<int>(myints, myints + 29);
   my_game.setPrime(myset);
}

void TestGame::TearDown(){}


// Test case for setupGame() function
TEST_F(TestGame, test_setupGame_function){   
    my_game.setupGame();
    EXPECT_EQ(7, my_game.getSingledice());
    EXPECT_EQ(2, my_game.getTripledice());
    EXPECT_EQ(1, my_game.getQuintupledice());
    EXPECT_EQ(0, my_game.getTable().size());
}


// Test case for simulateGame() function for fixed dice amount
TEST_F(TestGame, test_simulatrGame_function_for_fixed_dice_amount){
	for(int i = 0; i < 100; ++i){
		my_game.setupGame();
    		int i_sinlge = my_game.getSingledice();
    		int i_triple = my_game.getTripledice();
    		int i_quintuple =  my_game.getQuintupledice();
    		int i_table = my_game.getTable().size();

   		my_game.simulateGame();

    		int c_sinlge = my_game.getSingledice();
    		int c_triple = my_game.getTripledice();
    		int c_quintuple =  my_game.getQuintupledice();
    		int c_table = my_game.getTable().size();

    		EXPECT_EQ(i_sinlge + i_triple + i_quintuple + i_table,
              		  c_sinlge + c_triple + c_quintuple + c_table);
	}  
}


// Test case for simulateGame() function for valid value
TEST_F(TestGame, test_simulatrGame_function_for_valid_value){  
    for(int i = 0; i < 10000000; ++i){
	my_game.setupGame();

    	int i_running_total_win = my_game.getTotalwin();
    	int i_running_total_bet =  my_game.getTotalbet();

    	my_game.simulateGame();

    	int c_win_amount = my_game.getWinamount();
    	int c_running_total_win = my_game.getTotalwin();
    	int c_running_total_bet =  my_game.getTotalbet();

    	EXPECT_EQ(17, c_running_total_bet-i_running_total_bet);
    	EXPECT_EQ(c_win_amount, c_running_total_win-i_running_total_win);
    	EXPECT_TRUE(myset.find(c_win_amount) != myset.end() );
   }
}
