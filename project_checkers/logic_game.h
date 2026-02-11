#pragma once
#include "checkers_white.h"
#include "checkers_black.h"
#include "pole_checkers.h"

void print_pole(int size, char size_pole[][8]);

//char white_check = '•';
//char black_check = '°';
char motion = '¯';
int eating{ 0 };

void return_to_go(char size_pole[][8], char check)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == motion)
			{
				size_pole[i][j] = check;
			}
		}
	}
}

void white_to_go(char size_pole[][8], char check)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == check)
			{
                if ((size_pole[i - 1][j + 1] == '°') &&
                    (size_pole[i - 2][j + 2] == ' ') &&
                    ((j + 2) < 8) && ((i - 2) >= 0)) // êîä èñïðàâèë ÊÈÐÈËË ïðîâåðü!!!
                {
                    size_pole[i][j] = motion;
                    eating++;
                }
				else if ((size_pole[i - 1][j - 1] == '°') &&
                         (size_pole[i - 2][j - 2] == ' ') &&
                           ((j - 2) >= 0) && ((i - 2) >= 0))
				{
					size_pole[i][j] = motion;
					eating++;
				}
			}
		}
	}

	if(eating == 0)
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
							size_pole[i][j] = motion;
					}
					else if (j == 7)
					{
						if (size_pole[i - 1][6] == ' ')
							size_pole[i][j] = motion;
					}
					else
					{
						if ((size_pole[i - 1][j + 1] == ' ') || (size_pole[i - 1][j - 1] == ' ') )
							size_pole[i][j] = motion;
					}
				}
			}
		}
	}
	eating = 0;
}

void black_to_go(char size_pole[][8], char check)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == check)
			{
				if ((size_pole[i + 1][j + 1] == '•') && (size_pole[i + 2][j + 2] == ' ') && ((j + 2) < 9) && (i + 2) <= 7)// êîä èñïðàâèë ÊÈÐÈËË ïðîâåðü!!!
				{
					size_pole[i][j] = motion;
					eating++;
				}
				else if ((size_pole[i + 1][j - 1] == '•') && (size_pole[i + 2][j - 2] == ' ') && ((j - 2) >= 0) && (i + 2) <= 7)
				{
					size_pole[i][j] = motion;
					eating++;
				}
			}
		}
	}

	if (eating == 0)
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
							size_pole[i][j] = motion;
					}
					else if (j == 7)
					{
						if (size_pole[i + 1][6] == ' ')
							size_pole[i][j] = motion;
					}
					else
					{
						if ((size_pole[i + 1][j + 1] == ' ') || (size_pole[i + 1][j - 1] == ' '))
							size_pole[i][j] = motion;


					}
				}
			}
		}
	}
	eating = 0;
}



void check_to_go(char size_pole[][8], char check, int control)
{
	if (control == 1)
	{
		if (check == '•')
		{
			white_to_go(size_pole, check);
			print_pole(8, size_pole);
		}

		else if (check == '°')
		{
			black_to_go(size_pole, check);
			print_pole(8, size_pole);
		}
	}
	if (check == '•')
		return_to_go(size_pole, check);
	else if (check == '°')
		return_to_go(size_pole, check);
}