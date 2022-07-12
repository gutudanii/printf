#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters str1uct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long lo;
	int z = 0;
	char *str1;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);

	str1 = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && lo)
	{
		*--str1 = 'x';
		*--str1 = '0';
	}
	params->unsign = 1;
	return (z += print_number(str1, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters str1uct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long dl;
	int b = 0;
	char *str11;

	if (params->l_modifier)
		dl = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		dl = (unsigned short int)va_arg(ap, unsigned int);
	else
		dl = (unsigned int)va_arg(ap, unsigned int);

	str11 = convert(dl, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && dl)
	{
		*--str11 = 'X';
		*--str11 = '0';
	}
	params->unsign = 1;
	return (b += print_number(str11, params));
}
/**
 * print_binary - prints number
 * @ap: the argument pointer
 * @params: the parameters str1uct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str1 = convert(n, 2, CONVERT_UNSIGNED, params);
	int b = 0;

	if (params->hashtag_flag && n)
		*--str1 = '0';
	params->unsign = 1;
	return (b += print_number(str1, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters str1uct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str1;
	int b = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str1 = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str1 = '0';
	params->unsign = 1;
	return (b += print_number(str1, params));
}
