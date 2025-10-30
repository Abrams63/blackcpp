#include "UI.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

void UI::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void UI::showSplashScreen() { 
    std::cout << "\n\n";
    std::cout << "  ██████╗ ██╗   ██╗███████╗ ██████╗ ███╗   ██╗    \n";
    std::cout << " ██╔════╝ ██║   ██║╚══███╔╝╚══███╔╝██╔═══██╗████╗  ██║    \n";
    std::cout << " ██║      ██║   ██║  ███╔╝   ███╔╝ ██║   ██║██╔██╗ ██║    \n";
    std::cout << " ██║      ██║   ██║ ███╔╝   ███╔╝  ██║   ██║██║╚██╗██║    \n";
    std::cout << " ╚██████╗ ╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║    \n";
    std::cout << "  ╚═════╝  ╚═════╝ ╚══════╝╚════╝ ╚═════╝ ╚═╝  ╚═══╝    \n";
    std::cout << "                                                          \n";
    std::cout << " ██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗ ███████╗ \n";
    std::cout << " ██╔══██╗██╔══██╗██╔══╝██║ ██╔╝██╔══╝██╔══██╗██╔══╝ \n";
    std::cout << " ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝███████╗ \n";
    std::cout << " ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗╚════██║ \n";
    std::cout << " ██████╔╝██║  ██║╚██████╗██║  ██╗███████╗██║  ██║███████║ \n";
    std::cout << " ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝ ╚═╝╚══════╝╚═╝ ╚═╝╚══════╝ \n";
    std::cout << "\n\n";
}

void UI::showHelp() {
    clearScreen();
    std::cout << "\n=== ПОМОЩЬ ПО ИГРЕ БЛЭКДЖЕК ===\n\n";
    std::cout << "Цель игры: Набрать больше очков, чем дилер, но не более 21.\n\n";
    std::cout << "Правила:\n";
    std::cout << "- Карты 2-10 стоят столько очков, сколько на них указано\n";
    std::cout << "- Валет, Дама, Король стоят по 10 очков\n";
    std::cout << "- Туз может быть 1 или 11 - выбирается автоматически\n";
    std::cout << "- Если сумма больше 21 - перебор (bust), игрок проигрывает\n\n";
    std::cout << "Ход игры:\n";
    std::cout << "- Игрок получает 2 карты\n";
    std::cout << "- Дилер получает 2 карты (одна из них закрыта)\n";
    std::cout << "- Игрок может:\n";
    std::cout << "  * Взять карту (Hit) - получить еще одну карту\n";
    std::cout << "  * Остановиться (Stand) - завершить набор карт\n";
    std::cout << "- После хода игрока, дилер берет карты до 17\n\n";
    std::cout << "Нажмите Enter для возврата в меню...";
    std::cin.ignore();
    std::cin.get();
}

void UI::drawCard(const std::string& rank, const std::string& suit) {
    std::cout << "┌─────┐\n";
    std::cout << "│ " << rank << "   │\n";
    std::cout << "│  " << suit << "  │\n";
    std::cout << "│   " << rank << " │\n";
    std::cout << "└─────┘\n";
}

void UI::drawTable(const std::string& playerHand, int playerTotal,
                   const std::string& dealerHand, int dealerTotal,
                   bool showDealerHoleCard) {
    
    clearScreen();
    std::cout << "\n========== СТОЛ ==========\n\n";
    
    std::cout << "Дилер:\n";
    if (showDealerHoleCard) {
        std::cout << dealerHand;
    } else {
        std::cout << "┌─────┐ ┌─────┐\n";
        std::cout << "│ " << dealerHand.substr(4, 2) << "  │ │ ?   │\n";
        std::cout << "│  " << dealerHand.substr(11, 1) << "  │ │  ? │\n";
        std::cout << "│   " << dealerHand.substr(4, 2) << " │ │   ? │\n";
        std::cout << "└─────┘ └─────┘\n";
    }
    std::cout << "Всего: " << (showDealerHoleCard ? std::to_string(dealerTotal) : "?") << "\n\n";
    
    std::cout << "Игрок:\n";
    std::cout << playerHand;
    std::cout << "Всего: " << playerTotal << "\n\n";
}