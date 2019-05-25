/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* deck.cpp
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#include "card.h"
#include "deck.h"

using namespace std;

Deck::Deck() {

    // array values from 1 - 52
    for (int i=0; i<DECK_SIZE; i++) {
       m_deck[i]=i+1; 
    }

}

Deck::~Deck(){}

// a simple way to view the deck for testing
void Deck::showDeck() const {

    for (int i=0; i<DECK_SIZE; i++) {
        cout << m_deck[i] << ", ";
    }

    cout << endl;

}

void Deck::shuffle() {
    const int SHUFFLE_MAX=5; // run through the deck this many times
    int shuffle=0;

    do {
        for (int i=0; i<DECK_SIZE; i++) {
            int r=rand() % 52;
            int temp=m_deck[i];
            m_deck[i]=m_deck[r];
            m_deck[r]=temp;
            shuffle++;
        }
    } while (shuffle<SHUFFLE_MAX);

}

Card Deck::dealCard() {
    int card=m_deck[m_numDealt]; // numDealt tells us which card to deal
    m_deck[m_numDealt]=0; // once dealt, set it's location to 0
    m_numDealt++; // increment numDealt for next time
    return Card(card);
}

int Deck::numDealt() {
    return m_numDealt;
}

