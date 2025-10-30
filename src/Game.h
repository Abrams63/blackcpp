#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "../Deck.h"
#include <string>

class Game {
    Deck m_deck;
    Player m_player;
    Dealer m_dealer;
    
    // Внутренние вспомогательные функции
    void displayTable(bool showDealerHoleCard = true);
    std::string formatHand(const Hand& hand, bool hideFirstCard = false);
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    char getPlayerChoice();
    
public:
    Game(); // Конструктор
    void run(); // Запуск игры
};

#endif