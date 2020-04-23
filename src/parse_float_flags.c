#include "../includes/ft_printf.h"

long double 		round_up(t_args *b, long double n)
{
	int 		mult;
	int			pow;
	long double start;

	start = n;
	pow = b->prec;
	mult = 10;
	if (pow == 0)
		return (n - (int)n > 0.5) ? n + 1 :  n;
	while (--pow)
		mult *= 10;
	n = ((double)((int)(n * mult)) / mult);
	n = start > n + 5.0 / ( 10 * mult) ? n + 1.0 / mult : n;
	return (n);
}

char					*ft_float_itoa(t_args *b, long double n, int prec)
{
	long double		num;
	long long		full;
	char			*tmp;
	char			*str;
	int				len;

	len = b->prec + ft_findlen((int)(n < 0) ? -n : n, 10) + 1 + (n < 0);
	str = ft_strnew(len);
	num = round_up(b, (n < 0) ? -n : n);
	tmp = ft_itoa((unsigned long long)num);
	ft_strcpy(str, tmp);
	free(tmp);
	num -= (unsigned long long)num;
	if (prec > 0)
		str[ft_strlen(str)] = '.';
	while (prec > 0 && prec--)
	{
		if (prec <= 15)
			num += 0.000000000000001;
		num *= 10;
		full = (unsigned long long)num;
		num -= full;
		str[ft_findlen((int)(n < 0) ? -n : n, 10) + (b->prec - prec)] = full + 48;
	}
	return (str);
}

void		float_padding(t_args *b, char *tmp, char *num, int len)
{
	int		i;
	int		k;


	i = b->width - len;
	k = 0;
	while (tmp[i])
	{
		tmp[i] = num[k];
		i++;
		k++;
	}
	if (b->zero && !ft_isdigit(num[0]))
	{
		tmp[0] = num[0];
		tmp[b->width - len] = '0';
	}
}

void		parse_float_flag(t_args *b, long double a)
{
	char	*num;
	char	*tmp;
	int		len;

	if (a == INFINITY)
	{
		add_to_buffer(b, "inf", 0, ft_strlen("inf"));
		return ;
	}
	num = ft_float_itoa(b, a, b->prec);
	len = ft_strlen(num);
	if (b->width > len)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, (b->zero) ? '0' : ' ', b->width);
		if (b->minus)
			ft_memcpy(tmp, num, len);
		else
			float_padding(b, tmp, num, len);
	}
	else
		tmp = ft_strdup(num);
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
	free(tmp);
	free(num);
}

void	float_flags(va_list argptr, t_args *b)
{
	long double a;

	if (b->prec < 0)
		b->prec = 6;
	if (b->l_cap || b->l)
	{
		a = va_arg(argptr, long double);
		printf("%Lf\n", a);
	}
	else
	{
		a = va_arg(argptr, double);
		printf("%Lf\n", a);
	}
	parse_float_flag(b, a);
}
