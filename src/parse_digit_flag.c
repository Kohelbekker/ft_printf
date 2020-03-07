#include "../includes/ft_printf.h"

static int			ft_intlen(long long int n)
{
	int 				k;

	k = 1;
	while ((n = n / 10))
		k++;
	return (k);
}

char					*ft_new_itoa(t_args *b, long long int n)
{
	char				*str;
	long long int		k;
	size_t				len;
	int					i;

	i = 0;
	k = n;
	len ==ft_intlen(n);
	len += (b->prec > ft_intlen(n)) ? b->prec - ft_intlen(n) : 0;
	if (n < 0)
		k = -1 * n;
	str = ft_strnew(len);
	str[--len] = k % 10 + 48;
	while ((k = k / 10))
		str[--len] = (k % 10) + 48;
	if (n < 0)
		str[i++] = '-';
	else if (b->plus && n > 0)
		str[i++] = '+';
	else if (b->space)
		str[i++] = ' ';
	while(str[i] && !ft_isdigit(str[i]))
		str[i++] = '0';
	return (str);
}

	if (n < 0)
		str[i++] = '-';
	else if (b->plus && n > 0)
		str[i++] = '+';
	else if (b->space)
		str[i++] = ' ';

void		parse_digit_flag(t_args *b, long long int a)
{
	char	*num;
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	num = ft_new_itoa(b, a);
	len = ft_strlen(num);
	if (b->width > len)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, (b->zero) ? '0' : ' ', b->width);
		if (b->zero || b->minus)
		{

		}
		if (b->minus)
			ft_memcpy(tmp, num, len);
		else
			tmp = write_after_padding(b, 0, num, tmp);
	}
	else
	{
		tmp = ft_strdup(num);
	}
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
	free(tmp);
	free(num);
}

void	number_flags(va_list argptr, t_args *b)
{
	long long int a;
	if (b->h)
		a = (short)va_arg(argptr, int);
	else if (b->hh)
		a = (char)va_arg(argptr, int);
	else if (b->l)
		a = va_arg(argptr, long int);
	else if (b->ll)
		a = va_arg(argptr, long long int);
	else
		a = va_arg(argptr, int);
	parse_digit_flag(b, a);
}
