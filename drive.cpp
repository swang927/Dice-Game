/* Drive class -- to run the dice game
 * Author: Shaokang Wang
 *  6/21/2016
*/

#include <iostream>
#include "game.h"
#include <vector>

// since the result will in range (1 ~ 108), 
// list all of the primes in this range
std::set<int> prime{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
					 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107 };

// main function
int main()
{
	// create dice game
	high5::Game dice_game(prime);

	// print game title
	dice_game.printTitle();


	// start the game loop
	while (true)
	{
		// set up the game
		dice_game.setupGame();
		
		// play the game 
		dice_game.simulateGame();
		
		// show result : one round of the game
		dice_game.displayGame();	
		
		// wait user input : press "Enter" key to start next round 
		dice_game.getKeyboardInput();
	}

	return 0;
};