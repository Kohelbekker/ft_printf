#include "../includes/ft_printf.h"

void		flag_sign(t_args *b)
{
	char	*tmp;
	char	c;

	c = (b->zero) ? '0' : ' ';
	if (b->width)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, c, b->width);
		tmp[b->minus ? 0 : (b->width - 1)] = '%';
	}
	else
	{
		tmp = (char *)malloc(2);
		tmp[0] = '%';
		tmp[1] = '\0';
	}
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
}

char		*write_after_padding(t_args *b, char c, char *str, char *tmp)
{
	int		k;
	int		i;
	int		len;

	len = b->flag == 'c' ? 1 : ft_strlen((char *)str);
	if (b->flag != 'c')
		len = (b->prec != -1 && b->prec < len) ? b->prec : len;
	k = 0;
	i = b->width - len;
	if (b->flag == 'c')
		tmp[i] = c;
	else
	{
		while (tmp[i] && k < len)
		{
			tmp[i] = str[k];
			i++;
			k++;
		}
	}
	return (tmp);
}

void		parse_char_flag(t_args *b, char c, char *str)
{
	char	*tmp;
	int		len;

	if (str == NULL)
	{
		add_to_buffer(b, "(null)", 0, 6);
		return ;
	}
	len = b->flag == 'c' ? 1 : ft_strlen((char *)str);
	if (b->flag == 's')
		len = (b->prec != -1 && b->prec < len) ? b->prec : len;
	if (b->width > len)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		if (b->minus)
			b->flag == 's' ? ft_memcpy(tmp, str, len) : ft_memset(tmp, c, len);
		else
			tmp = write_after_padding(b, c, str, tmp);
	}
	else
	{
		tmp = (char *)malloc(len + 1);
		tmp[len] = '\0';
		tmp = b->flag == 's' ? ft_memcpy(tmp, str, len) : ft_memset(tmp, c, len);
	}
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
}