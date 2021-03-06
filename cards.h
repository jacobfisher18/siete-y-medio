/* *************************************
 Ricardo Salazar, February 26, 2015
 
 Interface of a simple Card class
 ************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

/* The values for this type start at 0 and increase by one afterwards until they get to SIETE.
 The rank reported by the function Card::get_rank() below is the value listed here plus one. */
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Card {
public:
    Card(); // Constructor assigns random rank & suit to card.
    
    // Accessors
    string get_spanish_suit() const;
    string get_spanish_rank() const;
    string get_english_suit() const;
    string get_english_rank() const;
    
    int get_rank() const; // Converts card rank to number. Possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
    
    double get_value() const;
    
    bool operator < (Card card2) const; // Compare rank of two cards. E.g: Eight<Jack is true. Assume Ace is always 1.
    
    void print() const;
    
private:
    suit_t suit;
    rank_t rank;
};


class Hand {
public:
    //default constructor automatically generated
    
    void addCard(Card c);
    void printCards() const;
    double get_total() const;
    bool bust() const; //returns true if the hand totals over 7.5
private:
    vector<Card> cards;
};


class Player {
public:
    Player(int m); //Assigns initial amount of money
    
    int get_money() const; //returns the amount of money the player has
    void gain(int money_to_gain);
    void lose(const int money_to_lose);
private:
    int money;
};

#endif
