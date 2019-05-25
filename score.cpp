/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* score.cpp
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

// TO DO: complete checkFifteens() method
// TO DO: complete checkRuns() method

#include "card.h"
#include "deck.h"
#include "score.h"
#include <vector>

using namespace std;

// Score object constructor will populate arrays with rank and suit tallys
// and will call checkTotal()
Score::Score(vector<Card>& hand, vector<Card>& crib, Card& starter) {

    for (int i=0; i<RANK_SIZE; i++) { // set rank array to zeroes
        rHand[i]=0;
        rCrib[i]=0;
    }

    for (int i=0; i<SUIT_SIZE; i++) { // set suit array to zeroes
        sHand[i]=0;
        sCrib[i]=0;
    }

    for (int i=0; i<hand.size(); i++) { // hand: count occurrences of ranks and suits
        int r=hand.at(i).m_rank;
        int s=hand.at(i).m_suit;
        rHand[r]++;
        sHand[s]++;
    }

    for (int i=0; i<crib.size(); i++) { // crib: count occurrences of ranks and suits
        int r=crib.at(i).m_rank;
        int s=crib.at(i).m_suit;
        rCrib[r]++;
        sCrib[s]++;
    }

    // include starter rank and suit in both hand and crib arrays
    // for easier counting
    int r=starter.m_rank;
    int s=starter.m_suit;
    rHand[r]++;
    sHand[s]++;
    rCrib[r]++;
    sCrib[s]++;

    // check total in turn calls the various counting methods
    checkTotal(hand, crib, starter);
}

//Destructor
Score::~Score(){}

// check to see if starter is a J
int Score::checkStarter(Card& starter) {
    int count=0;
    if (starter.m_rank==10) {
        m_starter+=2;
        count=2;
    }
    return count;
}

// check to see if there's a J of the same suit as the starter in hand or crib
int Score::checkRightJack(vector<Card>& hand, vector<Card>& crib, Card& starter) {
    int count=0;

    // check hand for Right Jack
    for (int i=0; i<hand.size(); i++) {
        if (hand.at(i).m_rank==10 && hand.at(i).m_suit==starter.m_suit) {
            m_hand+=1;
            count=1;
        }
    }

    // check crib for Right Jack
    for (int i=0; i<crib.size(); i++) {
        if (crib.at(i).m_rank==10 && crib.at(i).m_suit==starter.m_suit) {
            m_crib+=1;
            count=1;
        }
    }
    
    return count;

}

// check for flush
int Score::checkFlush(Card& starter) {
    int count=0;

    for (int i=0; i<SUIT_SIZE; i++) {
        
        // four card of same suit in hand is a four card flush
        if ( (sHand[i]==4) && (starter.m_suit!=i) ) {
            m_hand+=4;
            count=4;
        }
        // five card flush would include hand and starter
        if (sHand[i]==5) {
            m_hand+=5;
            count=5;
        }

        // only a five card flush counts as a flush for crib
        if (sCrib[i]==5) {
            m_crib+=5;
            count=5;
        }
    }
    
    return count;
}

// check 2, 3, 4 of a kind
int Score::checkPairs() {
    int count=0;

    for (int i=0; i<RANK_SIZE; i++) {
        // hand
        if (rHand[i]==2) {
            m_hand+=2;
            count=2;
        }
        if (rHand[i]==3) {
            m_hand+=6;
            count=6;
        }
        if (rHand[i]==4) {
            m_hand+=12;
            count=12;
        }
        // crib
        if (rCrib[i]==2) {
            m_crib+=2;
            count+=2;
        }
        if (rCrib[i]==3) {
            m_crib+=6;
            count+=6;
        }
        if (rCrib[i]==4) {
            m_crib+=12;
            count+=12;
        }
    }
    
    return count;
}

// TO DO
int Score::checkFifteens() {
    int count=0;
    return count;
}

// TO DO
int Score::checkRuns() {
    int count=0;
    return 0;
}

// return total
int Score::checkTotal(vector<Card>& hand, vector<Card>& crib, Card& starter) {
    int total=checkStarter(starter)+
              checkRightJack(hand, crib, starter)+
              checkFlush(starter)+
              checkPairs()+
              checkFifteens()+
              checkRuns();
    
    return total;
}

