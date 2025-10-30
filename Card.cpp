#include "Card.h"
#include <string>

// Card.cpp может быть пустым, если вся логика в заголовочном файле
// или можно добавить здесь вспомогательные функции работы с картами

std::string getSuitSymbol(Suit suit) {
    switch(suit) {
        case Suit::HEARTS: return "♥";
        case Suit::DIAMONDS: return "♦";
        case Suit::CLUBS: return "♣";
        case Suit::SPADES: return "♠";
        default: return "?";
    }
}

std::string getRankString(Rank rank) {
    switch(rank) {
        case Rank::TWO: return "2";
        case Rank::THREE: return "3";
        case Rank::FOUR: return "4";
        case Rank::FIVE: return "5";
        case Rank::SIX: return "6";
        case Rank::SEVEN: return "7";
        case Rank::EIGHT: return "8";
        case Rank::NINE: return "9";
        case Rank::TEN: return "10";
        case Rank::JACK: return "J";
        case Rank::QUEEN: return "Q";
        case Rank::KING: return "K";
        case Rank::ACE: return "A";
        default: return "?";
    }
}

int getCardValue(Rank rank) {
    switch(rank) {
        case Rank::TWO: return 2;
        case Rank::THREE: return 3;
        case Rank::FOUR: return 4;
        case Rank::FIVE: return 5;
        case Rank::SIX: return 6;
        case Rank::SEVEN: return 7;
        case Rank::EIGHT: return 8;
        case Rank::NINE: return 9;
        case Rank::TEN:
        case Rank::JACK:
        case Rank::QUEEN:
        case Rank::KING: return 10;
        case Rank::ACE: return 11;
        default: return 0;
    }
}