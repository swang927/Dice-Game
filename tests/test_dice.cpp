/*  test_dice.cpp
 *  Author: Shaokang Wang
 *  6/21/2016
*/

#include "test_dice.h"

// my gtest class
TestDice::TestDice(){}

TestDice::~TestDice(){}

void TestDice::SetUp(){
   srand((int)time(NULL));
   int myints[] = {1,2,3,4,5,6};
   myset = std::set<int>(myints, myints + 6);
}

void TestDice::TearDown(){}


// Test case for throwDice() function for type 1 dice 
TEST_F( TestDice, test_throwDice_function_for_Type_1_Dice){  
    // type 1 dice possible result [1, 2, 3, 4, 5, 6] 
    mydice = Dice(DiceType::signle);
    for(int i = 0; i < 100; i++){
    	EXPECT_TRUE(myset.find(mydice.throwDice()) != myset.end());
    }
   
}

// Test case for throwDice() function for type 2 dice 
TEST_F( TestDice, test_throwDice_function_for_Type_2_Dice){  
    // type 2 dice possible result [3, 6, 9, 12, 15, 18] 
    mydice = Dice(DiceType::triple);
    for(int i = 0; i < 100; i++){
    	EXPECT_TRUE(myset.find(mydice.throwDice() / 3) != myset.end());
        EXPECT_EQ(0, mydice.throwDice() % 3);
    }
   
}

    
// Test case for throwDice() function for type 3 dice 
TEST_F( TestDice, test_throwDice_function_for_Type_3_Dice){  
    // type 3 dice possible result [5, 10, 15, 20, 25, 30] 
    mydice = Dice(DiceType::quintuple);
    for(int i = 0; i < 100; i++){
    	EXPECT_TRUE(myset.find(mydice.throwDice() / 5) != myset.end());
        EXPECT_EQ(0, mydice.throwDice() % 5);
    }
   
}


// Test case for getType() function for type 1 dice 
TEST_F( TestDice, test_getType_function_for_Type_1_Dice){  
    // type 1 dice should return single 
    mydice = Dice(DiceType::signle);
    EXPECT_EQ(DiceType::signle, mydice.getType());  
}

// Test case for getType() function for type 2 dice 
TEST_F( TestDice, test_getType_function_for_Type_2_Dice){  
    // type 2 dice should return single 
    mydice = Dice(DiceType::triple);
    EXPECT_EQ(DiceType::triple, mydice.getType());  
}

// Test case for getType() function for type 3 dice 
TEST_F( TestDice, test_getType_function_for_Type_3_Dice){  
    // type 3 dice should return single 
    mydice = Dice(DiceType::quintuple);
    EXPECT_EQ(DiceType::quintuple, mydice.getType());  
}




