#pragma once
#include "pole_checkers.h"
#include "logic_game.h"
using namespace std;


int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);
void checkers_pole();
void print_pole(int size, char size_pole[][8]);
void check_to_go(char size_pole[][8], char check, int control);

char* white_checkers()
{
    static const int size_whites{ 12 };
    static char white_checkers[size_whites]{};
  /*  char *ptr_white_checkers = &white_checkers[size_whites];*/

    for (int i = 0; i < size_whites; i++)
        white_checkers[i] = '•';

    return white_checkers;
}

int eat1{ 0 };

void motion_white_checkers(char *ptr_white_checkers,char* black_checkers, int size, char size_pole[][8], bool check, char empty, int *ptr_number_black)            // проверка хода белых шашек по правилу первого хода
{
    bool white{ true };
    char motion = 'Ї';                                                                                                                // возможные ходы
    int x_IN{-1}, x_OU{ -1 };                                                                                                               // координаты
    int y_IN{ -1 }, y_OU{ -1 };
    int number{};
    char x_test{},y_test{};

    if (check == 1)
    {
        cout << "\n\t\t\t\t\t Вы играете белыми (снизу)" << endl;

        //if (eat1 == 1)
        //{
        //    swap(size_pole[2][1], size_pole[4][7]);
        //    eat1++;
        //}
        bool motion_check = true;
        bool xy_test = true;
        while(xy_test)
        {
            check_to_go(size_pole, '•', 1);

            cout << "\t\t\t\t\t Ход белыми." << endl;

            cout << '\n' << "\t\t\t\t\t Выберете шашку: ";
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
            if (((x_IN >= 0) && (x_IN <= 7)) && ((y_IN >= 0) && (y_IN <= 7)))
                if (size_pole[x_IN][y_IN] == 'Ї')
                    xy_test = false;
                else
                    xy_test = true;
            else
                xy_test = true;
        }
        xy_test = true;
        int neighboring_cell = 0;

        if ((size_pole[x_IN - 1][y_IN + 1] == '°') &&
            (size_pole[x_IN - 2][y_IN + 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN - 1][y_IN - 1] == '°') &&
            (size_pole[x_IN - 2][y_IN - 2] == ' ') &&
            ((x_IN - 2) >=0) && ((y_IN - 2) >= 0) ||

            (size_pole[x_IN + 1][y_IN + 1] == '°') &&
            (size_pole[x_IN + 2][y_IN + 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN + 1][y_IN - 1] == '°') &&
            (size_pole[x_IN + 2][y_IN - 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN - 2) >= 0))
        {
            cout << '\n' << "\t\t\t\t\t Рядом враг ";
            neighboring_cell = 1;
        }
        bool check_l = true;
        bool check_border = true;
        while (check_l )
        {
            while (xy_test)
            {
                /*while (check_border)
                {*/
                    cout << '\n' << "\t\t\t\t\t Выберете куда сходить: ";
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
                    
                //}
                 if (((x_OU >= 0) && (x_OU <= 7)) && ((y_OU >= 0) && (y_OU <= 7)))
                    if (size_pole[x_OU][y_OU] == ' ')
                    xy_test = false;
                    else
                        xy_test = true;
                    else
                        xy_test = true;
            }

            check_to_go(size_pole, '•', 2);

            if (neighboring_cell == 0)
            {
                if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
                {

                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                    size_pole[x_OU][y_OU] = *ptr_white_checkers;
                    print_pole(size, size_pole);
                    check_l = false;
                }
                else
                {
                    //check_border = true;
                    xy_test = true;
                }
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
                    *ptr_number_black -= 1;
                    check_l = false;
                    bool multi_kill{ true };
                    while (multi_kill)
                    {
                        if ((size_pole[x_OU - 1][y_OU + 1] == '°') &&
                            (size_pole[x_OU - 2][y_OU + 2] == ' ') &&
                            ((x_OU - 2) >= 0) && ((y_OU + 2) < 8) ||

                            (size_pole[x_OU - 1][y_OU - 1] == '°') &&
                            (size_pole[x_OU - 2][y_OU - 2] == ' ') &&
                            ((x_OU - 2) >= 0) && ((y_OU - 2) >= 0) ||

                            (size_pole[x_OU + 1][y_OU + 1] == '°') &&
                            (size_pole[x_OU + 2][y_OU + 2] == ' ') &&
                            ((x_OU + 2) < 8) && ((y_OU + 2) < 8) ||

                            (size_pole[x_OU + 1][y_OU - 1] == '°') &&
                            (size_pole[x_OU + 2][y_OU - 2] == ' ') &&
                            ((x_OU + 2) < 8) && ((y_OU - 2) >= 0))
                        {
                            check_to_go(size_pole, '•', 1);
                            xy_test = true;
                            while (xy_test)
                            {
                                check_to_go(size_pole, '•', 1);
                                cout << "\t\t\t\t\t Ход белыми." << endl;
                                cout << '\n' << "\t\t\t\t\t Выберете шашку: ";
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

                                if (((x_IN >= 0) && (x_IN <= 7)) && ((y_IN >= 0) && (y_IN <= 7)))
                                    if (size_pole[x_IN][y_IN] == 'Ї')
                                        xy_test = false;
                                    else
                                        xy_test = true;
                                    else
                                        xy_test = true;
                            }

                            cout << '\n' << "\t\t\t\t\t Выберете куда сходить: ";
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
                                *ptr_number_black -= 1;
                                check_to_go(size_pole, '•', 2);
                            }
                            multi_kill = true;
                        }
                        else
                            multi_kill = false;
                    }
                }
                else
                    xy_test = true;
            }
        }
        // комбинация за белых для проверки множественного поедания
        // a6b5d3e4g6h5b3c4b5d3d3f5a2b3b7a6b3c4c8b7h3g4f5h3e2d3h7g6d3e4g8h7d1e2c6b5f3g4
    } 
    else if (check == 2) 
    {
        cout << "\n\t\t\t\t\t Вы играете белыми (сверху)" << endl;
        //for (int i = 1; i < 8; i += 2)
        //    size_pole[2][i] = motion;

        bool xy_test = true;
        while (xy_test)
        {
            /*while 
            {*/
                check_to_go(size_pole, '•', 1);

                cout << "\t\t\t\t\t Ход белыми." << endl;
                cout << '\n' << "\t\t\t\t\t Выберете шашку: ";
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
            //}
            if (((x_IN >= 0) && (x_IN <= 7)) && ((y_IN >= 0) && (y_IN <= 7)))
                if (size_pole[x_IN][y_IN] == 'Ї')
                    xy_test = false;
                else
                    xy_test = true;
                else
                    xy_test = true;
        }
        xy_test = true;
        int neighboring_cell = 0;
        if ((size_pole[x_IN + 1][y_IN + 1] == '°') &&
            (size_pole[x_IN + 2][y_IN + 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN + 1][y_IN - 1] == '°') &&
            (size_pole[x_IN + 2][y_IN - 2] == ' ') &&
            ((x_IN + 2) < 8) && ((y_IN - 2) >= 0) ||

            (size_pole[x_IN - 1][y_IN + 1] == '°') &&
            (size_pole[x_IN - 2][y_IN + 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN + 2) < 8) ||

            (size_pole[x_IN - 1][y_IN - 1] == '°') &&
            (size_pole[x_IN - 2][y_IN - 2] == ' ') &&
            ((x_IN - 2) >= 0) && ((y_IN - 2) >= 0))
         {
            cout << '\n' << "\t\t\t\t\t Рядом враг ";
            neighboring_cell = 1;
         }
         bool check_l = true;
        while (check_l)
        {
            while (xy_test)
            {
                /*while 
                {*/
                    cout << '\n' << "\t\t\t\t\t Выберете куда сходить: ";
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
                //}
                if (((x_OU >= 0) && (x_OU <= 7)) && ((y_OU >= 0) && (y_OU <= 7)))
                    if (size_pole[x_OU][y_OU] != ' ')
                        xy_test = false;
                    else
                        xy_test = true;
                else
                    xy_test = true;
            }

            check_to_go(size_pole, '•', 2);

            if (neighboring_cell == 0)
            {
                if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
                {

                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
                    size_pole[x_OU][y_OU] = *ptr_white_checkers;
                    print_pole(size, size_pole);
                    check_l = false;
                }
                else
                {
                    //check_border = true;
                    xy_test = true;
                }
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
                    check_l = false;
                }
                else
                {
                    //check_border = true;
                    xy_test = true;
                }
            }
        }
    }
}
