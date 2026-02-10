//#pragma once
//#include "pole_checkers.h"
//using namespace std;
//
//int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);
//void checkers_pole();
//void print_pole(int size, char size_pole[][8]);
//
//char* white_checkers()
//{
//    static const int size_whites{ 12 };
//    static char white_checkers[size_whites]{};
//
//    for (int i = 0; i < size_whites; i++)
//        white_checkers[i] = '•';
//
//    return white_checkers;
//}
//void motion_white_checkers(char* white_checkers, char* black_checkers, int size, char size_pole[][8], bool check, char empty)            // проверка хода белых шашек по правилу первого хода
//{
//    int a{ 0 }, b{ 1 }, c{ 2 }, d{ 3 }, e{ 4 }, f{ 5 }, g{ 6 }, h{ 7 };
//    bool white{ true };
//    char motion = 'Ї';                                                                                                                // возможные ходы
//    int x_IN{}, x_OU{};                                                                                                               // координаты
//    int y_IN{}, y_OU{};
//    int number{};
//    char x_test{}, y_test{};
//    if (white == true)
//    {
//        if (check == 0)
//        {
//
//            cout << "Вы играете белыми (снизу)" << endl;
//            for (int i = 0; i < 8; i += 2)
//                size_pole[5][i] = motion;
//
//            cout << size_pole[2][1] << endl;
//            cout << size_pole[4][1] << endl;
//            swap(size_pole[2][1], size_pole[4][1]);
//            print_pole(size, size_pole);
//
//            cout << '\n' << "Выберете шашку: ";
//            cin >> y_test;
//            cin >> x_test;
//
//            for (int i = 1; x_IN <= 8; i++)
//            {
//                if (x_test == (i + 48))
//                {
//                    x_IN = i;
//                    x_IN -= 1;
//                    cout << x_IN << endl;
//                    break;
//                }
//            }
//            for (int i = 1; y_IN <= 8; i++)
//            {
//                if (y_test == (i + 96))
//                {
//                    y_IN = i;
//                    y_IN -= 1;
//                    cout << y_IN << endl;
//                    break;
//                }
//            }
//            int neighboring_cell = 0;
//            if (size_pole[x_IN - 1][y_IN + 1] == '°' || size_pole[x_IN - 1][y_IN - 1] == '°')
//            {
//                cout << '\n' << "Рядом варг ";
//                neighboring_cell = 1;
//            }
            //bool check_l = true;
            //while (check_l == true)
            //{
            //    cout << '\n' << "Выберете куда сходить: ";
            //    cin >> y_test;
            //    cin >> x_test;
            //    for (int i = 1; x_OU <= 8; i++)
            //    {
            //        if (x_test == (i + 48))
            //        {
            //            x_OU = i;
            //            x_OU -= 1;
            //            cout << x_OU << endl;
            //            break;
            //        }
            //    }
            //    for (int i = 1; y_OU <= 8; i++)
            //    {
            //        if (y_test == (i + 96))
            //        {
            //            y_OU = i;
            //            y_OU -= 1;
            //            cout << y_OU << endl;
            //            break;
            //        }
            //    }

            //    check_to_go(size_pole, '•', 2);

            //    if (neighboring_cell == 0)
            //    {
            //        if ((x_OU - x_IN == 1 || x_OU - x_IN == -1) && (y_OU - y_IN == 1 || y_OU - y_IN == -1))
            //        {

            //            swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
            //            size_pole[x_OU][y_OU] = white_checkers[0];
            //            print_pole(size, size_pole);
            //            check_l = false;
            //        }
            //        else
            //            cout << "!!!!!!!!!ОШИБОЧНЫЙ ДОЛБАЁБ!!!!!!!" << endl;
            //    }
            //    else if (neighboring_cell == 1)
            //    {
            //        int xs{}, ys{};
            //        if (x_IN > x_OU)
            //            xs = x_IN - 1;
            //        else
            //            xs = x_OU - 1;
            //        if (y_IN > y_OU)
            //            ys = y_IN - 1;
            //        else
            //            ys = y_OU - 1;
            //        if (size_pole[xs][ys] == '°')
            //        {
            //            size_pole[xs][ys] = ' ';
            //            swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
            //            check_l = false;
            //        }
            //        else
            //            cout << "!!!!!!!!!ОШИБОЧНЫЙ ДОЛБАЁБ!!!!!!!" << endl;
            //    }
            //}
