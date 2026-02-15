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
        std::cout << "\n\n";//\n\n";
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
            std::cout << "\n\t \t   Одиночная игра" << endl;
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