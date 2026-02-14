//#pragma once
//
//
//#include <iostream>
//#include <cstdlib> 
//#include <windows.h>
//#include <fcntl.h>
//#include <io.h>
//
//using namespace std;
//
//
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")
//#include "MusicTest.h"
////#include "pole_checkers.h"
//
//using namespace std;
//int Music();
//void showAsciiArt();
//
//void menu();
//void podmenu();
//void setting();
//int Music_Paused();
//int Music_Playing();
////void menu();
////void checkers_pole();
////void showAsciiArt() 
////
////{
////    // Установка локали для широких символов
////    setlocale(LC_ALL, "ru_RU.UTF-8");
////    wcout.imbue(locale("ru_RU.UTF-8"));
////
////    const wchar_t* art_lines[] =
////    {
////        L"╔════════════════════════════════════════════════════════════╗",
////        L"║                                                            ║",
////        L"║    ██████╗ ██╗  ██╗ █████╗ ███████╗██╗  ██╗██╗███████╗     ║",
////        L"║    ██╔══██╗██║  ██║██╔══██╗██╔════╝██║ ██╔╝██║██╔════╝     ║",
////        L"║    ██████╔╝███████║███████║███████╗█████╔╝ ██║███████╗     ║",
////        L"║    ██╔═══╝ ██╔══██║██╔══██║╚════██║██╔═██╗ ██║╚════██║     ║",
////        L"║    ██║     ██║  ██║██║  ██║███████║██║  ██╗██║███████║     ║",
////        L"║    ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝╚══════╝     ║",
////        L"║                                                            ║",
////        L"║              ███████╗██╗  ██╗██╗ █████╗ ██╗                ║",
////        L"║              ██╔════╝██║  ██║██║██╔══██╗██║                ║",
////        L"║              ███████╗███████║██║███████║██║                ║",
////        L"║              ╚════██║██╔══██║██║██╔══██║██║                ║",
////        L"║              ███████║██║  ██║██║██║  ██║██║                ║",
////        L"║              ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝                ║",
////        L"║                                                            ║",
////        L"╠════════════════════════════════════════════════════════════╣",
////        L"║                  ДОБРО ПОЖАЛОВАТЬ В ИГРУ!                  ║",
////        L"╚════════════════════════════════════════════════════════════╝"
////    };
////
////    wcout << L"\n\n";
////    for (int i = 0; i < 19; i++)
////    {
////        wcout << L"\t\t\t" << art_lines[i] << endl;
////    }
////    wcout << L"\n\n";
////    setlocale(LC_ALL, "ru");
////    SetConsoleCP(1251);
////    SetConsoleOutputCP(1251);
////    Music();
////    cout << "\t\t\t\t\tНажмите Enter для продолжения...";
////    cin.get();
////    system("cls");
//// /*   menu();*/
////}
//
//int main()
//{
//    showAsciiArt();
//
//
//    return 0;
//}
//void showAsciiArt() {
//
//    setlocale(LC_ALL, "ru_RU.UTF-8");
//    wcout.imbue(locale("ru_RU.UTF-8"));
//
//    const wchar_t* art_lines[] =
//    {
//        L"╔════════════════════════════════════════════════════════════╗",
//        L"║                                                            ║",
//        L"║   ██╗  ██╗  ██╗  ████═╗ ██╗  ██╗  ██╗ ██╗ ██╗ ██╗   ╔██╗   ║",
//        L"║   ██║  ██║  ██║ ██║ ██║ ██║  ██║  ██║ ██║██╔╝ ██║  █║██║   ║",
//        L"║   ██║  ██║  ██║ ██║ ██║ ██║  ██║  ██║ ███╠═╣  ██║ █╔╝██║   ║",
//        L"║   ██║  ██║  ██║ ██████║ ██║  ██║  ██║ ██║██╚╗ ██║█╔╝ ██║   ║",
//        L"║   ████████████║ ██║ ██║ ████████████║ ██║ ██║ ██╠═╝  ██║   ║",
//        L"║   ╚═══════════╝ ╚═╝ ╚═╝ ╚═══════════╝ ╚═╝ ╚═╝ ╚═╝    ╚═╝   ║",
//        L"║               ██╗                       ██╗                ║",
//        L"║       ███████╗██║ ████═╗███████╗███████╗╚═╝███████╗        ║",
//        L"║       ██╔════╝██║██║ ██║██╔════╝██╔════╝██╗██╔════╝        ║",
//        L"║       ██║     ██║██║ ██║███████╗███████╗██║██║             ║",
//        L"║       ██║     ██║██████║╚════██║╚════██║██║██║             ║",
//        L"║       ███████╗██║██║ ██║███████║███████║██║███████╗        ║",
//        L"║       ╚══════╝╚═╝╚═╝ ╚═╝╚══════╝╚══════╝╚═╝╚══════╝        ║",
//        L"║                                                            ║",
//        L"╠════════════════════════════════════════════════════════════╣",
//        L"║                  ДОБРО ПОЖАЛОВАТЬ В ИГРУ!                  ║",
//        L"╚════════════════════════════════════════════════════════════╝"
//    };
//
//    //wcout << L"\n\n";
//    for (int i = 0; i < 19; i++)
//    {
//        wcout << L"\t\t\t" << art_lines[i] << endl;
//    }
//    wcout << L"\n\n";
//
//    setlocale(LC_ALL, "ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    Music();
//    cout << "\t\t\t\t\tНажмите Enter для продолжения...";
//    cin.get();
//    system("cls");
//    menu();
//}
//
//void menu()
//{
//    setlocale(LC_ALL, "ru");
//
//    char choice{};
//
//    while (choice != '1' || choice != '2' || choice != '0')
//    {
//        std::cout << "\n\n";//\n\n";
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|         ГЛАВНОЕ МЕНЮ        |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|        1. Начать игру       |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|        2. Настройки         |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|        0. Выход             |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t \t Ваш выбор: ";
//        std::cin >> choice;
//
//        system("cls");
//
//        if (choice == '1')
//            podmenu();
//        else if (choice == '2')
//            setting();
//        else if (choice == '0')
//            exit(0);
//    }
//}
//
//void podmenu()
//{
//    char player{};
//
//    while (player != '1' || player != '2' || player != '0')
//    {
//        std::cout << "\n\n"; //\n\n";
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t| ======= РЕЖИМ ИГРЫ ======== |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|        Выбор игрока:        |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|      1. Одиночная игра      |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|      2. Игрок с игроком     |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|      0. Выход               |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t      Ваш выбор: ";
//        std::cin >> player;
//
//        system("cls");
//
//        if (player == '1')
//            std::cout << "\n\t \t   Одиночная игра" << endl;
//        else if (player == '2')
//            std::cout << "\n\t \t   Одиночная игра ff" << endl;
//        /* checkers_pole();*/
//        else if (player == '0')
//            menu();
//    }
//}
//void setting()
//{
//    char player{};
//
//    while (player != '1' || player != '2' || player != '0')
//    {
//
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|     1. Включить Музыку      |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|     2. Выключить Музыку     |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t|      0. Выход               |\t" << endl;
//        std::cout << "\t\t\t\t \t ----------------------------- \t" << endl;
//        std::cout << "\t\t\t\t \t      Ваш выбор: ";
//        std::cin >> player;
//
//        if (player == '1')
//            Music_Playing();
//        else if (player == '2')
//            Music_Paused();
//        else if (player == '0')
//            menu();
//    }
//
//}
//
//#pragma once
//#include <windows.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")
//#include <iostream>
//using namespace std;
//int Music_Paused();
//int Music()
//{
//    setlocale(LC_ALL, "ru");
//
//    bool isPlaying = false;
//    bool isPaused = false;
//
//    DWORD volume = 0x1000; // Можно регулировать это значение
//    waveOutSetVolume(NULL, MAKELONG(volume, volume));
//
//    /* cout << "Нажмите Enter для паузы, еще раз Enter для продолжения, 0+Enter для выхода" << endl;*/
//
//    BOOL result = PlaySound(TEXT("8bit.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//    isPlaying = true;
//
//    if (!result) {
//        cerr << "Ошибка воспроизведения! Код: " << GetLastError() << endl; //Это проверка ошибок
//        return -1;
//    }
//
//    //cout << " Музыка играет" << endl;
//    //while (true) 
//    //{
//    //    cin.get();
//
//    //    if (isPlaying && !isPaused) {
//
//    //        PlaySound(NULL, NULL, 0);
//    //        isPaused = true;
//    //        cout << " Пауза (Enter - продолжить, 0 - выход)" << endl;
//    //    }
//    //    else if (isPlaying && isPaused) {
//
//    //        PlaySound(TEXT("8bit.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//    //        isPaused = false;
//    //        cout << " Продолжение (Enter - пауза, 0 - выход)" << endl;
//    //    }
//    //    if (cin.peek() == '0') // Смотрит символ позволяет посмотреть, что пользователь ввел, 
//    //    {
//    //        cin.get();        // 	Читает символ
//    //        break;
//    //    }
//    //}
//
//    //PlaySound(NULL, NULL, 0);
//    //cout << "Звук остановлен! Программа завершена" << endl;
//
//    return 0;
//}
//
////int Music_Paused(bool isPlaying, bool isPaused)
//int Music_Paused()
//{
//    /* while (true)
//     {*/
//     /* cin.get();*/
//
//      /*if (isPlaying && !isPaused) {*/
//
//    PlaySound(NULL, NULL, 0);
//    /*  isPaused = true;
//      cout << " Пауза (Enter - продолжить, 0 - выход)" << endl;*/
//      /*}*/
//
//      //if (cin.peek() == '0') // Смотрит символ позволяет посмотреть, что пользователь ввел, 
//      //{
//      //    cin.get();        // 	Читает символ
//      //    break;
//      //}
// /* }*/
//
// /* PlaySound(NULL, NULL, 0);
//  cout << "Звук остановлен! Программа завершена" << endl;*/
//
//    return 0;
//}
//
////int Music_Playing(bool isPlaying, bool isPaused)
//int Music_Playing()
//{
//
//    /*  if (isPlaying && isPaused) {*/
//
//    PlaySound(TEXT("8bit.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//    /*  isPaused = false;
//      cout << " Продолжение (Enter - пауза, 0 - выход)" << endl;
//      }*/
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
