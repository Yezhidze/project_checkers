#include <iostream>
#include <windows.h>
#include "checkers_white.h"
#include "checkers_black.h"
#include "pole_checkers.h"

using namespace std;

void checkers_pole();
void print_pole(int size, char size_pole[][8]);

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    system("cls");
    checkers_pole();

    return 0;
}