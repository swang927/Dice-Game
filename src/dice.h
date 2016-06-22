/*  dice.h
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#ifndef INCLUDED_DICE
#define INCLUDED_DICE


#include <cstdlib>
#include <ctime>

namespace high5
{

// 3 type of dices
enum class DiceType{
    signle,   // x1
    triple,   // x3
    quintuple // x5 
};


class Dice {
  private:
    // record current dice type
    DiceType type;

  public:
    // default constructor
    Dice();
    // constructor
    Dice(DiceType dice_typy);

	
	// Utility funtions:
    // throw dice
    int throwDice();

	
	// Accessor:
    // get type of the Dice
    DiceType getType() const;
};

}

#endif