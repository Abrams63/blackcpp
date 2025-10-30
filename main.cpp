#include <iostream>
#include <string>
#include "UI.h"
#include "Game.h"
#include "Network.h"

int main() {
    UI::showSplashScreen();
    
    int choice;
    do {
        std::cout << "\n=== BLACKJACK ===\n";
        std::cout << "1. Одиночная игра\n";
        std::cout << "2. Мультиплеер\n";
        std::cout << "3. Помощь\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";
        
        std::cin >> choice;
        
        switch(choice) {
            case 1: {
                Game game;
                game.run();
                break;
            }
            case 2: {
                Network::startMultiplayer();
                break;
            }
            case 3: {
                UI::showHelp();
                break;
            }
            case 0: {
                std::cout << "Спасибо за игру!\n";
                break;
            }
            default: {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
    } while(choice != 0);
    
    return 0;
}