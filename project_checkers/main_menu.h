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
void checkers_pole();

/* Меню последовательность.
    1. Начать игру.
    2. Настройки музыки вкл\выкл
    3. Выход (при нажатии на выход должен выходить из игры)
    
    Подмененю для Начать игру:
    Выберете режим игры
    1. Одиночная игра.
    2. Игрок с игроком.
    3. Выход в главное меню.
    
    При нажатии на режим "Одиночный режим" должен отправлять в функцию с одиночной игрой 
    (его пока что нет, по этому напиши код без функции и закоментируй).

    При нажатии на режим "Игрок с игроком" должен отправлять в фунцию checkers_pole().

    При нажатии на "Выход в главное меню" должен отправлять в главное меню.
    
    ТАК ЖЕ ВАЖНО СОБЛЮДАТЬ ПРАВИЛА УСЛОВИЙ,
    ЕСЛИ ПОЛЬЗОВАТЕЛЬ НАЖАЛ НЕВЕРНУЮ ЦИФРУ
    ВЫВОДИТЬ ЧТО-ТО ТИПА "НЕВЕРНЫЙ ВЫБОР" И ПОВТОРНО 
    ОТПРАВЛЯТЬ В МЕНЮ НА КОТОРОМ ОН ОШИБСЯ!!!!!!!!!! (ТЕКУЩЕЕ МЕНЮ)*/

void showAsciiArt() {
    // Установка локали для широких символов
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
        wcout << L"\t\t" << art_lines[i] << endl;
    }
   wcout << L"\n\n";
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\t\t              Нажмите Enter для продолжения...";
    cin.get();
    system("cls");
    menu();
}

void menu()
{
    
    int choice = 0;
    int checker_type = 1;
    int checker_color = 0;
    int player = 1;

    while (true)
    {
        std::cout << "\n ========\t ОСНОВНОЕ МЕНЮ \t    ======== \n " << endl;
        std::cout << "  \t \t 0. Показать текущие настройки \t" << endl;
        std::cout << "  \t \t 1. Выбрать игрока" << endl;
        std::cout << "  \t \t 2. Выбрать цвет шашек" << endl;
        std::cout << "  \t \t 3. Начать игру" << endl;
        std::cout << "  \t \t 4. Выход" << endl;
        std::cout << "  \t \t    Ваш выбор: \n \n ";

        if (player != 0 && checker_color != 0)
        {


            if (player == 1 && checker_color == 1)
            {
                std::cout << "\t \t " << player << " Одиночная игра" << endl;
                std::cout << "\t \t " << checker_color << " Вы вебрали белые шашки" << endl;
            }
            else if (player == 2 && checker_color == 2)
            {
                std::cout << "\t \t " << player << " Игра на двои" << endl;
                std::cout << "\t \t " << checker_color << " Вы вебрали черные шашки" << endl;
            }
            else
            {
                std::cout << "\t \t Неправельный выбор " << endl;
            }
        }
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            std::cout << "\n \t ========\tМЕНЮ \t ======== \n " << endl;
            std::cout << " \t \t  Выбор игрока  \n" << endl;
            if (player == 1)
            {
                std::cout << " \t \t   Выбор игрока  " << endl;
                std::cout << " \t \t 1 Одиночная игра " << endl;
                std::cout << " \t \t 2 Игра на двоих \n" << endl;
                std::cout << " \t \t   Ваш выбор: ";
                std::cin >> player;

                if (player == 1)
                {
                    std::cout << " \n \t \t  Одиночная игра  " << endl;
                }
                else if (player == 2)
                {
                    std::cout << " \n \t \t  Игра на двоих " << endl;
                }
                else
                {
                    std::cout << "Неверный выбор " << endl;
                    player = 0;
                }
            }
            std::cout << " \n \t \t   Нажмите Enter для продолжения...";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;

        case 2:

            std::cout << "\n \t ========\tМЕНЮ \t ======== \n " << endl;
            std::cout << " \t \t  Текущие настройки: \n" << endl;
            std::cout << "  \t \t    Выбрать цвет шашек" << endl;
            std::cout << "  \t \t    Ваш выбор: ";

            if (checker_color == 0)
            {
                std::cout << " \t \t   Выберите цвет шашек:" << endl;
                std::cout << " \t \t 1 Белые шашки" << endl;
                std::cout << " \t \t 2 Черные шашки \n" << endl;
                std::cout << " \t \t   Ваш выбор: ";
                std::cin >> checker_color;

                if (checker_color == 1)
                {
                    std::cout << " \n \t \t   Вы вебрали белые шашки " << endl;
                }
                else if (checker_color == 2)
                {
                    std::cout << " \n \t \t   Вы вебрали черные шашки " << endl;
                }
                else
                {
                    std::cout << "Неверный выбор " << endl;
                    checker_color = 0;
                }
            }
            std::cout << " \n \t \t   Нажмите Enter для возврата в меню...";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;

        case 3:
            std::cout << "\n \t ========\tНАЧАЛО ИГРЫ \t ======== \n " << endl;

            if (player == 0 || checker_color == 0)
            {

                std::cout << " \t \t   Ошибка: не все настройки выбраны!" << std::endl;

                if (player == 0)
                {
                    std::cout << " \t \t   - Выберите режим игры" << std::endl;
                }

                if (checker_color == 0)
                {
                    std::cout << " \t \t   - Выберите цвет шашек" << std::endl;
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
                checkers_pole();
            }
            std::cout << " \n \t \t   Нажмите Enter для возврата в меню...";
            std::cin.ignore();
            std::cin.get();
            system("cls");
            break;

        case 4:
            cout << "\n \t ========\tВЫХОД \t ======== \n " << endl;
            std::cout << "Выход из программы." << endl;
            break;
        default:
            cout << " \n \t \t   Неверный выбор. Попробуйте снова." << endl;
            cout << " \t \t   Нажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }

    }
}