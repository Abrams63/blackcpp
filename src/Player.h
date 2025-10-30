#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>


class Hand {
    std::vector<Card> m_cards;
public:
    void addCard(Card card);
    int getTotalValue() const;
};

class Player {
protected:
    Hand m_hand;
public:
    void addCardToHand(Card card);
    int getHandValue();
    Hand& getHand();
};

class Dealer : public Player {
public:
    bool shouldHit();
};

#endif