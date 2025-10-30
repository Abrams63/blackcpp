#ifndef CARD_H
#define CARD_H

enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

enum class Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct Card {
    Suit suit;
    Rank rank;
};

#endif