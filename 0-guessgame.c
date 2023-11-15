#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
* main - Generates an array of random numbers between 1 and 9,
* accepts user input, and compares the user input
* and the system-generated numbers
*
* Return: Always returns 0 on success.
*/
int main(void)
{
	int i, guess1, guess2, guess3, guess[3], code[3], _true;
	int chance = 0;

	srand(time(0));
	for (i = 0; i < 3; i++)
		code[i] = (rand() % 9) + 1;
	printf("Welcome to **LOTTOVILE$$**\n");
	while (chance < 3)
	{
		printf("GUESS-LUCKYCODE(Hint:0 to 9)\n");
		scanf("%d %d %d", &guess1, &guess2, &guess3);
		guess[0] = guess1;
		guess[1] = guess2;
		guess[2] = guess3;
		_true = 1;

		for (i = 0; i < 3; i++)
		{
			if (guess[i] != code[i])
			{
				_true = 0;
				break;
			}
		}
		if (_true)
		{
			printf("YOU WIN!\n");
			break;
		}
		else
		{
			chance++;
			printf("%d tries left\n", 3 - chance);
		}
	}
	if (chance == 3)
	{
		printf("LUCKYCODE %d-%d-%d.You lost...!!!\n", code[0], code[1], code[2]);
	}
	return (0);
}

