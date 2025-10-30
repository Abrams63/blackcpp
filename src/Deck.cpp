#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    for (int suit = static_cast<int>(Suit::HEARTS); suit <= static_cast<int>(Suit::SPADES); ++suit) {
        for (int rank = static_cast<int>(Rank::TWO); rank <= static_cast<int>(Rank::ACE); ++rank) {
            Card card;
            card.suit = static_cast<Suit>(suit);
            card.rank = static_cast<Rank>(rank);
            m_cards.push_back(card);
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(m_cards.begin(), m_cards.end(), gen);
}

Card Deck::deal() {
    Card card = m_cards.back();
    m_cards.pop_back();
    return card;
}