#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int count;
	count= 0;

	while (specifiers[count].specifier)
	{
		if (*s == specifiers[count].specifier[0])
		{
			return (specifiers[count].f);
		}
		count++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int v = 0;

	switch (*s)
	{
		case '+':
			v = params->plus_flag = 1;
			break;
		case ' ':
			v = params->space_flag = 1;
			break;
		case '#':
			v = params->hashtag_flag = 1;
			break;
		case '-':
			v = params->minus_flag = 1;
			break;
		case '0':
			v = params->zero_flag = 1;
			break;
	}
	return (v);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int d = 0;

	switch (*s)
	{
	case 'h':
		d = params->h_modifier = 1;
		break;
	case 'l':
		d = params->l_modifier = 1;
		break;
	}
	return (d);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
/* should this function use char **s and modify the pointer? */
{
	int gg = 0;

	if (*s == '*')
	{
		gg = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			gg = gg * 10 + (*s++ - '0');
	}
	params->width = gg;
	return (s);
}
