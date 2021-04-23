#include "shell.h"

/**
 * _nbrLen - length of a number
 * @prmNumber: number
 * Return: length of the number
 */

int _nbrLen(int prmNumber)
{
	int cLoop = 0, number;

	if (prmNumber == 0)
		return (1);

	number = prmNumber;

	if (number < 0)
	{
		number *= -1;
		cLoop++;	/* for the sign char */
	}

	while (number)
	{
		number /= 10;
		cLoop++;
	}

	return (cLoop);
}
