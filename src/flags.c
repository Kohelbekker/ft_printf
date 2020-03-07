#include "../includes/ft_printf.h"

void	precision_search(t_args *b, char *str)
{
	b->i++;
	while(str[b->i] && ft_isdigit(str[b->i]))
	{
		b->prec *= 10;
		b->prec += str[b->i++] - '0';
	}
}

void	size_search(t_args *b, char *str)
{
	if (str[b->i] == 'l' && str[b->i + 1] != 'l')
		b->l = 1;
	else if (str[b->i] == 'l' && str[b->i + 1] == 'l')
		b->ll = 1;
	else if (str[b->i] == 'h' && str[b->i + 1] != 'h')
		b->h = 1;
	else if (str[b->i] == 'h' && str[b->i + 1] == 'h')
		b->hh = 1;
	else if (str[b->i] == 'L')
		b->l_cap = 1;
}

void	sign_search(t_args *b, char *str)
{
	int i;

	i = b->i;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0' ||
		str[i] == '#' || str[i] == ' ')
	{
		if (str[i] == '+')
		{
			b->space = 0;
			b->plus = 1;
		}
		if (str[i] == '-')
		{
			b->zero = 0;
			b->minus = 1;
		}
		if (str[i] == '#')
			b->zero_x = 1;
		if (str[i] == ' ' && b->plus == 0)
			b->space = 1;
		if (str[i] == '0' && b->minus == 0)
			b->zero = 1;
		i++;
	}
	b->i = i;
}

void	flag_search(va_list p, t_args *b, char *str)
{
	b->flag = str[b->i];

	if (b->flag == 'c' || b->flag == 's')
		b->flag == 'c' ? parse_char_flag(b, va_arg(p, int), NULL) : parse_char_flag(b, 0, va_arg(p, char*));
	else if (b->flag == 'f')
		float_flags(p, b);
	else if (b->flag == 'u' || b->flag == 'o' || b->flag == 'x' ||
		b->flag == 'X' || b->flag == 'p')
		base_flags(p, b);
	else if (b->flag == 'd' || b->flag == 'i')
		number_flags(p, b);
	else if (b->flag == '%')
		flag_sign(b);
	else
		add_to_buffer(b,  str, b->start, b->i);
	b->i++;
}

void	find_flag(va_list argptr, t_args *b, char *str)
{
	sign_search(b, str);
	width_search(b, str);
	if (str[b->i] == '.')
	{
		b->prec = 0;
		precision_search(b, str);
	}
	size_search(b, str);
	flag_search(argptr, b, str);
}