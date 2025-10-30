#include "Game.h"
#include "UI.h"
#include "Card.h"
#include <iostream>
#include <limits>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <unistd.h>

Game::Game() {}

void Game::run() { 
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        m_deck.shuffle();
        
        Player tempPlayer;
        Dealer tempDealer;
        m_player = tempPlayer;
        m_dealer = tempDealer;
        m_player.addCardToHand(m_deck.deal());
        m_dealer.addCardToHand(m_deck.deal());
        m_player.addCardToHand(m_deck.deal());
        m_dealer.addCardToHand(m_deck.deal());
        
        displayTable(false);
        
        if (m_player.getHandValue() == 21) {
            std::cout << "Блэкджек! У вас 21!\n";
        } else {
            playerTurn();
        }
        
        if (m_player.getHandValue() <= 21) {
            displayTable(true);
            
            dealerTurn();
        }
        
        determineWinner();
        
        std::cout << "\nХотите сыграть еще? (y/n): ";
        std::cin >> playAgain;
    }
    
    std::cout << "Спасибо за игру!\n";
}

void Game::displayTable(bool showDealerHoleCard) {
    UI::drawTable(formatHand(m_player.getHand()), m_player.getHandValue(),
                  formatHand(m_dealer.getHand(), !showDealerHoleCard), 
                  m_dealer.getHandValue(), showDealerHoleCard);
}

std::string Game::formatHand(const Hand& hand, bool hideFirstCard) {
    std::string result = "";
    
    result += "Всего: " + std::to_string(hand.getTotalValue());
    
    return result;
}

void Game::playerTurn() {
    char choice;
    
    do {
        std::cout << "\nВаш ход:\n";
        std::cout << "1. Взять карту (Hit)\n";
        std::cout << "2. Остановиться (Stand)\n";
        std::cout << "Выберите (1 или 2): ";
        
        choice = getPlayerChoice();
        
        if (choice == '1') {
            m_player.addCardToHand(m_deck.deal());
            displayTable(false);
            
            if (m_player.getHandValue() > 21) {
                std::cout << "Перебор! Вы проиграли.\n";
                return;
            }
        }
    } while (choice == '1' && m_player.getHandValue() <= 21);
}

void Game::dealerTurn() {
    std::cout << "\nХод дилера:\n";
    
    while (m_dealer.shouldHit()) {
        std::cout << "Дилер берет карту...\n";
        m_dealer.addCardToHand(m_deck.deal());
        displayTable(true);
        
        #ifdef _WIN32
            Sleep(1000);
        #else
            sleep(1);
        #endif
        
        if (m_dealer.getHandValue() > 21) {
            std::cout << "У дилера перебор!\n";
            return;
        }
    }
    std::cout << "Дилер останавливается.\n";
}

void Game::determineWinner() {
    int playerValue = m_player.getHandValue();
    int dealerValue = m_dealer.getHandValue();
    
    std::cout << "\n=== Результаты ===\n";
    std::cout << "Ваша рука: " << playerValue << std::endl;
    std::cout << "Рука дилера: " << dealerValue << std::endl;
    
    if (playerValue > 21) {
        std::cout << "Вы проиграли! Перебор.\n";
    } else if (dealerValue > 21) {
        std::cout << "Вы выиграли! У дилера перебор.\n";
    } else if (playerValue > dealerValue) {
        std::cout << "Вы выиграли!\n";
    } else if (dealerValue > playerValue) {
        std::cout << "Дилер выиграл.\n";
    } else {
        std::cout << "Ничья!\n";
    }
}

char Game::getPlayerChoice() {
    char choice;
    std::cin >> choice;

    while (choice != '1' && choice != '2') {
        std::cout << "Неверный ввод. Пожалуйста, введите 1 или 2: ";
        std::cin >> choice;
    }
    
    return (choice == '1') ? '1' : '2';
}