// Copyright 2024 Vyacheslav Bolshakov

#include <gtest/gtest.h>
#include "Automata.h"

TEST(Coffee, create) {
    Automata automata;
    EXPECT_EQ(Automata::OFF, automata.get_state());
}

TEST(Coffee, on) {
    Automata automata;
    automata.on();
    EXPECT_EQ(Automata::WAIT, automata.get_state());
}

TEST(Coffee, coin) {
    Automata automata;
    automata.on();
    automata.coin(100);
    EXPECT_EQ(Automata::ACCEPT, automata.get_state());
}

TEST(Coffee, choice) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice("Espresso");
    EXPECT_EQ(Automata::CHECK, automata.get_state());
}

TEST(Coffee, check) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice("Espresso");
    automata.check();
    EXPECT_EQ(Automata::CHECK, automata.get_state());
}

TEST(Coffee, cook) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice("Espresso");
    automata.check();
    automata.cook();
    EXPECT_EQ(Automata::COOK, automata.get_state());
}

TEST(Coffee, finish) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice("Espresso");
    automata.check();
    automata.cook();
    automata.finish();
    EXPECT_EQ(Automata::WAIT, automata.get_state());
}

TEST(Coffee, off1) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice("Espresso");
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    EXPECT_EQ(Automata::OFF, automata.get_state());
}

TEST(Coffee, off2) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(Automata::OFF, automata.get_state());
}

TEST(Coffee, error_on) {
    Automata automata;
    automata.on();
    try {
        automata.on();
    } catch (const char* error) {
        ASSERT_STREQ("Already on", error);
    }
}

TEST(Coffee, error_off) {
    Automata automata;
    try {
        automata.off();
    } catch (const char* error) {
        ASSERT_STREQ("Can't off", error);
    }
}

TEST(Coffee, error_coin) {
    Automata automata;
    try {
        automata.coin(100);
    } catch (const char* error) {
        ASSERT_STREQ("Can't get coins", error);
    }
}

TEST(Coffee, error_choice) {
    Automata automata;
    try {
        automata.choice("Espresso");
    } catch (const char* error) {
        ASSERT_STREQ("Can't choice", error);
    }
}

TEST(Coffee, error_cancel) {
    Automata automata;
    try {
        automata.cancel();
    } catch (const char* error) {
        ASSERT_STREQ("Can't cancel", error);
    }
}

TEST(Coffee, error_check) {
    Automata automata;
    try {
        automata.check();
    } catch (const char* error) {
        ASSERT_STREQ("Can't check", error);
    }
}

TEST(Coffee, error_cook) {
    Automata automata;
    try {
        automata.cook();
    } catch (const char* error) {
        ASSERT_STREQ("Can't cook", error);
    }
}

TEST(Coffee, error_finish) {
    Automata automata;
    try {
        automata.finish();
    } catch (const char* error) {
        ASSERT_STREQ("Can't finish", error);
    }
}
