#pragma once
#include "main_menu.h"
#include "checkers_white.h"
#include "checkers_black.h"
#include "pole_checkers.h"

void checkers_pole();
void print_pole(int size, char size_pole[][8]);
int checkers_position(int size, char size_pole[][8], char* white_checkers, char* black_checkers);
int check_selection(int* ptr_check_number);

char motion = 'ѓ';
char *ptr_motion = &motion;
int eating{ 0 };

void check_to_damka(char *size_pole, int check, char design_check )
{

     for (int i = 0; i < 8 , design_check == 'Х', check == 1; i++)
     {
         if (*(size_pole + i) == design_check)
             *(size_pole + i) = '*';
     }
     /*for (int i = 0; i < 8, design_check == 'Х', check == 2 ; i++)
     {
         if (size_pole[7][i] == design_check)
             size_pole[7][i] = '*';
     }
     for (int i = 0; i < 8, design_check == '∞', check == 1; i++)
     {
         if (size_pole[7][i] == design_check)
             size_pole[7][i] = '§';
     }
     for (int i = 0; i < 8, design_check == '∞', check == 2; i++)
     {
         if (size_pole[0][i] == design_check)
             size_pole[0][i] = '§';
     }*/
   

}

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

void white_to_go(char size_pole[][8], char check, int control, int *ptr_check_number)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == check || size_pole[i][j] == *ptr_motion)
			{
                if ((size_pole[i - 1][j + 1] == '∞') &&
                    (size_pole[i - 2][j + 2] == ' ') &&         // код исправил  »–»ЋЋ проверь!!!      
                   ((i - 2) >= 0) && ((j + 2) < 8))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
				else if ((size_pole[i - 1][j - 1] == '∞') &&
                         (size_pole[i - 2][j - 2] == ' ') &&
                        ((i - 2) >= 0) && ((j - 2) >= 0))
				{
					size_pole[i][j] = *ptr_motion;
					eating++;
				}
                else if ((size_pole[i + 1][j + 1] == '∞') &&
                         (size_pole[i + 2][j + 2] == ' ') &&
                        ((i + 2) < 8) && ((j + 2) < 8))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
                else if ((size_pole[i + 1][j - 1] == '∞') &&
                         (size_pole[i + 2][j - 2] == ' ') &&
                        ((i + 2) < 8) && ((j - 2) >= 0))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
			}
		}
	}
    int number = check_selection(ptr_check_number);

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

void black_to_go(char size_pole[][8], char check, int control, int *ptr_check_number)//, int number
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (size_pole[i][j] == check || size_pole[i][j] == *ptr_motion)
			{
				if ((size_pole[i + 1][j + 1] == 'Х') &&
                    (size_pole[i + 2][j + 2] == ' ') &&
                   ((i + 2) < 8) && ((j + 2) < 8))              // код исправил  »–»ЋЋ проверь!!!
				{
					size_pole[i][j] = *ptr_motion;
					eating++;
				}
				else if ((size_pole[i + 1][j - 1] == 'Х') &&
                         (size_pole[i + 2][j - 2] == ' ') &&
                        ((i + 2) < 8) && ((j - 2) >= 0))
				{
					size_pole[i][j] = *ptr_motion;
					eating++;
				}
                else if ((size_pole[i - 1][j + 1] == 'Х') &&
                         (size_pole[i - 2][j + 2] == ' ') &&
                        ((i - 2) >= 0) && ((j + 2) < 8))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
                else if ((size_pole[i - 1][j - 1] == 'Х') &&
                         (size_pole[i - 2][j - 2] == ' ') &&
                        ((i - 2) >= 0) && ((j - 2) >= 0))
                {
                    size_pole[i][j] = *ptr_motion;
                    eating++;
                }
			}
		}
	}
    int number = check_selection(ptr_check_number);

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

int check_selection(int *ptr_check_number)
{
    int number = *ptr_check_number;
    if (number == 1)
        return number;
    else if (number == 2)
        return number;
}

void check_to_go(char size_pole[][8], char check, int control, int* ptr_check_number)  //переделать передачу переменной дл€ получени€ значени€ number из checkers_position()
{
    int numbers = *ptr_check_number;
	if (control == 1)
	{
		if (check == 'Х')
		{
			white_to_go(size_pole, check, control, ptr_check_number);//, number
			print_pole(8, size_pole);
		}

		else if (check == '∞')
		{
			black_to_go(size_pole, check, control, ptr_check_number);//, number
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

void check_will_go(int* x_OU, int* y_OU, char size_pole[][8])
{
    bool xy_test{ true };
    int y_test, x_test;
    while (xy_test)
    {
        cout << '\n' << "\t\t\t\t\t ¬ыберете куда сходить: ";
        cin >> y_test;
        cin >> x_test;
        *x_OU = 0;
        *y_OU = 0;

        for (int i = 1; *x_OU <= 8; i++)
        {
            if (x_test == (i + 48))
            {
                *x_OU = i;
                *x_OU -= 1;
                //cout << x_OU << endl;
                break;
            }
        }
        for (int i = 1; *y_OU <= 8; i++)
        {
            if (y_test == (i + 96))
            {
                *y_OU = i;
                *y_OU -= 1;
                //cout << y_OU << endl;
                break;
            }
        }
        if (((*x_OU >= 0) && (*x_OU <= 7)) && ((*y_OU >= 0) && (*y_OU <= 7)))
        {
            if (size_pole[*x_OU][*y_OU] == ' ')
                xy_test = false;
            else
                xy_test = true;
        }
        else
            xy_test = true;
    }
}