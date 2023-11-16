#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
* main - generates an array of random numbers between 1 and 10,
* accepts user input and compares it with the system-generated numbers.
*
* Return: always returns 0 on success.
*/
int main(void)
{
int i, guess1, guess2, guess3, isCorrect;
int chance = 0;
int guess[3], code[3];

srand(time(0));
for (i = 0; i < 3; i++)
{
code[i] = (rand() % 10) + 1;
}
printf("Welcome to **LOTTOVILE$$**\n");
while (chance < 3)
{
printf("GUESS-LUCKYCODE (Hint: 0 to 9)\n");
scanf("%d %d %d", &guess1, &guess2, &guess3);
guess[0] = guess1;
guess[1] = guess2;
guess[2] = guess3;
isCorrect = 1;
for (i = 0; i < 3; i++)
{
if (guess[i] != code[i])
{
isCorrect = 0;
break;
}
}
if (isCorrect)
{
printf("YOU WIN!\n");
break;
}
else
{
chance++;
printf("YOU LOST, %d tries left\n", 3 - chance);
}
}
if (chance == 3)
printf("LUCKYCODE is %d-%d-%d. You lost...!\n", code[0], code[1], code[2]);
return (0);
}

