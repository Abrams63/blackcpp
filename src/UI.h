#ifndef UI_H
#define UI_H

#include <string>

class UI {
public:
    static void clearScreen();
    static void showSplashScreen();
    static void showHelp();
    static void drawCard(const std::string& rank, const std::string& suit);
    static void drawTable(const std::string& playerHand, int playerTotal, 
                         const std::string& dealerHand, int dealerTotal, 
                         bool showDealerHoleCard = true);
};

#endif