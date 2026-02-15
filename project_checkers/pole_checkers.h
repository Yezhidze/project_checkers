#pragma once
#include "main_menu.h"
#include "checkers_white.h"
#include "checkers_black.h"

//using namespace std;

void print_pole(int size, char size_pole[][8]);
int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);
void motion_white_checkers(char* white_checkers, char* black_checkers, int size, char size_pole[][8], bool check, char empty, int *ptr_number_black);         // проверка хода белых шашек по правилу первого хода
void motion_black_checkers(char* white_checkers, char* black_checkers, int size, char size_pole[][8], bool check, char empty, int *ptr_number_white);         // проверка хода чёрных шашек
char* white_checkers();
char* black_checkers();
void menu();



void checkers_pole()
{
    const char empty = ' ';                                                 // Пустое поле
    static const int size{ 8 };
    char size_pole[size][size] {};

    for (int i = 0; i < size; i++)                                          // длина
    {
        for (int j = 0; j < size; j++)                                      // столбцы
        {
            size_pole[i][j] = empty;                                        // Заполняем доску пустыми клетками
        }
    }

    char* ptr_checkers_white = white_checkers();
    char* ptr_checkers_black = black_checkers();

    bool check = checkers_position(size, size_pole, ptr_checkers_white, ptr_checkers_black);
    
    print_pole(size, size_pole);
    system("pause");
    /*if (check == 0)
    {*/
        /*while(black_checkers() != 0 || white_checkers() != 0)
        {
            motion_white_checkers(ptr_checkers_white, ptr_checkers_black, size, size_pole, check, empty);
            motion_black_checkers(ptr_checkers_white, ptr_checkers_black, size, size_pole, check, empty);
        }*/
    int number_white{ 12 };
    int* ptr_number_white = &number_white;
    int number_black{ 12 };
    int* ptr_number_black = &number_black;
    bool number_check = true;

    while (number_check)
    {
        if (*ptr_number_black > 0)
        {
            motion_white_checkers(ptr_checkers_white, ptr_checkers_black, size, size_pole, check, empty, ptr_number_black);
            if (*ptr_number_white > 0)
            {
                motion_black_checkers(ptr_checkers_white, ptr_checkers_black, size, size_pole, check, empty, ptr_number_white);
            }
        }
        else
            menu();
    }
    //a6b5d3c4b5d3e2c4b7a6c4d5c6e4f3d5e6c4b3d5d7e6h3g4e6c4g4f5g6e4c2d3e4c2b1d3a6b5d3c4e2d1f3f7e6f3e4a6b5e4d5e6c4a2b3c4a2g2f3h7g6f3g4b5c4g4f5g6e4f1e2a2b1e2f3e4g2h1f3a8b7f3e4g8h7e4d5c4e6
    //}
}

void print_pole(int size, char size_pole[][8])                                                                 // вывод поля в консоль
{ 
    system("cls");
    cout << "\n\n"; //\n\n";
    cout << "\t\t\t\t\t    a  b  c  d  e  f  g  h\n";                                  //Рисую отметки по краю доски(кординаты если по русски :D )
    for (int row = 0, numb = 0; row < size; row++, numb++)                  // Чередуем цвет фона в зависимости от позиции
    {
        cout << "\t\t\t\t\t ";
        cout << (numb + 1) << " ";
        for (int col = 0; col < size; col++)
        {
            if ((row + col) % 2 == 0) 
            {
                
                cout << "\033[107m " << size_pole[row][col] << " \033[0m";  // Белый фон
            }
            else 
            {
                cout << "\033[40m " << size_pole[row][col] << " \033[0m";   // Чёрный фон
            }
        }
        cout << " " << (numb + 1) << "\n";
    }
    cout << "\t\t\t\t\t    a  b  c  d  e  f  g  h\n";
    cout << endl;
    cout << "\t\t\t\t\t • - белая пешка." << endl;
    cout << "\t\t\t\t\t ° - чёрная пешка." << endl;
    cout << "\t\t\t\t\t Где [i][j] - координаты шашек и полей." << endl;
    cout << "\t\t\t\t\t Ї - шашки, которыми можно сходить.\n" << endl;
}

int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers)
{
    int check{};
    cout << "Выбор стороны (0 - белые, 1 - чёрные) : ";
    cin >> check;
    if (check == 0)
    {
        for (int i = 0; i < 4; i++)                         //ряд 0
            size_pole[0][i * 2 + 1] = black_checkers[i];

        for (int i = 0; i < 4; i++)                         //ряд 1
            size_pole[1][i * 2] = black_checkers[i + 4];

        for (int i = 0; i < 4; i++)                         //ряд 2
            size_pole[2][i * 2 + 1] = black_checkers[i + 8];

        for (int i = 0; i < 4; i++)                         //ряд 5
            size_pole[5][i * 2] = white_checkers[i];

        for (int i = 0; i < 4; i++)                         //ряд 6
            size_pole[6][i * 2 + 1] = white_checkers[i + 4];

        for (int i = 0; i < 4; i++)                         //ряд 7
            size_pole[7][i * 2] = white_checkers[i + 8];
    }
    else if (check == 1)
    {
        for (int i = 0; i < 4; i++)                         //ряд 0
            size_pole[0][i * 2 + 1] = white_checkers[i];

        for (int i = 0; i < 4; i++)                         //ряд 1
            size_pole[1][i * 2] = white_checkers[i + 4];

        for (int i = 0; i < 4; i++)                         //ряд 2
            size_pole[2][i * 2 + 1] = white_checkers[i + 8];

        for (int i = 0; i < 4; i++)                         //ряд 5
            size_pole[5][i * 2] = black_checkers[i];

        for (int i = 0; i < 4; i++)                         //ряд 6
            size_pole[6][i * 2 + 1] = black_checkers[i + 4];

        for (int i = 0; i < 4; i++)                         //ряд 7
            size_pole[7][i * 2] = black_checkers[i + 8];
    }

    return check;
}