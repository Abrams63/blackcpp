#include "Game.h"
#include "UI.h"
#include "../Card.cpp"
#include <iostream>
#include <limits>

Game::Game() {
    // Конструктор ничего не делает, так как колода и игроки будут инициализированы в run()
}

void Game::run() {
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        // Перемешиваем колоду
        m_deck.shuffle();
        
        // Очищаем руки игроков
        // Создаем новые объекты, так как у нас нет метода очистки руки
        Player tempPlayer;
        Dealer tempDealer;
        m_player = tempPlayer;
        m_dealer = tempDealer;
        
        // Сдаем по 2 карты игроку и дилеру
        m_player.addCardToHand(m_deck.deal());
        m_dealer.addCardToHand(m_deck.deal());
        m_player.addCardToHand(m_deck.deal());
        m_dealer.addCardToHand(m_deck.deal());
        
        // Показываем стол (с закрытой картой дилера)
        displayTable(false);
        
        // Проверяем, не выпало ли у игрока 21 сразу
        if (m_player.getHandValue() == 21) {
            std::cout << "Блэкджек! У вас 21!\n";
        } else {
            // Ход игрока
            playerTurn();
        }
        
        // Если игрок не перебрал, то ход дилера
        if (m_player.getHandValue() <= 21) {
            // Показываем обе карты дилера
            displayTable(true);
            
            dealerTurn();
        }
        
        // Определяем победителя
        determineWinner();
        
        // Спрашиваем, хочет ли игрок играть снова
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
    // Эта функция должна возвращать строку, представляющую руку
    // В текущей реализации UI.cpp ожидает строку, но мы просто выводим карты напрямую
    // Пока вернем пустую строку, так как UI::drawTable не использует этот параметр напрямую
    std::string result = "";
    
    // Вместо этого, мы будем использовать логику отображения в UI::drawTable
    // Но для совместимости с текущей структурой просто возвращаем строку
    // содержащую количество карт
    result += "Карты: " + std::to_string(hand.getTotalValue());
    
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
    
    // Дилер берет карты, пока не наберет 17 или больше
    while (m_dealer.shouldHit()) {
        std::cout << "Дилер берет карту...\n";
        m_dealer.addCardToHand(m_deck.deal());
        displayTable(true);
        
        // Небольшая задержка для лучшего UX
        #ifdef _WIN32
            Sleep(1000); // Задержка 1 секунда (требует #include <windows.h>)
        #else
            sleep(1); // Задержка 1 секунда (требует #include <unistd.h>)
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
    
    // Проверяем, является ли ввод числом 1 или 2
    while (choice != '1' && choice != '2') {
        std::cout << "Неверный ввод. Пожалуйста, введите 1 или 2: ";
        std::cin >> choice;
    }
    
    return (choice == '1') ? '1' : '2';
}