// Copyright 2024 Vyacheslav Bolshakov

#include "../include/Automata.h"

int main() {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.coin(50);
    automata.choice("Espresso");
    automata.check();
    automata.cook();
    automata.finish();
}
