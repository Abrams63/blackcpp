#include "Player.h"
#include "Card.h"
#include <algorithm>

void Hand::addCard(Card card) {
    m_cards.push_back(card);
}

int Hand::getTotalValue() const {
    int total = 0;
    int aces = 0;
    
    for (const auto& card : m_cards) {
        if (card.rank == Rank::ACE) {
            aces++;
            total += 11;
        } else {
            total += getCardValue(card.rank);
        }
    }
    
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }
    
    return total;
}

void Player::addCardToHand(Card card) {
    m_hand.addCard(card);
}

int Player::getHandValue() {
    return m_hand.getTotalValue();
}

Hand& Player::getHand() {
    return m_hand;
}

bool Dealer::shouldHit() {
    return m_hand.getTotalValue() < 17;
}