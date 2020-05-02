#include "../includes/ft_printf.h"

int		check_length(int i)
{
	int	length;

	length = 0;
	while (i > 9)
	{
		i /= 10;
		length++;
	}
	length++;
	return (length);
}

void	width_search(t_args *b, va_list argptr, char *str)
{
	if (str[b->i] == '*')
	{
		b->width = va_arg(argptr, int);
		b->i++;
		return ;
	}
	while (str[b->i] && ft_isdigit(str[b->i]))
	{
		b->width *= 10;
		b->width += str[b->i++] - '0';
	}
}

long long						find_multiplier(t_args *b)
{
	long long 	multip;
	int			i;

	i = 1;
	multip = 10;
	while (i < b->prec)
	{
		multip *= 10;
		i++;
	}
	return (multip);
}