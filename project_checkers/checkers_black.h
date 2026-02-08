#pragma once
using namespace std;

char* checkers_black()
{
    static const int size_black{ 12 };
    static char black_checkers[size_black]{};

    for (int i = 0; i < size_black; i++)
        //black_checkers[i] = 'B';
        black_checkers[i] = '°';

    return black_checkers;
}
