#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

// Размеры доски
const int ROWS = 6;
const int COLS = 8;

// Типы фигур
const int EMPTY = 0;
const int WHITE_PAWN = 1;
const int BLACK_PAWN = 2;
const int WHITE_DAMA = 3;
const int BLACK_DAMA = 4;

// Структура хода
struct Move {
    int fromRow, fromCol, toRow, toCol;
    Move(int fr = 0, int fc = 0, int tr = 0, int tc = 0)
        : fromRow(fr), fromCol(fc), toRow(tr), toCol(tc) {
    }
    bool operator == (const Move& other) const {
        return fromRow == other.fromRow && fromCol == other.fromCol &&
               toRow == other.toRow && toCol == other.toCol;
    }
};