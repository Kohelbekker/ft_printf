#include "../includes/ft_printf.h"

void		clear_struct(t_args *b)
{
	b->flag = 0;
	b->zero_x = 0;
	b->zero = 0;
	b->minus = 0;
	b->plus = 0;
	b->prec = -1;
	b->width = 0;
	b->space = 0;
	b->hh = 0;
	b->h = 0;
	b->ll = 0;
	b->l = 0;
	b->l_cap = 0;
	b->prefix_exist = 0;
}

void	add_to_buffer(t_args *b, char *str, int start, int end)
{
	char	*tmp;
	int		i;

	i = b->buf ? ft_strlen(b->buf) : 0;
	if (!b->buf)
		b->buf = (char *)malloc(sizeof(char) * (end + 1));
	else
	{
		tmp = ft_strdup(b->buf);
		free(b->buf);
		b->buf = (char *)malloc(ft_strlen(tmp) + (end - start) + 1);
		ft_strcpy(b->buf, tmp);
		free(tmp);
	}
	while (start < end)
	{
		b->buf[i] = str[start];
		i++;
		start++;
	}
	b->buf[i] = '\0';
}

void	main_loop(va_list argptr, t_args *b, char *str)
{
	while (str[b->i])
	{
		b->start = b->i;
		while (str[b->i] != '%' && str[b->i] != '\0')
			b->i++;
		add_to_buffer(b, str, b->start, b->i);
		if (str[b->i] == '%')
		{
			b->start = b->i++;
			find_flag(argptr, b, str);
			clear_struct(b);
		}
	}
}

int     ft_printf(const char *format, ...)
{
	char	*str;
	va_list	argptr;
	t_args	*b;
	int		len;

	if (format[0] == '\0')
		return (0);
	b = (t_args *)malloc(sizeof(t_args));
	clear_struct(b);
	b->i = 0;
	b->start = 0;
	b->buf = 0;
	va_start(argptr, format);
	str = (char *)format;
	main_loop(argptr, b, str);
	va_end(argptr);
	len = ft_strlen(b->buf);
	ft_putstr(b->buf);
	free(b);
	return (len);
}
