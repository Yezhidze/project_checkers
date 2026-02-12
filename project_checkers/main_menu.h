#pragma once
//#include <iostream>
//#include <cstdlib> 
//#include <windows.h>
//#include <fcntl.h>
//#include <io.h>
//#include "pole_checkers.h"

//using namespace std;
void showAsciiArt();
void menu();

//#include "pole_checkers.h"
//void checkers_pole();
void showAsciiArt() {
    
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcout.imbue(locale("ru_RU.UTF-8"));

    const wchar_t* art_lines[] =
    {
        L"╔════════════════════════════════════════════════════════════╗",
        L"║                                                            ║",
        L"║    ██████╗ ██╗  ██╗ █████╗ ███████╗██╗  ██╗██╗███████╗     ║",
        L"║    ██╔══██╗██║  ██║██╔══██╗██╔════╝██║ ██╔╝██║██╔════╝     ║",
        L"║    ██████╔╝███████║███████║███████╗█████╔╝ ██║███████╗     ║",
        L"║    ██╔═══╝ ██╔══██║██╔══██║╚════██║██╔═██╗ ██║╚════██║     ║",
        L"║    ██║     ██║  ██║██║  ██║███████║██║  ██╗██║███████║     ║",
        L"║    ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝╚══════╝     ║",
        L"║                                                            ║",
        L"║              ███████╗██╗  ██╗██╗ █████╗ ██╗                ║",
        L"║              ██╔════╝██║  ██║██║██╔══██╗██║                ║",
        L"║              ███████╗███████║██║███████║██║                ║",
        L"║              ╚════██║██╔══██║██║██╔══██║██║                ║",
        L"║              ███████║██║  ██║██║██║  ██║██║                ║",
        L"║              ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝                ║",
        L"║                                                            ║",
        L"╠════════════════════════════════════════════════════════════╣",
        L"║                  ДОБРО ПОЖАЛОВАТЬ В ИГРУ!                  ║",
        L"╚════════════════════════════════════════════════════════════╝"
    };

    wcout << L"\n\n";
    for (int i = 0; i < 19; i++)
    {
        wcout << L"\t\t\t" << art_lines[i] << endl;
    }
    wcout << L"\n\n";
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\t\t\t\t\tНажмите Enter для продолжения...";
    cin.get();
    system("cls");
    /*   menu();*/
}

