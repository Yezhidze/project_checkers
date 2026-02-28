//#pragma once
//#define BOARD_SIZE 8
//
//
//// Проверка находится ли клетка в пределах доски
//bool is_valid_position(int row, int col) {
//    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
//}
//
//// Проверка является ли клетка дамкой
//bool is_queen(char piece) {
//    return (piece == '*' || piece == '¤');
//}
//
//// Получение цвета фигуры (true - белые, false - черные)
//bool is_white_piece(char piece) {
//    return (piece == '•' || piece == '*');
//}
//
//// Функция для множественного взятия дамкой
//void queen_capture_sequence(char board[BOARD_SIZE][BOARD_SIZE], int row, int col,
//    bool white_turn, int depth)
//{
//    char piece = board[row][col];
//    if (!is_queen(piece)) return;
//
//    bool made_capture = false;
//
//    // Все 4 направления для дамки
//    int directions[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
//
//    // Пробуем бить в каждом направлении
//    for (int d = 0; d < 4; d++) {
//        int dr = directions[d][0];
//        int dc = directions[d][1];
//
//        // Дамка может бить через несколько клеток
//        int step = 1;
//        bool found_enemy = false;
//        int enemy_row = -1, enemy_col = -1;
//
//        // Ищем вражескую фигуру на пути
//        while (is_valid_position(row + step * dr, col + step * dc)) {
//            int check_row = row + step * dr;
//            int check_col = col + step * dc;
//            char current = board[check_row][check_col];
//
//            if (current != ' ') {
//                if (!found_enemy) {
//                    // Проверяем, вражеская ли это фигура
//                    bool is_enemy = false;
//                    if (white_turn) { // Белые бьют черных
//                        is_enemy = (current == '°' || current == '¤');
//                    }
//                    else { // Черные бьют белых
//                        is_enemy = (current == '•' || current == '*');
//                    }
//
//                    if (is_enemy) {
//                        found_enemy = true;
//                        enemy_row = check_row;
//                        enemy_col = check_col;
//                    }
//                    else {
//                        // Своя фигура - дальше не идем
//                        break;
//                    }
//                }
//                else {
//                    // Уже нашли врага, но есть еще фигура - нельзя
//                    break;
//                }
//            }
//            else if (found_enemy) {
//                // Нашли пустую клетку за врагом - можно бить
//                int landing_row = check_row;
//                int landing_col = check_col;
//
//                // Сохраняем состояние
//                char enemy = board[enemy_row][enemy_col];
//                char current_piece = board[row][col];
//
//                // Выполняем взятие
//                board[row][col] = ' ';
//                board[enemy_row][enemy_col] = ' ';
//                board[landing_row][landing_col] = current_piece;
//
//                made_capture = true;
//
//                printf("Взятие: (%d,%d) -> (%d,%d), сбита фигура на (%d,%d)\n",row, col, landing_row, landing_col, enemy_row, enemy_col);
//
//                // Рекурсивно пробуем бить дальше
//                queen_capture_sequence(board, landing_row, landing_col, white_turn, depth + 1);
//
//                // Восстанавливаем для проверки других направлений
//                board[row][col] = current_piece;
//                board[enemy_row][enemy_col] = enemy;
//                board[landing_row][landing_col] = ' ';
//
//                break; // Нашли вариант взятия в этом направлении
//            }
//            step++;
//        }
//    }
//
//    if (depth == 0 && !made_capture) {
//        printf("Нет возможных взятий для дамки на (%d,%d)\n", row, col);
//    }
//}
//
//// Проверка может ли дамка бить
//bool can_queen_capture(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, bool white_turn) {
//    char piece = board[row][col];
//    if (!is_queen(piece)) return false;
//
//    int directions[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
//
//    for (int d = 0; d < 4; d++) {
//        int dr = directions[d][0];
//        int dc = directions[d][1];
//
//        int step = 1;
//        bool found_enemy = false;
//
//        while (is_valid_position(row + step * dr, col + step * dc)) {
//            int check_row = row + step * dr;
//            int check_col = col + step * dc;
//            char current = board[check_row][check_col];
//
//            if (current != ' ') {
//                if (!found_enemy) {
//                    bool is_enemy = false;
//                    if (white_turn) {
//                        is_enemy = (current == '°' || current == '¤');
//                    }
//                    else {
//                        is_enemy = (current == '•' || current == '*');
//                    }
//
//                    if (is_enemy) {
//                        found_enemy = true;
//                    }
//                    else {
//                        break;
//                    }
//                }
//                else {
//                    break;
//                }
//            }
//            else if (found_enemy) {
//                return true; // Можно бить
//            }
//            step++;
//        }
//    }
//    return false;
//}
//
//// Проверка может ли дамка просто ходить (без взятия)
//bool can_queen_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col,
//    int to_row, int to_col, bool white_turn)
//{
//    if (!is_valid_position(to_row, to_col) || board[to_row][to_col] != ' ')
//        return false;
//
//    int row_diff = to_row - from_row;
//    int col_diff = to_col - from_col;
//
//    // Проверка диагонали
//    if (abs(row_diff) != abs(col_diff) || row_diff == 0)
//        return false;
//
//    int dr = (row_diff > 0) ? 1 : -1;
//    int dc = (col_diff > 0) ? 1 : -1;
//    int steps = abs(row_diff);
//
//    // Проверяем все клетки на пути (должны быть пустыми)
//    for (int s = 1; s < steps; s++) {
//        int check_row = from_row + s * dr;
//        int check_col = from_col + s * dc;
//        if (board[check_row][check_col] != ' ')
//            return false;
//    }
//
//    return true;
//}
//
//// Основная функция для движения дамки
//bool move_queen(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col,
//    int to_row, int to_col, bool white_turn)
//{
//    char piece = board[from_row][from_col];
//
//    // Проверка что это дамка и она принадлежит текущему игроку
//    if (!is_queen(piece)) {
//        printf("Ошибка: это не дамка!\n");
//        return false;
//    }
//
//    bool piece_is_white = (piece == '*');
//    if (piece_is_white != white_turn) {
//        printf("Ошибка: не ваша фигура!\n");
//        return false;
//    }
//
//    int row_diff = to_row - from_row;
//    int col_diff = to_col - from_col;
//
//    if (abs(row_diff) != abs(col_diff) || row_diff == 0) {
//        printf("Ошибка: дамка ходит только по диагонали!\n");
//        return false;
//    }
//
//    int dr = (row_diff > 0) ? 1 : -1;
//    int dc = (col_diff > 0) ? 1 : -1;
//    int steps = abs(row_diff);
//
//    // Проверяем, является ли ход взятием
//    int enemy_row = -1, enemy_col = -1;
//    bool is_capture = false;
//
//    for (int s = 1; s <= steps; s++) {
//        int check_row = from_row + s * dr;
//        int check_col = from_col + s * dc;
//        char cell = board[check_row][check_col];
//
//        if (s < steps && cell != ' ') {
//            if (!is_capture) {
//                // Проверяем, вражеская ли фигура
//                bool is_enemy = false;
//                if (white_turn) {
//                    is_enemy = (cell == '°' || cell == '¤');
//                }
//                else {
//                    is_enemy = (cell == '•' || cell == '*');
//                }
//
//                if (is_enemy) {
//                    is_capture = true;
//                    enemy_row = check_row;
//                    enemy_col = check_col;
//                }
//                else {
//                    printf("Ошибка: нельзя перепрыгивать через свои фигуры!\n");
//                    return false;
//                }
//            }
//            else {
//                printf("Ошибка: нельзя бить несколько фигур за один ход!\n");
//                printf("Используйте функцию множественного взятия.\n");
//                return false;
//            }
//        }
//        else if (s == steps && cell != ' ') {
//            printf("Ошибка: конечная клетка должна быть пустой!\n");
//            return false;
//        }
//    }
//
//    // Выполняем ход
//    if (is_capture) {
//        board[enemy_row][enemy_col] = ' ';
//        printf("Взята фигура на (%d,%d)\n", enemy_row, enemy_col);
//    }
//
//    board[to_row][to_col] = piece;
//    board[from_row][from_col] = ' ';
//
//    printf("Дамка перемещена с (%d,%d) на (%d,%d)\n", from_row, from_col, to_row, to_col);
//
//    // Проверяем, можно ли бить дальше (для множественного взятия)
//    if (is_capture && can_queen_capture(board, to_row, to_col, white_turn)) {
//        printf("Возможно множественное взятие! Вызовите queen_capture_sequence\n");
//    }
//
//    return true;
//}
//
//// Функция для поиска всех дамок на доске
//void find_all_queens(char board[BOARD_SIZE][BOARD_SIZE], bool white_turn,
//    int queens[][2], int* count)
//{
//    *count = 0;
//    char queen_symbol = white_turn ? '*' : '¤';
//
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            if (board[i][j] == queen_symbol) {
//                queens[*count][0] = i;
//                queens[*count][1] = j;
//                (*count)++;
//            }
//        }
//    }
//}
//
//// Функция для проверки обязательности взятия для дамок
//bool must_queen_capture(char board[BOARD_SIZE][BOARD_SIZE], bool white_turn) {
//    int queens[32][2];
//    int queen_count;
//
//    find_all_queens(board, white_turn, queens, &queen_count);
//
//    for (int i = 0; i < queen_count; i++) {
//        if (can_queen_capture(board, queens[i][0], queens[i][1], white_turn)) {
//            return true;
//        }
//    }
//    return false;
//}