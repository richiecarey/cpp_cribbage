/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* card.h
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#pragma once

#include <iostream>

class Card {
    private:
        static const int RANK_SIZE=13;
        static const int SUIT_SIZE=4;
        std::string m_ranks[RANK_SIZE]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        // unicode for card suit symbols
        std::string m_suits[SUIT_SIZE]={"\u2660","\u2665","\u2666","\u2663"}; // spades, hearts, diamonds, clubs
    public:
        Card();
        Card(int card);
        ~Card();
        int m_rank;
        int m_suit;
        void showCard(int visible=0) const;
        int sortOrder() const;
        friend bool operator<(const Card &c1, const Card &c2);
};

