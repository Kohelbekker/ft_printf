#include "ft_printf.h"

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