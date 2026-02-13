#include <iostream>
#include <windows.h>
//#include "checkers_white.h"
//#include "checkers_black.h"
#include "pole_checkers.h"
#include "main_menu.h" 

using namespace std;

void checkers_pole();
void print_pole(int size, char size_pole[][8]);

void showAsciiArt();
void menu();


using namespace std;

int main()
{
    //showAsciiArt();

    setlocale(LC_ALL, "ru");
    //SetConsoleOutputCP(65001); // UTF-8
    //SetConsoleCP(65001);
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    checkers_pole();

    return 0;
}