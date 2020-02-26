#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int     check_length(int i)
{
    int length;

    length = 0;
    while (i > 9)
    {
        i /= 10;
        length++;
    }
    length++;
    return (length);
}

int     do_padding(char *str, int pad, int zero_flag)
{
    if ( pad != 0)
    {
        pad -= ft_strlen(str);
		while (pad != 0)
        {
            if (zero_flag == 0)
                ft_putchar(' ');
            else
                ft_putchar('0');
            pad--;
        }
    }
    return (0);
}

void		flag_selector(char **tmp, va_list argptr)
{		
    int     zero_flag;
    int     pad;
    int     d;
	char    *str;
	
	d = 0;
	pad = 0;	
    zero_flag = 0;
	if (**tmp >= '0' && **tmp <= '9')
	{
		if (**tmp == '0')
			zero_flag = 1;
		while (**tmp >= '0' && **tmp <= '9')
		{   
			pad *= 10;
			pad += **tmp - '0';
			(*tmp)++;
		}
		if (**tmp != 'd' && **tmp != 's') 
		{
			ft_putstr(ft_itoa(pad));
			zero_flag = 0;
		}
	}
	if (**tmp == 's')
	{ 
		str = va_arg(argptr, char *);
		pad = do_padding(str, pad, zero_flag);
		ft_putstr(str);
		(*tmp)++;
	}
	else if (**tmp == 'd')
	{
		d = va_arg(argptr, int);
		str = ft_itoa(d);
		pad = do_padding(str, pad, zero_flag);
		ft_putstr(str);
		(*tmp)++;
	}
	else if (**tmp == '%')
		ft_putchar('%');
}

int     ft_printf(const char *format, ...)
{
    char    *tmp;
    va_list argptr;

    va_start(argptr, format);
    tmp = (char *)format;
    while (*tmp)
    {
        while (*tmp != '%' && *tmp != '\0')
        {
            ft_putchar(*tmp);
            tmp++;
        }
        if (*tmp == '\0')
            return (0);
        tmp++;
    	flag_selector(&tmp, argptr);
	}
	va_end(argptr);
	return (0);
}
/*
int	main () {
	char *str;

	str = "lol\nkek\nwow, number: %d\n%sofix\n";
	ft_printf(str, 12345, "yo-hoh-oh");
	return (0);
}
*/
