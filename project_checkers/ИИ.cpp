/*#include <iostream>
#include <vector>
#include <iomanip>

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
};

class Checkers {
private:
    vector<vector<int>> board;
    vector<Move> availableMoves;
    vector<pair<int, int>> capturedPieces; // Координаты взятых шашек
    int currentPlayer; // 1 — белые, 2 — чёрные
    int whiteCount, blackCount;

    void initBoard() {
        board.assign(ROWS, vector<int>(COLS, EMPTY));
        // Расстановка белых шашек (строки 0–1)
        for (int row = 0; row < 2; ++row) {
            for (int col = 0; col < COLS; col += 2) {
                board[row][(row % 2 == 0) ? col + 1 : col] = WHITE_PAWN;
            }
        }
        // Расстановка чёрных шашек (строки 4–5)
        for (int row = 4; row < ROWS; ++row) {
            for (int col = 0; col < COLS; col += 2) {
                board[row][(row % 2 == 0) ? col : col + 1] = BLACK_PAWN;
            }
        }
        whiteCount = 8;
        blackCount = 8;
    }

    bool isValidCell(int row, int col) const {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

    void clearMoves() {
        availableMoves.clear();
        capturedPieces.clear();
    }

    // Превращение в дамку
    void promoteToDama(int row, int col) {
        if (board[row][col] == WHITE_PAWN && row == 0) {
            board[row][col] = WHITE_DAMA;
        }
        else if (board[row][col] == BLACK_PAWN && row == ROWS - 1) {
            board[row][col] = BLACK_DAMA;
        }
    }

    // Проверка хода обычной шашкой (вперёд по диагонали)
    void checkPawnMove(int row, int col, int dRow, int dCol) {
        int newRow = row + dRow;
        int newCol = col + dCol;
        if (isValidCell(newRow, newCol) && board[newRow][newCol] == EMPTY) {
            availableMoves.emplace_back(row, col, newRow, newCol);
        }
    }

    // Проверка рубки обычной шашкой
    void checkPawnCapture(int row, int col, int dRow, int dCol) {
        int enemyRow = row + dRow;
        int enemyCol = col + dCol;
        int destRow = row + 2 * dRow;
        int destCol = col + 2 * dCol;
        if (isValidCell(enemyRow, enemyCol) && isValidCell(destRow, destCol) &&
            board[enemyRow][enemyCol] != EMPTY && board[enemyRow][enemyCol] != currentPlayer &&
            board[destRow][destCol] == EMPTY) {
            availableMoves.emplace_back(row, col, destRow, destCol);
            capturedPieces.emplace_back(enemyRow, enemyCol);
        }
    }

    // Проверка хода дамкой (любое количество клеток по диагонали)
    void checkDamaMove(int row, int col) {
        static const int dirs[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
        for (const auto& d : dirs) {
            int r = row + d[0], c = col + d[1];
            while (isValidCell(r, c) && board[r][c] == EMPTY) {
                availableMoves.emplace_back(row, col, r, c);
                r += d[0];
                c += d[1];
            }
        }
    }

    // Проверка рубки дамкой
    void checkDamaCapture(int row, int col) {
        static const int dirs[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
        for (const auto& d : dirs) {
            int enemyR = row + d[0], enemyC = col + d[1];
            int destR = row + 2 * d[0], destC = col + 2 * d[1];
            if (isValidCell(enemyR, enemyC) && isValidCell(destR, destC) &&
                board[enemyR][enemyC] != EMPTY && board[enemyR][enemyC] != currentPlayer &&
                board[destR][destC] == EMPTY) {
                availableMoves.emplace_back(row, col, destR, destC);
                capturedPieces.emplace_back(enemyR, enemyC);
            }
        }
    }

    void generateMoves() {
        clearMoves();
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == currentPlayer) {
                    checkPawnMove(r, c, (currentPlayer == WHITE_PAWN) ? -1 : 1, -1);
                    checkPawnMove(r, c, (currentPlayer == WHITE_PAWN) ? -1 : 1, 1);
                    checkPawnCapture(r, c, (currentPlayer == WHITE_PAWN) ? -1 : 1, -1);
                    checkPawnCapture(r, c, (currentPlayer == WHITE_PAWN) ? -1 : 1, 1);
                }
                else if (board[r][c] == (currentPlayer + 2)) { // Дамка
                    checkDamaMove(r, c);
                    checkDamaCapture(r, c);
                }
            }
        }
    }

    bool makeMove(const Move& move) {
        if (find(availableMoves.begin(), availableMoves.end(), move) == availableMoves.end()) {
            return false; // Недопустимый ход
        }

        // Перемещаем фигуру
        board[move.toRow][move.toCol] = board[move.fromRow][move.fromCol];
        board[move.fromRow][move.fromCol] = EMPTY;

        // Если была рубка — удаляем взятую шашку
        auto it = find(capturedPieces.begin(), capturedPieces.end(),
            make_pair(move.toRow - (move.toRow - move.fromRow) / 2,
                move.toCol - (move.toCol - move.fromCol) / 2));
        if (it != capturedPieces.end()) {
            board[it->first][it->second] = EMPTY;
            (currentPlayer == WHITE_PAWN ? blackCount-- : whiteCount--);
            capturedPieces.erase(it);
        }

        // Превращаем в дамку при необходимости
        promoteToDama(move.toRow, move.toCol);

        return true;
    }

    void printBoard() const {
        cout << "  ";
        for (int c = 0; c < COLS; ++c) cout << c + 1 << " ";
        cout << endl;
        for (int r = 0; r < ROWS; ++r) {
            cout << r + 1 << " ";*/