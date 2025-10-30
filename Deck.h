#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
    std::vector<Card> m_cards;
public:
    Deck();             // Заполняет 52 карты
    void shuffle();     // std::shuffle
    Card deal();        // Возвращает карту
};

#endif