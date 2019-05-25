/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* cribbage.h
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#pragma once

#include <vector>
#include "card.h"
#include "deck.h"
#include "score.h"

class Cribbage {
    private:
        bool keepPlaying=true;
        const int HAND_SIZE=6;
        const int CRIB_SIZE=4;
        const int MAX_ROUNDS=5;
        int m_round=0;
        int m_handPts=0;
        int m_cribPts=0;
        int m_starterPts=0;
        int m_roundPts=0;
        int m_gamePts=0;
        std::vector<Card> m_hand;
        std::vector<Card> m_crib;
        Card* pHand;
        Card* pCrib;
        Card* pStarter;
        Card m_starter;
        Deck m_deck;
    public:
        Cribbage();
        ~Cribbage();
        void play();
        void welcome() const;
        void dealHand();
        void showHand() const;
        void discardTwo();
        void turnStarter();
        void showCrib(int s) const;
        void scoreRound();
        bool checkPlay() const;
};

