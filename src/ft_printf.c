#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void		clear_struct(t_args *b)
{
	b->type = NULL;
	b->zero_x = 0;
	b->zero = 0;
	b->minus = 0;
	b->plus = 0;
	b->prec = 0;
	b->width = 0;
	b->space = 0;
	b->hh = 0;
	b->h = 0;
	b->ll = 0;
	b->l = 0;
	b->l_cap = 0;
}

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

void		parse_arg(va_list argptr, t_args *b, char *str)
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

void	precision_search(t_args *b, char *str)
{
	b->i++;
	while(str[b->i] && ft_isdigit(str[b->i]))
	{
		b->prec *= 10;
		b->prec += str[b->i++] -'0';
	}

}

void	width_search(t_args *b, char *str)
{
	while (str[b->i] && ft_isdigit(str[b->i]))
	{
		b->width *= 10;
		b->width += str[b->i++] - '0';
	}
}

void	sign_search(t_args *b, char *str)
{
	int i;

	i = b->i;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0' ||
		str[i] == '#' || str[i] = ' ')
	{
		if (str[i] == '+')
			b->plus = 1;
		if (str[i] == '-')
			b->minus = 1;
		if (str[i] == '#')
			b->zero_x = 1;
		if (str[i] == ' ')
			b->space = 1;
		if (str[i] == '0')
			b->zero = 1;
		i++;
	}
	b->i = i;
}

void	find_flag(va_list argptr, t_args *b, char *str)
{
	sign_search(b, str);
	width_search(b, str);
	if (str[b->i] == '.')
		precision_search(b, str);
	flag_search(argptr, b, str);
}

void	main_loop(va_list argptr, t_args *b, char *str)
{
	int		start;
	int		end;

	while (str[b->i])
    {
        while (str[b->i] != '%' && str[b->i] != '\0')
        {
            ft_putchar(str[b->i]);
            b->i++;
            start++;
        }
        end = start;
        if (str[b->i] == '%')
        {
        	find_flag(argptr, b, str);
        	clear_struct(b);
        }
	}
}

int     ft_printf(const char *format, ...)
{
    char    *str;
    va_list argptr;
	t_args	*b;

	b = (t_args *)malloc(sizeof(t_args));
	clear_struct(b);
	b->i = 0;
	b->start = 0;
    va_start(argptr, format);
    str = (char *)format;
    main_loop(argptr, b, str);
	va_end(argptr);
	free(b);
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
