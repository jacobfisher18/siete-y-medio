#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants
const int STARTING_MONEY = 100;

// Non member functions declarations (if any)
// Non member functions implementations (if any)

int main(){
    Player myPlayer = Player(STARTING_MONEY);
    
    //keep going while the player still has money
    while (myPlayer.get_money() > 0) {
        
        int bet;
        cout << "You have $" << myPlayer.get_money() << ". Enter bet: ";
        cin >> bet;
        
        Hand playerHand = Hand();
        playerHand.addCard(Card()); //draw a random card for the player
        
        cout << "Your cards: " << endl;
        playerHand.printCards();
        
        string another;
        cout << "Your total is " << playerHand.get_total() << ". Do you want another card (y/n)? ";
        cin >> another;
    }
    
    return 0;
}
