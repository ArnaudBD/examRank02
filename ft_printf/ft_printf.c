#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int prints(char * s)
{
	int i;
	if(!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int printx(int nu, int base)
{
	char *b = "0123456789abcdef";
	int n;
	int count;
	unsigned int num;

	count = 0;
	count = 0;
	if (base == 10)
	{
		if (nu < 0)
		{
			num = -nu;
			write(1, "-", 1);
			count++;
		}
		else
			num = nu;
	}
	else
	{
		num = (unsigned int)nu;
	}
	if (num / base)
		count += printx(num/base, base);
	n = num % base;
	write(1, &b[n], 1);
	count++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int count;
	va_list	ap;
	va_start(ap, str);

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != 0 && str[i] != '%')
			{
				if (str[i] == 's')
					count += prints(va_arg(ap, char *));
				if (str[i] == 'd')
					count += printx(va_arg(ap ,int), 10);
				if (str[i] == 'x')
					count += printx(va_arg(ap,int), 16);
				i++;
			}
		}
		else
		{
			write(1, &str[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}

