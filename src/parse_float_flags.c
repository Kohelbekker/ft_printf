#include "../includes/ft_printf.h"

long long						find_multiplier(t_args *b)
{
	long long multip;
	int	i;

	i = 1;
	multip = 10;
	while (i < b->prec)
	{
		multip *= 10;
		i++;
	}
	return (multip);
}

char					*ft_float_itoa(t_args *b, long double number)
{
	long double			num;
	int					negative;
	long long			whole;

	num = (number < 0) ? -number : number;
	negative = (number < 0) ? -1 : 1;
	whole = (unsigned long long)num;
	if (num - whole >= 0.5 && b->prec == 0)
		whole += 1;
	num -= whole;
	printf("whole = ");
	printf("%lld\n", whole);
	printf("\n");
	if (b->prec <= 15)
		num += 0.0000000000000001;
	if (b->prec > 0)
		printf(".");
	if (b->prec != 0)
		while (b->prec)
		{
			num *= 10;
			whole = (unsigned long long)num;
			num -= whole;
			whole %= 10;
			printf("%c", whole + '0');
			b->prec--;
		}
		printf("\n");
	return ("kek");
	// char				*str;
	// double	k;
	// int					len;
	// int					i;
	// double	frac;
	// long long		part;
	// long long		multip;

	// k = (n < 0) ? -n : n;
	// len = b->prec + ft_findlen((int)k, 10) + 1 + (n < 0);
	// frac = k - (long long)k;
	// frac = (b->prec < 16) ? frac + 0.0000000000000001 : frac;
	// multip = find_multiplier(b);
	// part = frac * multip;
	// str = ft_strnew(len);
	// printf("len = %d, multip = %d, frac = %f, part = %d\n", len, multip, frac, part);
	// if (b->prec != 0)
	// 	str[--len] = part % 10 + 48;
	// while (len > ft_findlen((int)n, 10) + 1)
	// {
	// 	part /= 10;
	// 	str[--len] = (part % 10) + 48;
	// }
	// printf("str = %s\n", str);
	// if (b->prec != 0)
	// 	str[--len] = '.';
	// part = b->prec == 0 && k - (long long)k >= 0.5 ? (int)k + 1 : (int)k;
	// printf("part2 = %d\n", part);
	// str[--len] = part % 10 + 48;
	// while ((part = part / 10))
	// 	str[--len] = (part % 10) + 48;
	// // while(str[i] && !ft_isdigit(str[i]))
	// // 	str[i++] = '0';
	// if (n < 0)
	// 	str[0] = '-';
	// else if (b->plus && n > 0)
	// 	str[0] = '+';
	// else if (b->space)
	// 	str[0] = ' ';
	// return (str);
}

void		parse_float_flag(t_args *b, long double a)
{
	char	*num;
	char	*tmp;
	int		len;
	int		i;
	int		k;

	k = 0;
	i = 0;

	if (a == INFINITY)
	{
		add_to_buffer(b, "inf", 0, ft_strlen("inf"));
		return ;
	}
	num = ft_float_itoa(b, a);
	len = ft_strlen(num);
	// printf("num = %s\n", num);
	// if (b->width > len)
	// {
	// 	tmp = (char *)malloc(b->width + 1);
	// 	tmp[b->width] = '\0';
	// 	ft_memset(tmp, (b->zero && b->prec == -1) ? '0' : ' ', b->width);
	// 	if (b->minus)
	// 		ft_memcpy(tmp, num, len);
	// 	else
	// 	{
	// 		i = b->width - len;
	// 		k = 0;
	// 		while (tmp[i])
	// 		{
	// 			tmp[i] = num[k];
	// 			i++;
	// 			k++;
	// 		}
	// 		if (b->zero && b->prec == -1 && !ft_isdigit(num[0]))
	// 		{
	// 			tmp[0] = num[0];
	// 			tmp[b->width - len] = '0';
	// 		}
	// 	}
	// }
	// else
	// 	tmp = ft_strdup(num);
	// add_to_buffer(b, tmp, 0, ft_strlen(tmp));
	// free(tmp);
	//free(num);
}

void	float_flags(va_list argptr, t_args *b)
{
	long double a;

	if (b->prec < 0)
		b->prec = 6;
	if (b->l_cap)
		a = va_arg(argptr, long double);
	else
		a = va_arg(argptr, double);
	parse_float_flag(b, a);
}