void menu()
{
    setlocale(LC_ALL, "ru");
    int choice = 0;
    int checker_type = 1;
    int checker_color = 0;
    int player = 1;
    showAsciiArt();
    while (true)
    {
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t|        ОСНОВНОЕ МЕНЮ         |\t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t|        1. Начать игру        |\t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t|        2.Настройки           |\t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;
        std::cout << "\t \t|        3.Выход               |\t" << endl;
        std::cout << "\t \t ------------------------------ \t" << endl;

        if (player != 0 && checker_color != 0)
        {
            if (player == 1 && checker_color == 1)
            {
                std::cout << " \t \t   - Одиночная игра" << std::endl;
                std::cout << " \t \t   - Белые шашки" << std::endl;
            }
            else if (player == 1 && checker_color == 2)
            {
                std::cout << " \t \t   - Одиночная игра" << std::endl;
                std::cout << " \t \t   - Черные шашки" << std::endl;
            }
            else if (player == 2 && checker_color == 1)
            {
                std::cout << " \t \t   - Игра на двоих" << std::endl;
                std::cout << " \t \t   - Белые шашки" << std::endl;
            }
            else if (player == 2 && checker_color == 2)
            {
                std::cout << " \t \t   - Игра на двоих" << std::endl;
                std::cout << " \t \t   - Черные шашки" << std::endl;
            }
            else
            {
                std::cout << " \t \t   Неправильный выбор настроек" << std::endl;
            }
        }
        std::cout << "    \t \t   Ваш выбор: ";
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            std::cout << "\t \t ------------------------------ \t" << endl;
            std::cout << "\t \t| ======= НАЧАЛА ИГРЫ ======== |\t" << endl;
            std::cout << "\t \t ------------------------------ \t" << endl;

            if (player == 0 || checker_color == 0)
            {

                std::cout << "  \t \t ------------------------------ \t" << endl;
                std::cout << "  \t \t|   Не все настройки выбраны!  |\t" << endl;
                std::cout << "  \t \t|   Необходимо выбрать:        |\t" << endl;
                std::cout << "  \t \t ------------------------------ \t" << endl;
                std::cout << "  \t \t ------------------------------ \t" << endl;
                std::cout << "  \t \t| Вернитесь в меню для выбора. |\t" << endl;
                std::cout << "  \t \t ------------------------------ \t" << endl;

                if (player == 0 || checker_color == 0)
                {
                    std::cout << "  \t \t ------------------------------ \t" << endl;
                    std::cout << "  \t \t|      Выберите режим игры     |\t" << endl;
                    std::cout << "  \t \t ------------------------------ \t" << endl;
                    std::cout << "  \t \t ------------------------------ \t" << endl;
                    std::cout << "  \t \t|      Выберите цвет шашек     |\t" << endl;
                    std::cout << "  \t \t ------------------------------ \t" << endl;
                }
            }
            else
            {
                std::cout << " \t \t   Игра начинается!" << std::endl;
                std::cout << " \t \t   Ваш выбор:" << std::endl;

                if (player == 1 && checker_color == 1)
                {
                    std::cout << " \t \t   - Одиночная игра" << std::endl;
                    std::cout << " \t \t   - Белые шашки" << std::endl;
                }
                else if (player == 1 && checker_color == 2)
                {
                    std::cout << " \t \t   - Одиночная игра" << std::endl;
                    std::cout << " \t \t   - Черные шашки" << std::endl;
                }
                else if (player == 2 && checker_color == 1)
                {
                    std::cout << " \t \t   - Игра на двоих" << std::endl;
                    std::cout << " \t \t   - Белые шашки" << std::endl;
                }
                else if (player == 2 && checker_color == 2)
                {
                    std::cout << " \t \t   - Игра на двоих" << std::endl;
                    std::cout << " \t \t   - Черные шашки" << std::endl;
                }
                else
                {
                    std::cout << " \t \t   Неправильный выбор настроек" << std::endl;
                }

                std::cout << " \n \t \t   Удачи в игре!" << std::endl;
                std::cin.get();
            }
            std::cout << " \n \t \t   Нажмите Enter для продолжения...";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;

        case 2:
        {
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|    ======== МЕНЮ ========    |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|         Выбор игрока:        |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|       1. Одиночная игра      |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|       2. Игрок с игроком     |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t   Выбор игрока: ";
            std::cin >> player;

            system("cls");

            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|     Выберите цвет шашек:     |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|         1. Белые шашки       |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t|         2. Черные шашки      |\t" << endl;
            std::cout << "  \t \t ------------------------------ \t" << endl;
            std::cout << "  \t \t   Выберите цвет шашек: ";
            std::cin >> checker_color;
            if (player == 1)
            {
                std::cout << "\n\t \t   Одиночная игра" << endl;
            }
            else if (player == 2)
            {
                std::cout << "\n\t \t   Игра на двоих" << endl;
            }
            else
            {
                std::cout << "\n  \t \t   Неверный выбор режима!" << endl;
                player = 0;
            }


            if (checker_color == 1)
            {
                std::cout << " \n \t \t   Вы выбрали белые шашки" << endl;
            }
            else if (checker_color == 2)
            {
                std::cout << " \n \t \t   Вы выбрали черные шашки" << endl;
            }
            else
            {
                std::cout << " \n \t \t   Неверный выбор цвета!" << endl;
                checker_color = 0;
            }

            std::cout << " \n \t \t   Нажмите Enter для возврата в меню...";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;
        }
        case 3:
            int a = 0;
            std::cout << "  \t \t -------------------------------------\t" << endl;
            std::cout << "  \t \t |                ВЫХОД              |\t" << endl;
            std::cout << "  \t \t -------------------------------------\t" << endl;
            std::cout << "  \t \t  ------------------------------------\t" << endl;
            std::cout << "  \t \t |   Если вы хотите выйте нажмите 1  |\t" << endl;
            std::cout << "  \t \t  ------------------------------------\t" << endl;
            std::cout << "  \t \t  ------------------------------------\t" << endl;
            std::cout << "  \t \t |Если вы хотите продолжить нажмите 2|\t" << endl;
            std::cout << "  \t \t  ------------------------------------\t" << endl;
            std::cout << "  \t \t   Ваш выбор: ";
            cin >> a;
            if (a == 1)
            {
                cout << "\n\t \t   Спосибо за выбор!" << endl;
                return 0;
            }
            else if (a == 2)
            {
                cout << "\n\t \t   Спосибо за выбор!" << endl;
            }
            std::cout << " \n \t \t   Нажмите Enter для возврата в меню...";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;

        }

    }
}