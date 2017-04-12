#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

/*
 Potential To-Do:
 1. End the game when the dealer has lost $900
 2. Input validation for betting amounts
 3. Write the companion log in gamelog.txt
 4. Improve the README
 5. Create an experimental branch and then merge it
 */

// Global constants
const int STARTING_MONEY = 100; //amount of money with which the player starts
const double DEALER_THRESHOLD = 5.5; //the total hand value at which the dealer will stop drawing another card

int main(){
    Player myPlayer = Player(STARTING_MONEY);
    
    string again = "y";
    
    //keep going while the player still has money and they reply "y" to keep playing
    while ((myPlayer.get_money() > 0) && (again == "y")) {
        
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
        
        while (another == "y") {
            Card newCard = Card();
            playerHand.addCard(newCard); //draw a random card for the player
            cout << "New card:" << endl;
            newCard.print();
            
            cout << "Your cards: " << endl;
            playerHand.printCards();
            
            cout << "Your total is " << playerHand.get_total() << ". Do you want another card (y/n)? ";
            cin >> another;
        }
        
        Hand dealerHand = Hand();
        dealerHand.addCard(Card()); //draw a random card for the dealer
        
        cout << "Dealer's cards: " << endl;
        dealerHand.printCards();
        
        cout << "The dealer's total is " << dealerHand.get_total() << endl;
        
        while (dealerHand.get_total() < DEALER_THRESHOLD) {
            Card newCard = Card();
            dealerHand.addCard(newCard); //draw a random card for the dealer
            cout << "New card:" << endl;
            newCard.print();
            
            cout << "Dealer's cards: " << endl;
            dealerHand.printCards();
            
            cout << "The dealer's total is " << dealerHand.get_total() << endl;
        }
        
        if (playerHand.bust()) {
            //the player busted; dealer won
            cout << "Too bad. You lose $" << bet << endl;
            myPlayer.lose(bet);
        }
        
        else if (dealerHand.bust()) {
            //dealer busted and player didn't; player won
            cout << "Nice! You win $" << bet << endl;
            myPlayer.gain(bet);
        }
        
        else if (playerHand.get_total() == dealerHand.get_total()) {
            //tie
            cout << "Tie. You don't gain or lose any money." << endl;
        }
        
        else if (playerHand.get_total() < dealerHand.get_total()) {
            //dealer outscored player; dealer won
            cout << "Too bad. You lose $" << bet << endl;
            myPlayer.lose(bet);
        }
        
        else if (playerHand.get_total() > dealerHand.get_total()) {
            //player outscored dealer; player won
            cout << "Nice! You win $" << bet << endl;
            myPlayer.gain(bet);
        }
        
        else {
            //error
            cout << "Error in programming logic!" << endl;
            std::exit(0);
        }
        
        cout << "Play again (y/n)?";
        cin >> again;
    }
    
    return 0;
}
