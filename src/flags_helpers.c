#include "../includes/ft_printf.h"

int		check_length(int i)
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

void	width_search(t_args *b, char *str)
{
	while (str[b->i] && ft_isdigit(str[b->i]))
	{
		b->width *= 10;
		b->width += str[b->i++] - '0';
	}
}
