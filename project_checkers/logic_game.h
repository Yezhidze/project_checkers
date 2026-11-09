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

class LogicGame {
private:
    int board[ROWS][COLS];
    int currentPlayer; // 1 - белые, 2 - чёрные
    bool isWhiteTurn;

    bool isInside(int r, int c) const {
        return r >= 0 && r < ROWS && c >= 0 && c < COLS;
    }

    bool isWhite(int piece) const {
        return piece == WHITE_PAWN || piece == WHITE_DAMA;
    }

    bool isBlack(int piece) const {
        return piece == BLACK_PAWN || piece == BLACK_DAMA;
    }

    bool isDama(int piece) const {
        return piece == WHITE_DAMA || piece == BLACK_DAMA;
    }

    bool isEnemy(int piece, int player) const {
        if (player == 1) return isBlack(piece);
        return isWhite(piece);
    }

    bool isOwn(int piece, int player) const {
        if (player == 1) return isWhite(piece);
        return isBlack(piece);
    }

    void promote(int r, int c) {
        if (board[r][c] == WHITE_PAWN && r == ROWS - 1)
            board[r][c] = WHITE_DAMA;
        if (board[r][c] == BLACK_PAWN && r == 0)
            board[r][c] = BLACK_DAMA;
    }

    vector<Move> getCaptures(int r, int c, int player) {
        vector<Move> caps;
        int piece = board[r][c];
        int dirs[4][2] = { {-1,-1}, {-1,1}, {1,-1}, {1,1} };

        if (!isDama(piece)) {
            int step = (player == 1) ? 1 : -1;
            for (int d = 0; d < 4; d++) {
                int dr = dirs[d][0], dc = dirs[d][1];
                if (dr != step) continue; // пешка бьёт только вперёд
                int mr = r + dr, mc = c + dc;
                int tr = r + 2 * dr, tc = c + 2 * dc;
                if (isInside(tr, tc) && isEnemy(board[mr][mc], player) && board[tr][tc] == EMPTY)
                    caps.push_back(Move(r, c, tr, tc));
            }
        } else {
            // дамка: любое направление, прыжок через противника
            for (int d = 0; d < 4; d++) {
                int dr = dirs[d][0], dc = dirs[d][1];
                for (int dist = 1; dist < max(ROWS, COLS); dist++) {
                    int mr = r + dr * dist, mc = c + dc * dist;
                    if (!isInside(mr, mc)) break;
                    if (board[mr][mc] == EMPTY) continue;
                    if (!isEnemy(board[mr][mc], player)) break;
                    int tr = mr + dr, tc = mc + dc;
                    if (isInside(tr, tc) && board[tr][tc] == EMPTY)
                        caps.push_back(Move(r, c, tr, tc));
                    break;
                }
            }
        }
        return caps;
    }

    vector<Move> getSimpleMoves(int r, int c, int player) {
        vector<Move> moves;
        int piece = board[r][c];
        int dirs[4][2] = { {-1,-1}, {-1,1}, {1,-1}, {1,1} };

        if (!isDama(piece)) {
            int step = (player == 1) ? 1 : -1;
            for (int d = 0; d < 4; d++) {
                int dr = dirs[d][0], dc = dirs[d][1];
                if (dr != step) continue;
                int tr = r + dr, tc = c + dc;
                if (isInside(tr, tc) && board[tr][tc] == EMPTY)
                    moves.push_back(Move(r, c, tr, tc));
            }
        } else {
            for (int d = 0; d < 4; d++) {
                int dr = dirs[d][0], dc = dirs[d][1];
                for (int dist = 1; dist < max(ROWS, COLS); dist++) {
                    int tr = r + dr * dist, tc = c + dc * dist;
                    if (!isInside(tr, tc) || board[tr][tc] != EMPTY) break;
                    moves.push_back(Move(r, c, tr, tc));
                }
            }
        }
        return moves;
    }

public:
    LogicGame() {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                board[i][j] = EMPTY;
        // Белые пешки: первые две строки
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < COLS; j++)
                if ((i + j) % 2 == 1)
                    board[i][j] = WHITE_PAWN;
        // Чёрные пешки: последние две строки
        for (int i = ROWS - 2; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if ((i + j) % 2 == 1)
                    board[i][j] = BLACK_PAWN;
        currentPlayer = 1;
        isWhiteTurn = true;
    }

