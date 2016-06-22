/*  game.cpp
 *  Author: Shaokang Wang
 * 6/21/2016
*/

#include "game.h"

namespace high5
{

// default constructor
Game::Game(){};

// constructor
Game::Game(std::set<int> prime_set) 
    : prime(prime_set), 
    running_total_win(0),
    running_total_bet(0)
{
    // Seed the random-number generator with current time 
    srand((int)time(NULL));
}




// Utility funtions:
// random take a dice from the bag
Dice Game::takeDice(){
    // get one dice from bag and put on table
    // get total number of dice left in bag
    int total_dice = single_dice + triple_dice + quintuple_dice;
    // random pick a number as identifier of a dice in bag
    int selected_dice = (rand() % total_dice) + 1;

    // selected dice is single dice, in range:: [ 1 , single_dice]
    if (selected_dice <= single_dice){
        --single_dice;
        return Dice(DiceType::signle);
    }

    // selected dice is triple dice, in range:: ( single_dice , triple_dice ] 
    else if (selected_dice <= single_dice + triple_dice){
        --triple_dice;
        return Dice(DiceType::triple);
    }

    // selected dice is quintuple dice, in range:: ( triple_dice , quintuple_dice] 
    else {
        --quintuple_dice;
        return Dice(DiceType::quintuple);
    }
}


// get keyboard input
void Game::getKeyboardInput(){
    std::cin.get();
}


// updata the game status
void Game::setupGame()
{
    // clear previous data
    table.clear();
    // set new data
    single_dice = 7;
    triple_dice = 2;
    quintuple_dice = 1;
}


// simulate one round 
void Game::simulateGame(){
    // refresh RunningTotalWin to record a new round 
    win_amount = 0;

    // go through all the dices until the sum is a prime number,
    // then the prime number is the prize.
    // 10 dice are rolled and the sum is not prime,
    // then the game ends and the prize is 0.
    while (table.size() < 10 && prime.find(win_amount) == prime.end()){
        int value = takeDice().throwDice();
        table.push_back(value);
        win_amount += value;
    }
    if (table.size() == 10 && prime.find(win_amount) == prime.end()){
        win_amount = 0;
    }
    running_total_win += win_amount;
    running_total_bet += 17;
}


// display game result 
void Game::displayGame(){
    for (unsigned int i = 0; i < 10; i++){
        if (i < table.size()){
            std::cout << table[i] << "\t";
        }
        else{
            std::cout << " \t";
        }
    }

    // show the WinAmount
    std::cout << win_amount << "\t\t";

    // show the RunningTotalWin
    std::cout << running_total_win << "\t\t\t";

    // show the RunningTotalBet
    std::cout << running_total_bet << std::endl;
}


// print game title
void Game::printTitle(){
    std::cout << "High 5 Dice Game : \n\n";
    std::cout << "die1 \tdie2 \tdie3 \tdie4 \tdie5" <<
        " \tdie6 \tdie7 \tdie8 \tdie9 \t" <<
        "die10 \tWinAmount \tRunningTotalWin \t" <<
        "RunningTotalBet\n";
    std::cout << "________________________________________________" <<
                 "________________________________________________" <<
                 "_______________________________________" << std::endl;
}





// Accessor:
// set prime number checklist
void Game::setPrime(std::set<int> prime_list){
    prime = prime_list;
}


// get table 
std::vector<int> Game::getTable(){
    return table;
}


// get number of single dice left in bag 
int Game::getSingledice(){
    return single_dice;
}


// get number of triple dice left in bag
int Game::getTripledice(){
    return triple_dice;
}


// get number of quintuple dice left in bag 
int Game::getQuintupledice(){
    return quintuple_dice;
}


// get win amount for one round
int Game::getWinamount(){
    return win_amount;
}


// get total win amount so far 
unsigned long Game::getTotalwin(){
    return running_total_win;
}


// get total bet amount so far 
unsigned long Game::getTotalbet(){
    return running_total_bet;
}

}
