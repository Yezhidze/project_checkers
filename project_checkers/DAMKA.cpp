//#include <iostream>
//using namespace std;
//
//const char white_checkers = 'w';
//const char black_checkers = 'b';
//const char white_queen = 'W';
//const char black_queen = 'B';
//
//void motion(char& checker_type, int row);
//void make_first_move(char board[][8], int fromRow, int fromCol, int toRow, int toCol);
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//
//    char board[8][8] = { 0 };
//
//    board[6][3] = white_checkers;
//
//    make_first_move(board, 6, 3, 7, 3);
//
//    board[1][0] = black_checkers;
//
//    make_first_move(board, 1, 0, 0, 0);
//
//    return 0;
//}
//
//void motion(char& checker_type, int row)
//{
//    if (checker_type == white_checkers && row == 7)
//    {
//        cout << "Белая шашка превращается в дамку!" << endl;
//        checker_type = white_queen;
//    }
//    else if (checker_type == black_checkers && row == 0)
//    {
//        cout << "Черная шашка превращается в дамку!" << endl;
//        checker_type = black_queen;
//    }
//}
//
//void make_first_move(char board[][8], int fromRow, int fromCol, int toRow, int toCol)
//{
//    char checker_type = board[fromRow][fromCol];
//
//    board[fromRow][fromCol] = 0;
//
//    board[toRow][toCol] = checker_type;
//
//    cout << "Первый ход: [" << fromRow + 1 << "][" << char('a' + fromCol)
//        << "] -> [" << toRow + 1 << "][" << char('a' + toCol) << "]" << endl;
//
//    motion(checker_type, toRow);
//
//    board[toRow][toCol] = checker_type;
//}

// дамка для чёрных - ¤  ®   o  
// дамка для белых -  *  †   © 
