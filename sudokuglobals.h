#ifndef SUDOKUGLOBALS_H
#define SUDOKUGLOBALS_H

#include <stdio.h>

const int rows = 9;
const int cols = 9;

const int numTokens = rows * cols;

enum Token {
A,
B,
C,
D,
E,
F,
G,
H,
I,
None
};

enum Color {
    White,
    Red,
    Green
};

struct ColoredToken {
    Token token;
    Color color;
};

enum Control {
Display,
Load,
Solve,
Exit
};

#endif
