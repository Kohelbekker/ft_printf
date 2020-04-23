#include "../includes/ft_printf.h"

char		*base_itoa(t_args *b, unsigned long long int a, int base, int i)
{
	char					*res;
	int						len;

	if (b->prec == 0 && a == 0)
		return (b->flag != 'o' || !b->zero_x) ? "" : "0";
	len = (b->prec > ft_findlen(a, base)) ? b->prec : ft_findlen(a, base);
	len += (b->zero_x && !(b->flag == 'o' && b->prec > ft_findlen(a, base))) ?
	((b->flag == 'o') ? 1 : 2) : 0;
	res = ft_strnew(len);
	res[--len] = a % base + 48;
	res[len] += (res[len] > '9') ? ((b->flag == 'X') ? 7 : 39) : 0;
	while ((a = a / base))
	{
		res[--len] = (a % base) + 48;
		if ((a % base) + 48 > '9')
			res[len] += (b->flag == 'X') ? 7 : 39;
	}
	while(res[i] != '\0' && res[i] == ' ')
		res[i++] = '0';
	if ((b->flag != 'u') && b->zero_x)
	{
		res[0] = '0';
		if (b->flag != 'o')
			res[1] = (b->flag == 'X') ? 'X' : 'x';
	}
	return(res);
}

void		parse_base_flag(t_args *b, unsigned long long int a, int base, int i)
{
	char	*num;
	char	*tmp;
	int		k;

	num = base_itoa(b, a, base, 0);
	if (b->width > ft_strlen(num))
	{
		tmp = ft_strnew(b->width);
		ft_memset(tmp, (b->zero && b->prec == -1) ? '0' : ' ', b->width);
		if (b->minus)
			ft_memcpy(tmp, num, ft_strlen(num));
		else
		{
			i = b->width - ft_strlen(num);
			k = 0;
			while (tmp[i])
				tmp[i++] = num[k++];
		}
	}
	else
		tmp = ft_strdup(num);
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
	free(tmp);
}

void	base_flags(va_list argptr, t_args *b, int base)
{
	unsigned long long int	a;
	void					*tmp;

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
	else if (b->ll)
		a = va_arg(argptr, unsigned long long int);
	else if (b->l)
		a = va_arg(argptr, unsigned long int);
	else if (b->h)
		a = (unsigned short)va_arg(argptr, unsigned int);
	else if (b->hh)
		a = (unsigned char)va_arg(argptr, unsigned int);
	else
		a = va_arg(argptr, unsigned int);
	if (a == 0 && b->flag != 'o')
		b->zero_x = 0;
	parse_base_flag(b, a, base, 0);
}