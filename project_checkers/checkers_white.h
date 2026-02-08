#pragma once
#include "pole_checkers.h"
using namespace std;

int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);
void checkers_pole();
void print_pole(int size, char size_pole[][8]);

char* white_checkers()
{
    static const int size_whites{ 12 };
    static char white_checkers[size_whites]{};

    for (int i = 0; i < size_whites; i++)
        white_checkers[i] = '•';

    return white_checkers;
}
void motion_white_checkers(char* white_checkers,char* black_checkers, int size, char size_pole[][8], bool check, char empty)            // проверка хода белых шашек по правилу первого хода
{
    int a{ 0 }, b{ 1 }, c{ 2 }, d{ 3 }, e{ 4 }, f{ 5 }, g{ 6 }, h{ 7 };
    bool white{ true };
    char motion = 'Ї';                                                                                                                // возможные ходы
    int x_IN{}, x_OU{};                                                                                                               // координаты
    int y_IN{}, y_OU{};
    int number{};
    char x_test{},y_test{};
    int m{ 5 }, n{ 0 };
    while (m > n)
    {
        if (white == true)
        {
        /*if (check == 0)
        {*/

            cout << "\nВы играете белыми (снизу)" << endl;
            for (int i = 0; i < 8; i += 2)
                size_pole[5][i] = motion;

            print_pole(size, size_pole);

            cout << '\n' << "Выберете шашку: ";
            cin >> y_test;
            cin >> x_test;

            for (int i = 1; x_IN <= 8; i++)
            {
                if (x_test == (i + 48))
                {
                    x_IN = i;
                    x_IN -= 1;
                    //cout << x_IN << endl;
                    break;
                }
            }
            for (int i = 1; y_IN <= 8; i++)
            {
                if (y_test == (i + 96))
                {
                    y_IN = i;
                    y_IN -= 1;
                    //cout << y_IN << endl;
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
                    //cout << x_OU << endl;
                    break;
                }
            }
            for (int i = 1; y_OU <= 8; i++)
            {
                if (y_test == (i + 96))
                {
                    y_OU = i;
                    y_OU -= 1;
                    //cout << y_OU << endl;
                    break;
                }
            }

            for (int i = 0, k = 0; i < 8; i += 2, k++)
                size_pole[5][i] = white_checkers[k];
            if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
            {
                swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                size_pole[x_OU][y_OU] = white_checkers[0];
                print_pole(size, size_pole);
            }
            else
                cout << "!!!!!!!!!ОШИБОЧНЫЙ ДОЛБАЁБ!!!!!!!" << endl;
        /*}*/
        white = false;
        n++;
        }
        else if (white == false)
        {
            /*if (check == 1)
            {*/

            cout << "Вы играете чёрными (сверху)" << endl;
            for (int i = 1; i < 8; i += 2)
                size_pole[2][i] = motion;

            print_pole(size, size_pole);

            cout << '\n' << "Выберете шашку: ";
            cin >> y_test;
            cin >> x_test;

            for (int i = 1; x_IN <= 8; i++)
            {
                if (x_test == (i + 48))
                {
                    x_IN = i;
                    x_IN -= 1;
                    //cout << x_IN << endl;
                    break;
                }
            }
            for (int i = 1; y_IN <= 8; i++)
            {
                if (y_test == (i + 96))
                {
                    y_IN = i;
                    y_IN -= 1;
                    //cout << y_IN << endl;
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
                    //cout << x_OU << endl;
                    break;
                }
            }
            for (int i = 1; y_OU <= 8; i++)
            {
                if (y_test == (i + 96))
                {
                    y_OU = i;
                    y_OU -= 1;
                    //cout << y_OU << endl;
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
        /*}*/
        white = true;
        n++;
        }
    }
        
}
