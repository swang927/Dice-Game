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

	
	
	
	// Utility funtions:
    // throw dice and get the value of Dice
    int Dice::throwDice(){
        int r = (rand() % 6) + 1;
        // base on different type of dice return different value
        switch (type){
        // Type 1 dice : x 1
        case DiceType::signle:
            return r;
            // Type 2 dice : x 3
        case DiceType::triple:
            return r * 3;
        // Type 3 dice : x 5
        case DiceType::quintuple:
            return  r * 5;
        default:
            return 0;
        }    
    }

	
	
	
	// Accessor:
    // get type of the Dice: single dice
    DiceType Dice::getType() const{
        return type;
    }

}
