#include "../includes/ft_printf.h"

char		*base_itoa(t_args *b, unsigned long long int a, int base)
{
	char					*res;
	int						len;
	int						shift;
	int						pref;
	int						i;
	int						prec;

	prec = b->prec > 0 ? b->prec : 0;
	//i = (b->width - prec > 0) ? b->width - prec : 0;
	i = do we have zero_x flag ? 2 : 0;
	shift = (b->flag == 'X') ? 7 : 39;
	pref = (b->flag == 'o') ? 1 : 2;
	len = (b->prec > ft_findlen(a, base)) ? b->prec : ft_findlen(a, base);
	len += (b->zero_x && b->prec > ft_findlen(a, base) && prec < ft_findlen(a, base) + pref) ? ft_findlen(a, base) + pref - prec : 0;
	res = ft_strnew(len);
	res[len] = '\0';
	res[--len] = a % base + 48;
	res[len] += (res[len] > '9') ? shift : 0;
	while ((a = a / base))
	{
		res[--len] = (a % base) + 48;
		if ((a % base) + 48 > '9')
			res[len] += shift;
	}
	if ((b->flag != 'u') && b->zero_x)
	{
		res[0] = '0';
		if (b->flag != 'o')
			res[1] = (b->flag == 'X') ? 'X' : 'x';
	}
	while(res[i] != '\0' && res[i] == ' ')
		res[i++] = '0';
	printf("res2 = '%s'\n", res);
	return(res);
}

void		parse_base_flag(t_args *b, unsigned long long int a, int base)
{
	char	*num;
	char	*tmp;
	int		len;
	int		i;
	int		k;

	k = 0;
	i = 0;
	num = base_itoa(b, a, base);
	len = ft_strlen(num);
	if (b->width > len)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, (b->zero) ? '0' : ' ', b->width);
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
			if (b->zero && b->zero_x)
			{
				tmp[0] = num[0];
				tmp[b->width - len] = '0';
				if (b->flag == 'X' || b->flag == 'x')
				{
					tmp[1] = num[1];
					tmp[b->width - len + 1] = '0';
				}
			}
		}
	}
	else
		tmp = ft_strdup(num);
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
	free(tmp);
}

void	base_flags(va_list argptr, t_args *b)
{
	unsigned long long int	a;
	void					*tmp;
	int						base;

	if (b->flag == 'x' || b->flag == 'X' || b->flag == 'o' || b->flag == 'p')
		base = (b->flag == 'o')  ? 8 : 16;
	else
		base = 10;
	if (b->flag == 'p')
	{
		b->zero_x = 1;
		tmp = va_arg(argptr, void*);
		a = (unsigned long long int)tmp;
	}
	else if (b->h)
		a = (unsigned short)va_arg(argptr, unsigned int);
	else if (b->hh)
		a = (unsigned char)va_arg(argptr, unsigned int);
	else if (b->l)
		a = va_arg(argptr, unsigned long int);
	else if (b->ll)
		a = va_arg(argptr, unsigned long long int);
	else
		a = va_arg(argptr, unsigned int);
	parse_base_flag(b, a, base);
}