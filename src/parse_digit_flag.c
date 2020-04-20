#include "../includes/ft_printf.h"

int			ft_findlen(unsigned long long int n, int base)
{
	int 				k;

	k = 1;
	while ((n = n / base))
		k++;
	return (k);
}

char					*ft_new_itoa(t_args *b, long long int n)
{
	char				*str;
	unsigned long long int		k;
	int					len;
	int					i;

	i = 0;
	k = (n < 0) ? -n : n;
	len = (b->prec > ft_findlen(k, 10)) ? b->prec : ft_findlen(k, 10);
	len += (b->space || b->plus || n < 0) ? 1 : 0;
	str = ft_strnew(len);
	str[--len] = (b->prec != 0 || n != 0) ? k % 10 + 48 : '\0';
	while ((k = k / 10))
		str[--len] = (k % 10) + 48;
	while(str[i] && !ft_isdigit(str[i]))
		str[i++] = '0';
	if (n < 0)
		str[0] = '-';
	else if (b->plus && n >= 0)
		str[0] = '+';
	else if (b->space)
		str[0] = ' ';
	return (str);
}

void		parse_digit_flag(t_args *b, long long int a)
{
	char	*num;
	char	*tmp;
	int		len;
	int		i;
	int		k;

	k = 0;
	i = 0;
	num = ft_new_itoa(b, a);
	len = ft_strlen(num);
	if (b->width > len)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, (b->zero && b->prec == -1) ? '0' : ' ', b->width);
		if (b->minus)
			ft_memcpy(tmp, num, len);
		else
		{
			i = b->width - len;
			k = 0;
			while (tmp[i])
			{
				tmp[i] = num[k];
				i++;
				k++;
			}
			if (b->zero && b->prec == -1 && !ft_isdigit(num[0]))
			{
				tmp[0] = num[0];
				tmp[b->width - len] = '0';
			}
		}
	}
	else
		tmp = ft_strdup(num);
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
	free(tmp);
	free(num);
}

void	number_flags(va_list argptr, t_args *b)
{
	long long int a;
	if (b->ll)
		a = va_arg(argptr, long long int);
	else if (b->l)
		a = va_arg(argptr, long int);
	else if (b->h)
		a = (short)va_arg(argptr, int);
	else if (b->hh)
		a = (char)va_arg(argptr, int);
	else
		a = va_arg(argptr, int);
	parse_digit_flag(b, a);
}
