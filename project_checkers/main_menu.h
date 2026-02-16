#pragma once
//#include <iostream>
//#include <cstdlib> 
//#include <windows.h>
//#include <fcntl.h>
//#include <io.h>
//#include "pole_checkers.h"

#include "pole_checkers.h"
#include "Music.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

void showAsciiArt();
void menu();
void podmenu();
void setting();

void checkers_pole();

int Music();
void Music_Paused();
void Music_Playing();

void showAsciiArt() {

    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcout.imbue(locale("ru_RU.UTF-8"));

    const wchar_t* art_lines[] =
    {
        L"╔════════════════════════════════════════════════════════════╗",
        L"║                                                            ║",
        L"║   ██╗  ██╗  ██╗  ████═╗ ██╗  ██╗  ██╗ ██╗ ██╗ ██╗   ╔██╗   ║",
        L"║   ██║  ██║  ██║ ██║ ██║ ██║  ██║  ██║ ██║██╔╝ ██║  █║██║   ║",
        L"║   ██║  ██║  ██║ ██║ ██║ ██║  ██║  ██║ ███╠═╣  ██║ █╔╝██║   ║",
        L"║   ██║  ██║  ██║ ██████║ ██║  ██║  ██║ ██║██╚╗ ██║█╔╝ ██║   ║",
        L"║   ████████████║ ██║ ██║ ████████████║ ██║ ██║ ██╠═╝  ██║   ║",
        L"║   ╚═══════════╝ ╚═╝ ╚═╝ ╚═══════════╝ ╚═╝ ╚═╝ ╚═╝    ╚═╝   ║",
        L"║               ██╗                       ██╗                ║",
        L"║       ███████╗██║ ████═╗███████╗███████╗╚═╝███████╗        ║",
        L"║       ██╔════╝██║██║ ██║██╔════╝██╔════╝██╗██╔════╝        ║",
        L"║       ██║     ██║██║ ██║███████╗███████╗██║██║             ║",
        L"║       ██║     ██║██████║╚════██║╚════██║██║██║             ║",
        L"║       ███████╗██║██║ ██║███████║███████║██║███████╗        ║",
        L"║       ╚══════╝╚═╝╚═╝ ╚═╝╚══════╝╚══════╝╚═╝╚══════╝        ║",
        L"║                                                            ║",
        L"╠════════════════════════════════════════════════════════════╣",
        L"║                  ДОБРО ПОЖАЛОВАТЬ В ИГРУ!                  ║",
        L"╚════════════════════════════════════════════════════════════╝"
    };

    //wcout << L"\n\n";
    for (int i = 0; i < 19; i++)
    {
        wcout << L"\t\t\t" << art_lines[i] << endl;
    }
    wcout << L"\n\n";

    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Music();

    cout << "\t\t\t\t\tНажмите Enter для продолжения...";
    cin.get();
    
    menu();
}

void menu()
{
    setlocale(LC_ALL, "ru");

    char choice{};

    while (choice != '1' || choice != '2' || choice != '0')
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|         ГЛАВНОЕ МЕНЮ        |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|        1. Начать игру       |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|        2. Настройки         |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|        0. Выход             |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t \t Ваш выбор: ";
        std::cin >> choice;

        if (choice == '1')
            podmenu();
        else if (choice == '2')
            setting();
        else if (choice == '0')
            exit(1);
    }
}

void podmenu()
{
    char player{};

    while (player != '1' || player != '2' || player != '0')
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|         РЕЖИМ ИГРЫ          |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      1. Одиночная игра      |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      2. Игрок с игроком     |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      0. Выход               |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t      Ваш выбор: ";
        std::cin >> player;

        if (player == '1')
            cout << "Одиночная игра!" << endl;
        else if (player == '2')
            checkers_pole();
        else if (player == '0')
            menu();
    }
}

void setting()
{
    char player{};

    while (player != '1' || player != '2' || player != '0')
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|     1. Включить Музыку      |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|     2. Выключить Музыку     |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      0. Выход               |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t      Ваш выбор: ";
        std::cin >> player;

        if (player == '1')
            Music_Playing();
        else if (player == '2')
            Music_Paused();
        else if (player == '0')
            menu();
    }

}

int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers)
{
    char player{};
    int number{};

    while (player != '1' || player != '2' || player != '0')
    {
        system("cls");
        std::cout << "\n\n";
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|        Выбор шашки          |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      1. Белая шашка - •     |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      2. Черная шашка - °    |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t|      0. Выход               |\t" << endl;
        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
        std::cout << "\t\t\t\t \t      Ваш выбор: ";
        std::cin >> player;

        if (player == '1')
            break;
        else if (player == '2')
            break;
        else if (player == '0')
            podmenu();
    }
    number = player - '0';

    if (number == 1)
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
    else if (number == 2)
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
    return number;
}