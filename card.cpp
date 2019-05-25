/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* card.cpp
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#include <string>
#include "card.h"

using namespace std;

Card::Card(){}

Card::Card(int card) { // create Card object

    int suit=(card-1)/RANK_SIZE;
    int rank=(card-1)%RANK_SIZE;

    m_rank=rank;
    m_suit=suit;

}

Card::~Card(){}

void Card::showCard(int visible) const { // choose whether to show or hide card
    if (!visible) {
        cout << "X X" << endl;
    }
    else {
        cout << m_ranks[m_rank] << " " << m_suits[m_suit] << endl;
    }
}

int Card::sortOrder() const {
    int order=m_rank;
    return order;
}

bool operator<(const Card &c1, const Card &c2) { // overload < operator for sort
    return( (c1.sortOrder()) < (c2.sortOrder()) );
}

