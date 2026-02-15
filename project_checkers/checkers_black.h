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

int eat2{ 0 };

void motion_black_checkers(char* white_checkers, char* black_checkers, int size, char size_pole[][8], bool check, char empty, int *ptr_number_white)            // ïðîâåðêà õîäà ÷¸ðíûõ øàøåê
{
    bool white{ true };
    char motion = '¯';                                                                                                                // âîçìîæíûå õîäû
    int x_IN{-1}, x_OU{-1};                                                                                                               // êîîðäèíàòû
    int y_IN{-1}, y_OU{-1};
    int number{};
    char x_test{}, y_test{};

    if (check == 1)
    {
        cout << "\t\t\t\t\t Âû èãðàåòå ÷¸ðíûìè (ñâåðõó)" << endl;

        if (eat2 == 1)
        {
            swap(size_pole[2][1], size_pole[4][7]);
            eat2++;
        }

        bool xy_test = true;
        while (xy_test)
        {
            while (size_pole[x_IN][y_IN] != '¯')
            {
                check_to_go(size_pole, '°', 1);

                cout << "\t\t\t\t\t Õîä ÷¸ðíûìè." << endl;
                cout << '\n' << "\t\t\t\t\t Âûáåðåòå øàøêó: ";
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
            }
            if (((x_IN >= 0) && (x_IN <= 7)) && ((y_IN >= 0) && (y_IN <= 7)))
                xy_test = false;
            else
                xy_test = true;
        }
        xy_test = true;
        int neighboring_cell = 0;

        if ((size_pole[x_IN + 1][y_IN + 1] == '•') &&
            (size_pole[x_IN + 2][y_IN + 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN + 1][y_IN - 1] == '•') &&
            (size_pole[x_IN + 2][y_IN - 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN - 2) >= 0) ||

            (size_pole[x_IN - 1][y_IN + 1] == '•') &&
            (size_pole[x_IN - 2][y_IN + 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN - 1][y_IN - 1] == '•') &&
            (size_pole[x_IN - 2][y_IN - 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN - 2) >= 0))
        {
            cout << '\n' << "\t\t\t\t\t Ðÿäîì âðàã ";
            neighboring_cell = 1;
        }
        
        bool check_l = true;
        bool check_border = true;
        while (check_l)
        {
            while (xy_test)
            {
                while (check_border)
                {
                    cout << '\n' << "\t\t\t\t\t Âûáåðåòå êóäà ñõîäèòü: ";
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
                    if(size_pole[x_OU][y_OU] == ' ')
                        check_border = false;
                }
                if (((x_OU >= 0) && (x_OU <= 7)) && ((y_OU >= 0) && (y_OU <= 7)))
                    xy_test = false;
                else
                    xy_test = true;
            }
            // a6b5b3a4c6d5a4
            check_to_go(size_pole, '°', 2);

            if (neighboring_cell == 0)
            {
                if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
                {
                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                    size_pole[x_OU][y_OU] = black_checkers[0];
                    print_pole(size, size_pole);
                    check_l = false;
                }
                else
                {
                    check_border = true;
                    xy_test = true;
                }
                    /*cout << "!!!!!!!!!ÎØÈÁÎ×ÍÛÉ ÄÎËÁÀ¨Á!!!!!!!" << endl;*/
            }
            else if (neighboring_cell == 1)
            {
                int xs{}, ys{};
                if (x_IN > x_OU)
                    xs = x_IN - 1;
                else
                    xs = x_OU - 1;
                if (y_IN > y_OU)
                    ys = y_IN - 1;
                else
                    ys = y_OU - 1;
                if (size_pole[xs][ys] == '•')
                {
                    size_pole[xs][ys] = ' ';
                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                    *ptr_number_white -= 1;
                    check_l = false;
                }
                //else if (size_pole[xs][ys] != '•')
                else
                {
                    check_border = true;
                    xy_test = true;
                }
                    /*cout << "!!!!!!!!!ÎØÈÁÎ×ÍÛÉ ÄÎËÁÀ¨Á!!!!!!!" << endl;*/
            }
        }
    }
    else if (check == 2)
    {
        cout << "\n\t\t\t\t\t Âû èãðàåòå ÷¸ðíûìè (ñíèçó)" << endl;
        for (int i = 0; i < 8; i += 2)
            size_pole[5][i] = motion;

        //print_pole(size, size_pole);

        bool xy_test = true;
        while (xy_test)
        {
            while (size_pole[x_IN][y_IN] != '¯')
            {
                check_to_go(size_pole, '°', 1);

                cout << "\t\t\t\t\t Õîä ÷¸ðíûìè." << endl;
                cout << '\n' << "\t\t\t\t\t Âûáåðåòå øàøêó: ";
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
            }
            if (((x_IN >= 0) && (x_IN <= 7)) && ((y_IN >= 0) && (y_IN <= 7)))
                xy_test = false;
            else
                xy_test = true;
        }
        xy_test = true;
        int neighboring_cell = 0;
        if ((size_pole[x_IN + 1][y_IN + 1] == '•') &&
            (size_pole[x_IN + 2][y_IN + 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN + 1][y_IN - 1] == '•') &&
            (size_pole[x_IN + 2][y_IN - 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN - 2) >= 0) ||

            (size_pole[x_IN - 1][y_IN + 1] == '•') &&
            (size_pole[x_IN - 2][y_IN + 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN - 1][y_IN - 1] == '•') &&
            (size_pole[x_IN - 2][y_IN - 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN - 2) >= 0))
        {
            cout << '\n' << "\t\t\t\t\t Ðÿäîì âðàã ";
            neighboring_cell = 1;
        }
        bool check_l = true;
        while (check_l)
        {
            while (xy_test)
            {
                cout << '\n' << "\t\t\t\t\t Âûáåðåòå êóäà ñõîäèòü: ";
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
                if (((x_OU >= 0) && (x_OU <= 7)) && ((y_OU >= 0) && (y_OU <= 7)))
                    xy_test = false;
                else
                    xy_test = true;
            }

            check_to_go(size_pole, '•', 2);

            if (neighboring_cell == 0)
            {
                if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
                {
                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                    size_pole[x_OU][y_OU] = black_checkers[0];
                    print_pole(size, size_pole);
                    check_l = false;
                }
                else
                    cout << "!!!!!!!!!ÎØÈÁÎ×ÍÛÉ ÄÎËÁÀ¨Á!!!!!!!" << endl;
            }
            else if (neighboring_cell == 1)
            {
                int xs{}, ys{};
                if (x_IN > x_OU)
                    xs = x_IN - 1;
                else
                    xs = x_OU - 1;
                if (y_IN > y_OU)
                    ys = y_IN - 1;
                else
                    ys = y_OU - 1;
                if (size_pole[xs][ys] == '°')
                {
                    size_pole[xs][ys] = ' ';
                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                    *ptr_number_white -= 1;
                    check_l = false;
                }
                else
                    cout << "!!!!!!!!!ÎØÈÁÎ×ÍÛÉ ÄÎËÁÀ¨Á!!!!!!!" << endl;
            }
        }
    }
}