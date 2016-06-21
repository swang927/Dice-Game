/*  game.h
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include <iostream>
#include <vector>
#include <set>
#include "dice.h"

namespace high5
{
// class to simulate the dice game
class Game{
  private:
	  /*  record prime numbers in range (1~108) to check
	   *  if the sum is a prime number, the game ends and 
	   *  the prime number is the prize. 
	   */
	  std::set<int> prime;
	  // record the value of dices on table
	  std::vector<int> table;
	  
	  // record the number of type 1 dice left in bag
	  int single_dice;
	  // record the number of type 2 dice left in bag
	  int triple_dice;
	  // record the number of type 3 deic left in bag
	  int quintuple_dice;

	  // record the win amount for one round
	  int win_amount;
	  // record the total win amount for all rounds so far
	  unsigned long running_total_win;
	  // record the total bet amount for all rounds so far
	  unsigned long running_total_bet;

	  // random take a dice from the bag
	  Dice takeDice();

  public:
	  // default constructor
	  Game();
	  // constructor
	  Game(std::set<int> prime_set);

	  // print game title
	  void printTitle();
	  
	  // show result : one round of the game
      void displayGame();

	  // wait user input : press "Enter" key to start next round 
	  void getKeyboardInput();

	  // set up the game
	  void setupGame();

	  // playe the game 
	  void simulateGame();

	  // Accessor:
	  // set prime number checklist
	  void setPrime(std::set<int> prime_list);
};
}

#endif