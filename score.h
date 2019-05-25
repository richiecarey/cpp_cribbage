/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* score.h
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#pragma once

#include <iostream>
#include <vector>
#include "card.h"

class Score {
    private:
        static const int RANK_SIZE=13;
        static const int SUIT_SIZE=4;
        int rHand[RANK_SIZE];
        int rCrib[RANK_SIZE];
        int sHand[SUIT_SIZE];
        int sCrib[SUIT_SIZE];
    public:
        Score(std::vector<Card>& hand, std::vector<Card>& crib, Card& starter);
        ~Score();
        int m_hand=0;
        int m_crib=0;
        int m_starter=0;
        int checkStarter(Card& starter);
        int checkRightJack(std::vector<Card>& hand, std::vector<Card>& crib, Card& starter);
        int checkFlush(Card& starter);
        int checkPairs();
        int checkFifteens();
        int checkRuns();
        int checkTotal(std::vector<Card>& hand, std::vector<Card>& crib, Card& starter);
};

