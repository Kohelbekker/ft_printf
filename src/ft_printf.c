#include "../includes/ft_printf.h"
#include <stdio.h>

void		clear_struct(t_args *b)
{
	b->flag = 0;
	b->zero_x = 0;
	b->zero = 0;
	b->minus = 0;
	b->plus = 0;
	b->prec = 0;
	b->width = 0;
	b->space = 0;
	b->hh = 0;
	b->h = 0;
	b->ll = 0;
	b->l = 0;
	b->l_cap = 0;
}

int     check_length(int i)
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

void	add_to_buffer(t_args *b, char *str, int start, int end)
{
	char	*tmp;
	int	i;

	if (b->buf)
		printf("buf = %s\n", b->buf);
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

void	precision_search(t_args *b, char *str)
{
	b->i++;
	while(str[b->i] && ft_isdigit(str[b->i]))
	{
		b->prec *= 10;
		b->prec += str[b->i++] -'0';
	}

}

void	width_search(t_args *b, char *str)
{
	while (str[b->i] && ft_isdigit(str[b->i]))
	{
		b->width *= 10;
		b->width += str[b->i++] - '0';
	}
}

void	size_search(t_args *b, char *str)
{
	if (str[b->i] == 'l' && str[b->i + 1] != 'l')
		b->l = 1;
	else if (str[b->i] == 'l' && str[b->i + 1] == 'l')
		b->ll = 1;
	else if (str[b->i] == 'h' && str[b->i + 1] != 'h')
		b->h = 1;
	else if (str[b->i] == 'h' && str[b->i + 1] == 'h')
		b->hh = 1;
	else if (str[b->i] == 'L')
		b->l_cap = 1;
}

void	sign_search(t_args *b, char *str)
{
	int i;

	i = b->i;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0' ||
		str[i] == '#' || str[i] == ' ')
	{
		if (str[i] == '+')
			b->plus = 1;
		if (str[i] == '-')
			b->minus = 1;
		if (str[i] == '#')
			b->zero_x = 1;
		if (str[i] == ' ')
			b->space = 1;
		if (str[i] == '0')
			b->zero = 1;
		i++;
	}
	b->i = i;
}

void	flag_sign(t_args *b, char *str)
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

char	*write_after_padding(t_args *b, char c, char *str, char *tmp)
{
	int	k;
	int	i;
	int		len;

	len = b->flag == 'c' ? 1 : ft_strlen((char *)str);
	k = 0;
	i = b->width - len;
	if (b->flag == 'c')
		tmp[i] = c;
	else
	{
		while (tmp[i])
		{
			tmp[i] = str[k];
			i++;
			k++;
		}
	}
	return (tmp);
}

void	parse_char_flag(t_args *b, char c, char *str)
{
	char		*tmp;
	int		i;
	int		len;

	len = b->flag == 'c' ? 1 : ft_strlen((char *)str);
	i = 0;
	if (b->width > len)
	{
		tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, (b->zero) ? '0' : ' ', b->width);
		if (b->minus)
			tmp = b->flag == 's' ? ft_memcpy(tmp, str, len) : ft_memset(tmp, c, len);
		else
			tmp = write_after_padding(b, c, str, tmp);
	}
	else
	{
		tmp = (char *)malloc(len + 1);
		tmp = b->flag == 's' ? ft_memcpy(tmp, str, len) : ft_memset(tmp, c, len);
		tmp[len] = '\0';
	}
	add_to_buffer(b, tmp, 0, ft_strlen(tmp));
}

void	parse_pointer_flag()
{

}

void	simple_flags(va_list p, t_args *b, char *str)
{
	if (b->flag == 'c')
		parse_char_flag(b, va_arg(p, int), NULL);
	else if (b->flag == 's')
		parse_char_flag(b, 0, va_arg(p, char*)); // try to delete (void *)
	else if (b->flag == 'p')
		parse_pointer_flag(b, va_arg(p, void*));
}

void	base_flags(va_list argptr, t_args *b, char *str)
{
	
}

void	number_flags(va_list argptr, t_args *b, char *str)
{
	
}

void	float_flags()
{

}

void	flag_search(va_list argptr, t_args *b, char *str)
{
	b->flag = str[b->i];

	if (b->flag == 'c' || b->flag == 's' || b->flag == 'p')
		simple_flags(argptr, b, str);
	else if (b->flag == 'f')
		float_flags(argptr, b, str);
	else if (b->flag == 'u' || b->flag == 'o' || b->flag == 'x' ||
		b->flag == 'X')
		base_flags(argptr, b, str);
	else if (b->flag == 'd' || b->flag == 'i')
		number_flags(argptr, b, str);
	else if (b->flag == '%')
		flag_sign(b, str);
	else
		add_to_buffer(b,  str, b->start, b->i);
	b->i++;
}

void	find_flag(va_list argptr, t_args *b, char *str)
{
	sign_search(b, str);
	width_search(b, str);
	if (str[b->i] == '.')
		precision_search(b, str);
	size_search(b, str);
	flag_search(argptr, b, str);
}

void	main_loop(va_list argptr, t_args *b, char *str)
{
	int		start;

	while (str[b->i])
	{
		b->start = b->i;
		while (str[b->i] != '%' && str[b->i] != '\0')
		{
			printf("%c\n", str[b->i]);
			b->i++;
		}
		add_to_buffer(b, str, b->start, b->i);
		printf("done\n");
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
	char		*str;
	va_list	argptr;
	t_args	*b;
	int		len;

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

int	main () {
	char *str;
	int		a;

	a = ft_printf("'lol %s kek'\n", "sho ty dyadya?");
	printf("return = %d\n", a);
	return (0);
}

