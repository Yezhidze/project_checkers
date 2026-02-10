#pragma once
#include "pole_checkers.h"
#include "logic_game.h"
using namespace std;

int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);
void checkers_pole();
void print_pole(int size, char size_pole[][8]);
void check_to_go(char size_pole[][8], char check, int control);

char* black_checkers()
{
    static const int size_black{ 12 };
    static char black_checkers[size_black]{};

    for (int i = 0; i < size_black; i++)
        black_checkers[i] = '°';

    return black_checkers;
}
void motion_black_checkers(char* white_checkers, char* black_checkers, int size, char size_pole[][8], bool check, char empty)            // проверка хода чёрных шашек
{
    int a{ 0 }, b{ 1 }, c{ 2 }, d{ 3 }, e{ 4 }, f{ 5 }, g{ 6 }, h{ 7 };
    bool white{ true };
    char motion = 'Ї';                                                                                                                // возможные ходы
    int x_IN{}, x_OU{};                                                                                                               // координаты
    int y_IN{}, y_OU{};
    int number{};
    char x_test{}, y_test{};

    if (check == 0)
    {
        cout << "Вы играете чёрными (сверху)" << endl;

        check_to_go(size_pole, '°', 1);

        cout << "Ход чёрными." << endl;

        cout << '\n' << "Выберете шашку: ";
        cin >> y_test;
        cin >> x_test;
        for (int i = 1; x_IN <= 8; i++)
        {
            if (x_test == (i + 48))
            {
                x_IN = i;
                x_IN -= 1;
                break;
            }
        }
        for (int i = 1; y_IN <= 8; i++)
        {
            if (y_test == (i + 96))
            {
                y_IN = i;
                y_IN -= 1;
                break;
            }
        }

        cout << '\n' << "Выберете куда сходить: ";
        cin >> y_test;
        cin >> x_test;
        for (int i = 1; x_OU <= 8; i++)
        {
            if (x_test == (i + 48))
            {
                x_OU = i;
                x_OU -= 1;
                break;
            }
        }
        for (int i = 1; y_OU <= 8; i++)
        {
            if (y_test == (i + 96))
            {
                y_OU = i;
                y_OU -= 1;
                break;
            }
        }

        for (int i = 1, k = 0; i < 8; i += 2, k++)
            size_pole[2][i] = black_checkers[k];
        if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
        {
            swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
            size_pole[x_OU][y_OU] = black_checkers[0];
            print_pole(size, size_pole);
        }
        else
        cout << "!!!!!!!!!ОШИБОЧНЫЙ ДОЛБАЁБ!!!!!!!" << endl;
    }
    else if (check == 1)
    {
        cout << "\nВы играете чёрными (снизу)" << endl;
        for (int i = 0; i < 8; i += 2)
            size_pole[5][i] = motion;

        print_pole(size, size_pole);

        cout << "Ход чёрными." << endl;

        cout << '\n' << "Выберете шашку: ";
        cin >> y_test;
        cin >> x_test;
        for (int i = 1; x_IN <= 8; i++)
        {
            if (x_test == (i + 48))
            {
                x_IN = i;
                x_IN -= 1;
                break;
            }
        }
        for (int i = 1; y_IN <= 8; i++)
        {
            if (y_test == (i + 96))
            {
                y_IN = i;
                y_IN -= 1;
                break;
            }
        }

        cout << '\n' << "Выберете куда сходить: ";
        cin >> y_test;
        cin >> x_test;
        for (int i = 1; x_OU <= 8; i++)
        {
            if (x_test == (i + 48))
            {
                x_OU = i;
                x_OU -= 1;
                break;
            }
        }
        for (int i = 1; y_OU <= 8; i++)
        {
            if (y_test == (i + 96))
            {
                y_OU = i;
                y_OU -= 1;
                break;
            }
        }

        check_to_go(size_pole, '°', 2);
        if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
        {
            swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
            size_pole[x_OU][y_OU] = black_checkers[0];
            print_pole(size, size_pole);
        }
        else
            cout << "!!!!!!!!!ОШИБОЧНЫЙ ДОЛБАЁБ!!!!!!!" << endl;
    }
}