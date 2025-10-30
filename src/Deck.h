#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
    std::vector<Card> m_cards;
public:
    Deck();             
    void shuffle();     
    Card deal();        

    };

#endif