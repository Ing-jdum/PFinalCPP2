#ifndef MENU_H
#define MENU_H

class Menu {
private:
    void showMainMenu();
    void handleLoanSimulator();
    void handleCreditAnalysis();

public:
    Menu();
    void run();
};

#endif