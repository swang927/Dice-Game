/*  dice.cpp
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#include "dice.h"

namespace high5
{
	// default constructor :  
	Dice::Dice() : type(DiceType::signle){
	};

	// constructor
	Dice::Dice(DiceType d_type) : type(d_type){
	}

	// throw dice and get the value of Dice: 1 ~ 6
	int Dice::throwDice(){
		int r = (rand() % 6) + 1;
		switch (type){
		case DiceType::signle:
			return r;
		case DiceType::triple:
			return r * 3;
		case DiceType::quintuple:
			return  r * 5;
		default:
			return 0;
		}	
	}

	// get type of the Dice: single dice
	DiceType Dice::getType() const{
		return type;
	}

}
