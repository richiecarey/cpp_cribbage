/*****************************************************************************
* Richie Carey
* <richiecarey @ gmail.com>
*
* August 9, 2018
*
* Final Project - Cribbage Solitaire
*
* main.cpp
*
* Editor: VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Nov 24 2016 16:44:48)
* Compiler: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
******************************************************************************/

#include <cstdlib>
#include <ctime>
#include <vector>
#include "header.h"
#include "deck.h"
#include "card.h"
#include "cribbage.h"

using namespace std;

int main() {

    // seed random
    srand(time(0));

    // create a Cribbage object
    Cribbage game;

    // invoke play() method on the object
    game.play();

}

