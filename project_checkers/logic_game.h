#pragma once
#include "main_menu.h"
#include "checkers_white.h"
#include "checkers_black.h"
#include "pole_checkers.h"

void print_pole(int size, char size_pole[][8]);
int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);

char motion = 'ѓ';
char *ptr_motion = &motion;
int eating{ 0 };

void return_to_go(char size_pole[][8], char check)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == *ptr_motion)
			{
				size_pole[i][j] = check;
			}
		}
	}
}

void white_to_go(char size_pole[][8], char check, int number)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == check || size_pole[i][j] == *ptr_motion)
			{
                if ((size_pole[i - 1][j + 1] == '∞') &&
                    (size_pole[i - 2][j + 2] == ' ') &&
                    //(size_pole[i - 2][j + 2] <= size_pole[0][7]) &&       // код исправил  »–»ЋЋ проверь!!!
                   ((i - 2) >= 0) && ((j + 2) < 8))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
				else if ((size_pole[i - 1][j - 1] == '∞') &&
                         (size_pole[i - 2][j - 2] == ' ') &&
                         //(size_pole[i - 2][j - 2] <= size_pole[0][0]) &&
                        ((i - 2) >= 0) && ((j - 2) >= 0))
				{
					size_pole[i][j] = *ptr_motion;
					eating++;
				}
                else if ((size_pole[i + 1][j + 1] == '∞') &&
                         (size_pole[i + 2][j + 2] == ' ') &&
                         //(size_pole[i + 2][j + 2] <= size_pole[7][7]) &&
                        ((i + 2) < 8) && ((j + 2) < 8))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
                else if ((size_pole[i + 1][j - 1] == '∞') &&
                         (size_pole[i + 2][j - 2] == ' ') &&
                         //(size_pole[i + 2][j - 2] <= size_pole[7][0]) &&
                        ((i + 2) < 8) && ((j - 2) >= 0))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
			}
		}
	}

	if(eating == 0)
	{
        if(number == 1)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (size_pole[i][j] == check)
                    {
                        if (j == 0)
                        {
                            if (size_pole[i - 1][1] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else if (j == 7)
                        {
                            if (size_pole[i - 1][6] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else
                        {
                            if ((size_pole[i - 1][j + 1] == ' ') || (size_pole[i - 1][j - 1] == ' '))
                                size_pole[i][j] = *ptr_motion;
                        }
                    }
                }
            }
        }
        else if (number == 2)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (size_pole[i][j] == check)
                    {
                        if (j == 0)
                        {
                            if (size_pole[i + 1][1] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else if (j == 7)
                        {
                            if (size_pole[i + 1][6] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else
                        {
                            if ((size_pole[i + 1][j + 1] == ' ') || (size_pole[i + 1][j - 1] == ' '))
                                size_pole[i][j] = *ptr_motion;
                        }
                    }
                }
            }
        }
    }
	eating = 0;
}

void black_to_go(char size_pole[][8], char check, int number)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == check || size_pole[i][j] == *ptr_motion)
			{
				if ((size_pole[i + 1][j + 1] == 'Х') &&
                    (size_pole[i + 2][j + 2] == ' ') &&
                    //(size_pole[i + 2][j + 2] <= size_pole[7][7]) &&
                   ((i + 2) < 8) && ((j + 2) < 8))              // код исправил  »–»ЋЋ проверь!!!
				{
					size_pole[i][j] = *ptr_motion;
					eating++;
				}
				else if ((size_pole[i + 1][j - 1] == 'Х') &&
                         (size_pole[i + 2][j - 2] == ' ') &&
                         //(size_pole[i + 2][j - 2] <= size_pole[7][0]) &&
                        ((i + 2) < 8) && ((j - 2) >= 0))
				{
					size_pole[i][j] = *ptr_motion;
					eating++;
				}
                else if ((size_pole[i - 1][j + 1] == 'Х') &&
                         (size_pole[i - 2][j + 2] == ' ') &&
                         //(size_pole[i - 2][j + 2] <= size_pole[0][7]) &&
                        ((i - 2) >= 0) && ((j + 2) < 8))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
                else if ((size_pole[i - 1][j - 1] == 'Х') &&
                         (size_pole[i - 2][j - 2] == ' ') &&
                         //(size_pole[i - 2][j - 2] <= size_pole[0][0]) &&
                        ((i - 2) >= 0) && ((j - 2) >= 0))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
			}
		}
	}

	if (eating == 0)
	{
        if(number == 1)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (size_pole[i][j] == check)
                    {
                        if (j == 0)
                        {
                            if (size_pole[i + 1][1] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else if (j == 7)
                        {
                            if (size_pole[i + 1][6] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else
                        {
                            if ((size_pole[i + 1][j + 1] == ' ') || (size_pole[i + 1][j - 1] == ' '))
                                size_pole[i][j] = *ptr_motion;


                        }
                    }
                }
            }
        }
        else if (number == 2)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (size_pole[i][j] == check)
                    {
                        if (j == 0)
                        {
                            if (size_pole[i - 1][1] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else if (j == 7)
                        {
                            if (size_pole[i - 1][6] == ' ')
                                size_pole[i][j] = *ptr_motion;
                        }
                        else
                        {
                            if ((size_pole[i - 1][j + 1] == ' ') || (size_pole[i - 1][j - 1] == ' '))
                                size_pole[i][j] = *ptr_motion;
                        }
                    }
                }
            }
        }
	}
	eating = 0;
}

void check_to_go(char size_pole[][8], char check, int control)  //переделать передачу переменной дл€ получени€ значени€ number из checkers_position()
{
    //int numbers = &number;
	if (control == 1)
	{
		if (check == 'Х')
		{
			white_to_go(size_pole, check, number);
			print_pole(8, size_pole);
		}

		else if (check == '∞')
		{
			black_to_go(size_pole, check, number);
			print_pole(8, size_pole);
		}
	}
    else if (control == 2)
    {
        if (check == 'Х')
            return_to_go(size_pole, check);
        else if (check == '∞')
            return_to_go(size_pole, check);
    }
}