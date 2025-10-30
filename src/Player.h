#ifndef PLAYER_H
#define PLAYER_H

#include "../Card.h"
#include <vector>

class Hand {
    std::vector<Card> m_cards;
public:
    void addCard(Card card);
    int getTotalValue(); // Считает сумму с обработкой Тузов (11→1)
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
    // Тот же, но с другими правилами
    bool shouldHit(); // Дилер берет карту, если у него меньше 17
};

#endif