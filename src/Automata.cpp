// Copyright 2024 Vyacheslav Bolshakov

#include "../include/Automata.h"

Automata::Automata() {
    menu = {
        {"Espresso", 80},
        {"Americano", 100},
        {"Capuchinno", 100},
        {"Latte", 120}
    };
    cash = 0;
    state = Automata::OFF;
}

void Automata::on() {
    if (state == Automata::OFF) {
        state = Automata::WAIT;
    } else {
        throw "Already on";
    }
}

void Automata::off() {
    if (state == Automata::WAIT) {
        state = Automata::OFF;
    } else {
        throw "Can't off";
    }
}

void Automata::coin(int coins) {
    if (state == Automata::WAIT) {
        state = Automata::ACCEPT;
    }
    if (state == Automata::ACCEPT) {
        cash += coins;
    } else {
        throw "Can't get coins";
    }
}

void Automata::choice(std::string name) {
    if (state == Automata::ACCEPT) {
        drink = name;
        state = Automata::CHECK;
    } else {
        throw "Can't choice";
    }
}

void Automata::cancel() {
    if (state == Automata::ACCEPT || state == Automata::CHECK) {
        state = Automata::WAIT;
        cash = 0;
    } else {
        throw "Can't cancel";
    }
}

bool Automata::check() {
    if (state == Automata::CHECK) {
        int price = menu[drink];
        return cash >= price;
    } else {
        throw "Can't check";
    }
}

void Automata::cook() {
    if (state == Automata::CHECK && check()) {
        cash -= menu[drink];
        state = Automata::COOK;
    } else {
        throw "Can't cook";
    }
}

void Automata::finish() {
    if (state == Automata::COOK) {
        drink = "";
        cash = 0;
        state = Automata::WAIT;
    } else {
        throw "Can't finish";
    }
}

void Automata::get_menu() {
    for (const auto& [name, price] : menu) {
        std::cout << name << " - " << price << std::endl;
    }
}

int Automata::get_cash() {
    return cash;
}

Automata::states Automata::get_state() {
    return state;
}
