#include <iostream>
#include <map>
#include <string>

class Automata {
public:
    enum states {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    Automata();
    void on();
    void off();
    void coin(int coins);
    void choice(std::string name);
    bool check();
    void cancel();
    void cook();
    void finish();
    int get_cash();
    void get_menu();
    states get_state();
private:
    std::map<std::string, int> menu;
    states state;
    int cash;
    std::string drink;
};