#include "main.h"

/**
  * _putchar - function put character to the output
  * @c: the character to print in standard output
  *
  * Return: 0
  */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

