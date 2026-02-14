#pragma once
//#include <windows.h>
// //#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int Music()
{
    setlocale(LC_ALL, "ru");

    bool isPlaying = false;
    bool isPaused = false;

    DWORD volume = 0x500;                                                  // Можно регулировать громкость музыки
    waveOutSetVolume(NULL, MAKELONG(volume, volume));

    BOOL result = PlaySound(TEXT("8bit.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    isPlaying = true;

    if (!result) {
        cerr << "Ошибка воспроизведения! Код: " << GetLastError() << endl;  //Это проверка ошибок
        return -1;
    }

    return 0;
}

void Music_Paused()
{
    PlaySound(NULL, NULL, 0);

    //return 0;
}
void Music_Playing()
{
    PlaySound(TEXT("8bit.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    //return 0;
}
