#include "../includes/ft_printf.h"

void	notype_signs(t_args *b, char *str, int i)
{
	if (b->space)
	{
		str[i] = ' ';
		b->space = 0;
	}
	else if (b->zero)
	{
		str[i] = '0';
		b->zero = 0;
	}
	else if (b->plus)
	{
		str[i] = '+';
		b->plus = 0;
	}
	else if (b->minus)
	{
		str[i] = '-';
		b->minus = 0;
	}
}

void	no_type(t_args *b)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 1;
	len += (b->space + b->minus + b->zero + b->plus);
	str = ft_strnew(len + 1);
	str[len] = '\0';
	str[0] = '%';
	while(++i < len)
		notype_signs(b, str, i);
	add_to_buffer(b, str, 0, ft_strlen(str));
	if (b->width > 0)
		add_to_buffer(b, ft_itoa(b->width), 0, ft_strlen(ft_itoa(b->width)));
	if (b->prec != -1)
	{
		add_to_buffer(b, ".", 0, 1);
		add_to_buffer(b, ft_itoa(b->prec), 0, ft_strlen(ft_itoa(b->prec)));
	}
}