//        }
//        white = false;
//    }
//    else if (white == false)
//    {
//
//    }
//}

//#pragma once
//#include "pole_checkers.h"
//using namespace std;
//
//
//
//
//
//char* white_checkers()
//{
//    static const int size_whites{ 12 };
//    static char white_checkers[size_whites]{};
//
//    for (int i = 0; i < size_whites; i++)
//        //white_checkers[i] = 'W';
//        white_checkers[i] = 149;
//
//    return white_checkers;
//}
//void motion_white_checkers(char* white_checkers,char* black_checkers, int size, char size_pole[][8], bool check, char black)            // проверка хода белых шашек по правилу первого хода
//{
//    /*int a{ 0 }, b{ 1 }, c{ 2 }, d{ 3 }, e{ 4 }, f{ 5 }, g{ 6 }, h{ 7 };*/
//    bool white{ true };
//    char motion = 175;                                                                                                                 // возможные ходы
//    int x_IN{}, x_OU{};                                                                                                               // координаты
//    int y_IN{}, y_OU{};
//    int number{};
//    if (white == true)
//    {
//        if (check == 0)
//        {
//            
//            cout << "Вы играете белыми (снизу)" << endl;
//            for (int i = 0; i < 8; i += 2)
//                size_pole[5][i] = motion;
//
//            print_pole(size, size_pole);
//
//            cout << '\n' << "Введите координаты шашки для выбора х : ";
//            cin >> x_IN;
//            cout << '\n' << "Введите координаты шашки для выбора у : ";
//            cin >> y_IN;
//            /*y_IN -= 1;*/
//            cout << '\n' << "Введите координаты поля для хода х: ";
//            cin >> x_OU;
//            cout << '\n' << "Введите координаты поля для хода у: ";
//            cin >> y_OU;
//            /*y_OU -= 1;*/
//            int xs{}, ys{};
//            if (x_IN > x_OU)
//                xs = x_IN - 1;
//            else 
//                xs = x_OU - 1;
//            if (y_IN > y_OU)
//                ys = y_IN - 1;
//            else
//                ys = y_OU - 1;
//
//            if (size_pole[xs][ys] != '°')
//            {
//                if (size_pole[xs][ys] == -80)
//                {
//                    size_pole[xs][ys] = 120;
//                    swap(size_pole[x_OU][y_OU], size_pole[x_IN][y_IN]);
//                    size_pole[x_IN][y_IN] = '°';
//                }
//            }
//            else
//                swap(size_pole[x_OU][y_OU],size_pole[x_IN][y_IN]);
//            /*for (int i = 0, k = 0; i < 8; i += 2, k++)
//                size_pole[5][i] = white_checkers[k];
//            size_pole[x_OU][y_OU] = white_checkers[0];
//            size_pole[x_IN][y_IN] = black;*/
//            system("cls");
//
//        }
//        white = false;
//    }
//    else if (white == false)
//    {
//
//    }
//    
//    //int start_pos = 0;
//    //int nev_pos = 0;
//    //cout << " Выбор свободной шашки ";
//    //cout << " Ваши кординаты " << "( Ваша позиция 'A' на доске)" << endl;
//    //cout << " Введите текущую позицию шашки (0-31): " << endl;
//    //cin >> start_pos;
//    //if (start_pos >= 0 && start_pos < 32)
//    //{
//    //    if (white_checkers[start_pos] == 'W')
//    //    {
//    //        cout << "Найдена шашка на позиции " << start_pos << endl;
//    //        cout << "Введите новую позицию (0-31): ";
//    //        cin >> nev_pos;
//    //        if (nev_pos >= 0 && nev_pos < 32)
//    //        {
//    //            if (checkers_position[nev_pos] == 0) // проверка возможности хода 
//    //            {
//    //                white_checkers[start_pos] = 0;
//    //                white_checkers[nev_pos] = 1;
//    //                checkers_position[nev_pos] = 1;
//    //            }
//
//    //        }
//    //    }
//    //}
//}
////int a1 = size_pole[0][0]
////int a2 = size_pole[0][1]
////int a3 = size_pole[0][2]
////int a4 = size_pole[0][3]
////int a5 = size_pole[0][4]
////int a6 = size_pole[0][5]
////int a7 = size_pole[0][6]
////int a8 = size_pole[0][7]
////int a = 0
////int xy