/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* cribbage.cpp
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"
#include "card.h"
#include "deck.h"
#include "score.h"
#include "cribbage.h"

using namespace std;

Cribbage::Cribbage() {}

Cribbage::~Cribbage() {}

void Cribbage::play() {

    m_deck.shuffle();

    welcome();

    while (keepPlaying) {
            dealHand();
            showHand();
            showCrib(0);
            discardTwo();
            turnStarter();
            showHand();
            showCrib(1);
            scoreRound();
            keepPlaying=checkPlay();
     }
}

// possibly add options for user to display rules, etc
void Cribbage::welcome() const {
    cout << "\n................................................................" << endl;
    cout << "NOTE: COUNTS FOR 15s AND RUNS CURRENTLY UNAVAILABLE" << endl;
    cout << "Welcome to Cribbage Solitaire..." << endl;
    cout << "..." << endl;
}

void Cribbage::dealHand() {

    m_round++; // keep track of the round

    int i;
    int j;

    // deal 3 cards to player
    for (i=0; i<3; i++) {
        m_hand.push_back(m_deck.dealCard());
    }

    // deal 2 cards to crib
    for (j=0; j<2; j++) {
        m_crib.push_back(m_deck.dealCard());
    }

    // deal 3 more cards to player
    for (i=3; i<6; i++) {
        m_hand.push_back(m_deck.dealCard());
    }
    
    // sort hand
    sort(m_hand.begin(),m_hand.end());

}

void Cribbage::showHand() const { // display players hand

    cout << "Your hand..." << endl;

    for (int i=0; i<m_hand.size(); i++) {
        cout << i+1 << ". ";
        m_hand.at(i).showCard(1);
    }

    cout << "..." << endl;

}

void Cribbage::discardTwo() { // throw two cards into crib

    int x;
    int y;

    cout << "Choose a card to send to your crib." << endl;

    do {    
        cout << "First card: ";
        cin >> x;
    } while (x<=0 || x>m_hand.size());

    m_crib.push_back(m_hand.at(x-1)); // add to crib
    m_hand.erase(m_hand.begin()+(x-1)); // remove from hand

    cout << "..." << endl;

    showHand();
    showCrib(0);

    cout << "Choose another card to send to your crib." << endl;
    
    do {
        cout << "Second card: ";
        cin >> y;
    } while (y<=0 || y>m_hand.size());

    m_crib.push_back(m_hand.at(y-1)); // add to crib
    m_hand.erase(m_hand.begin()+(y-1)); // remove from hand

    sort(m_crib.begin(),m_crib.end()); // sort crib
    
    cout << "\n................................................................" << endl;
}

void Cribbage::turnStarter() { // flip the top card
    m_starter=m_deck.dealCard();
    cout << "Your starter card..." << endl;
    cout << "1. ";
    m_starter.showCard(1);
    cout << "..." << endl;
}

void Cribbage::showCrib(int s) const { // view the crib
    
    cout << "Your crib..." << endl;

    for (int i=0; i<m_crib.size(); i++) {
        cout << i+1 << ". ";
        m_crib[i].showCard(s);
    }

    cout << "..." << endl;
}

void Cribbage::scoreRound() {
    // create a Score object and pass hand, crib, and starter by reference
    Score sRound(m_hand,m_crib,m_starter);

    m_starterPts=sRound.m_starter; // 2pts for turnin a J as starter
    m_handPts=sRound.m_hand; // hand 
    m_cribPts=sRound.m_crib; // crib

    m_roundPts=m_starterPts+m_handPts+m_cribPts; // points for round
    m_gamePts+=m_roundPts; // total points for game

    cout << "SCORING..." << endl;
    cout << "STARTER: " << m_starterPts << endl;
    cout << "HAND: " << m_handPts << endl;
    cout << "CRIB: " << m_cribPts << endl;
    cout << "POINTS THIS ROUND: " << m_roundPts << endl;
    cout << "TOTAL POINTS THIS GAME: " << m_gamePts << endl;    
    cout << "..." << endl;

    if (MAX_ROUNDS-m_round==1) { 
        cout << "There is " << MAX_ROUNDS-m_round << " hand left in the game." << endl; 
    }
    else {
        cout << "There are " << MAX_ROUNDS-m_round << " hands left in the game." << endl; 
    }
    cout << "..." << endl;
    
    // reset hand, crib, and round points
    m_handPts=0;
    m_cribPts=0;
    m_roundPts=0;

    // clear hand and crib
    m_hand.clear();
    m_crib.clear();
}

bool Cribbage::checkPlay() const {
    char c;

    if (m_round>=MAX_ROUNDS) {
        cout << "Maximum number of hands reached. Game over!" << endl;
        cout << "..." << endl;
        return false;
    }
    
    cout << "Keep playing? (y/n) ";
    cin >> c;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        return true;
    }
    if (c=='n') {
        cout << "..." << endl;
        cout << "Thanks for playing!\n" << endl;
        return false;
    }
    else {
        cout << "................................................................" << endl;
        return true;
    }
}