    int getCurrentPlayer() const { return currentPlayer; }
    bool isWhiteTurnNow() const { return isWhiteTurn; }

    int getPiece(int r, int c) const {
        if (!isInside(r, c)) return -1;
        return board[r][c];
    }

    void setPiece(int r, int c, int piece) {
        if (isInside(r, c)) board[r][c] = piece;
    }

    // Все доступные ходы текущего игрока (рубки приоритетнее)
    vector<Move> getAllMoves() {
        vector<Move> allCaptures, allSimple;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (isOwn(board[i][j], currentPlayer)) {
                    auto caps = getCaptures(i, j, currentPlayer);
                    allCaptures.insert(allCaptures.end(), caps.begin(), caps.end());
                    auto simp = getSimpleMoves(i, j, currentPlayer);
                    allSimple.insert(allSimple.end(), simp.begin(), simp.end());
                }
            }
        }
        if (!allCaptures.empty()) return allCaptures;
        return allSimple;
    }

    // Ходы для ИИ: все ходы данного игрока
    vector<Move> getAllMovesFor(int player) {
        vector<Move> allCaptures, allSimple;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (isOwn(board[i][j], player)) {
                    auto caps = getCaptures(i, j, player);
                    allCaptures.insert(allCaptures.end(), caps.begin(), caps.end());
                    auto simp = getSimpleMoves(i, j, player);
                    allSimple.insert(allSimple.end(), simp.begin(), simp.end());
                }
            }
        }
        if (!allCaptures.empty()) return allCaptures;
        return allSimple;
    }

    bool hasMoves() {
        return !getAllMoves().empty();
    }

    // Выполнить ход. Возвращает true, если это была рубка
    bool makeMove(const Move& m) {
        int piece = board[m.fromRow][m.fromCol];
        board[m.toRow][m.toCol] = piece;
        board[m.fromRow][m.fromCol] = EMPTY;

        bool captured = false;
        int dr = m.toRow - m.fromRow;
        int dc = m.toCol - m.fromCol;
        if (abs(dr) == 2 || abs(dc) == 2) {
            // рубка
            int mr, mc;
            if (isDama(piece)) {
                mr = m.fromRow + dr / 2;
                mc = m.fromCol + dc / 2;
            } else {
                mr = (m.fromRow + m.toRow) / 2;
                mc = (m.fromCol + m.toCol) / 2;
            }
            board[mr][mc] = EMPTY;
            captured = true;
        }

        promote(m.toRow, m.toCol);

        // Если рубка и есть продолжение — не меняем игрока
        if (captured) {
            auto more = getCaptures(m.toRow, m.toCol, currentPlayer);
            if (!more.empty()) return true;
        }

        // Смена игрока
        currentPlayer = 3 - currentPlayer;
        isWhiteTurn = !isWhiteTurn;
        return captured;
    }

    // Для ИИ: сделать ход определённым игроком
    bool makeMoveFor(int player, const Move& m) {
        if (currentPlayer != player) return false;
        return makeMove(m);
    }

    void switchPlayer() {
        currentPlayer = 3 - currentPlayer;
        isWhiteTurn = !isWhiteTurn;
    }

    // Победа: 1 - белые, 2 - чёрные, 0 - ничья
    int checkWin() {
        bool whiteAlive = false, blackAlive = false;
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++) {
                if (isWhite(board[i][j])) whiteAlive = true;
                if (isBlack(board[i][j])) blackAlive = true;
            }
        if (!whiteAlive) return 2;
        if (!blackAlive) return 1;
        // Нет ходов
        if (getAllMovesFor(1).empty() && getAllMovesFor(2).empty()) {
            // кто не может ходить — тот проиграл
            if (getAllMovesFor(currentPlayer).empty())
                return 3 - currentPlayer;
        }
        return 0;
    }

    void printBoard() const {
        cout << "   ";
        for (int j = 0; j < COLS; j++) cout << j << "  ";
        cout << endl;
        for (int i = 0; i < ROWS; i++) {
            cout << i << "  ";
            for (int j = 0; j < COLS; j++) {
                char ch = '.';
                switch (board[i][j]) {
                    case WHITE_PAWN: ch = 'w'; break;
                    case BLACK_PAWN: ch = 'b'; break;
                    case WHITE_DAMA: ch = 'W'; break;
                    case BLACK_DAMA: ch = 'B'; break;
                }
                cout << ch << "  ";
            }
            cout << endl;
        }
    }
};