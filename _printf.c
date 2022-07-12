#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int amg = 0;
	va_list pa;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(pa, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, pa);
		if (*p != '%')
		{
			amg += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, pa);
		p = get_precision(p, &params, pa);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			amg += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			amg += get_print_func(p, pa, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(pa);
	return (amg);
}
