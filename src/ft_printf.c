#include "../includes/ft_printf.h"
#include <stdio.h>

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
}

void	add_to_buffer(t_args *b, char *str, int start, int end)
{
	char	*tmp;
	int	i;

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
	int		start;

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

	printf("\n-----------------------------------\n");
	printf("%%+d:  '%+d'\n", 123);
	printf("%%+d:  '%+d'\n", -123);
	printf("%%6d:  '%6d'\n", 123);
	printf("%%-6d:  '%-6d'\n", 123);
	printf("%%-6d:  '%-6d'\n", -123);
	printf("%%06d:  '%06d'\n", 123);
	printf("%%06d:  '%06d'\n", -123);
	printf("%%+05d:  '%+05d'\n", 10);
	printf("%%0+5d:  '%0+5d'\n", 10);
	printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
	printf("%%08.2f: '%08.2f'\n", 10.3456);	//Eight-wide, two positions after the decimal, zero-filled
	printf("%% d:     '% d'\n", 1234);
	printf("%% d:     '% d'\n", -1234);
	printf("%% +d:    '%+d'\n", 1234);
	printf("%%    d:     '%    d'\n", 1234);
	printf("%%    d:     '%    d'\n", -1234);
	printf("%%.1d:  '%.1d'\n", 123);
	printf("%%.6d:  '%.6d'\n", -123);
	printf("%%.6d:  '%.6d'//12345678\n", 12345678);
	printf("%%.06d:  '%.06d'\n", 123);
	printf("%%.6d:  '%.6d'\n", 123);
	printf("%%8.10d: '%8.10d'\n", 12345);
	printf("%%.30s: '%.30s'\n", "lolkekazaza");
	printf("%%8.20s: '%8.20s'\n", "lolkekazaza");
	printf("%%20.8s: '%20.8s'\n", "lolkekazaza");
	printf("%%5.s: '%5.s'\n", "lolkekazaza");
	printf("%%8.10d: '%8.10d'\n", 12345);

	ft_printf("\n-----------------------------------\n");
	ft_printf("%%+d:  '%+d'\n", 123);
	ft_printf("%%+d:  '%+d'\n", -123);
	ft_printf("%%6d:  '%6d'\n", 123);
	ft_printf("%%-6d:  '%-6d'\n", 123);
	ft_printf("%%-6d:  '%-6d'\n", -123);
	ft_printf("%%06d:  '%06d'\n", 123);
	ft_printf("%%06d:  '%06d'\n", -123);
	ft_printf("%%+05d:  '%+05d'\n", 10);
	ft_printf("%%0+5d:  '%0+5d'\n", 10);
	ft_printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
	ft_printf("%%08.2f: '%08.2f'\n", 10.3456);	//Eight-wide, two positions after the decimal, zero-filled
	ft_printf("%% d:     '% d'\n", 1234);
	ft_printf("%% d:     '% d'\n", -1234);
	ft_printf("%% +d:    '%+d'\n", 1234);
	ft_printf("%%    d:     '%    d'\n", 1234);
	ft_printf("%%    d:     '%    d'\n", -1234);
	ft_printf("%%.1d:  '%.1d'\n", 123);
	ft_printf("%%.6d:  '%.6d'\n", -123);
	ft_printf("%%.6d:  '%.6d'//12345678\n", 12345678);
	ft_printf("%%.06d:  '%.06d'\n", 123);
	ft_printf("%%.6d:  '%.6d'\n", 123);
	ft_printf("%%8.10d: '%8.10d'\n", 12345);
	ft_printf("%%.30s: '%.30s'\n", "lolkekazaza");
	ft_printf("%%8.20s: '%8.20s'\n", "lolkekazaza");
	ft_printf("%%20.8s: '%20.8s'\n", "lolkekazaza");
	ft_printf("%%5.s: '%5.s'\n", "lolkekazaza");
	ft_printf("%%8.10d: '%8.10d'\n", 12345);
	return (0);
}
