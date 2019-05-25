/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* deck.h
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"

class Deck {
    private:
        static const int DECK_SIZE=52;
        int m_deck[DECK_SIZE];
        int m_numDealt=0;
    public:
        Deck();
        ~Deck();
        void showDeck() const;
        void shuffle();
        Card dealCard();
        int numDealt();
};

