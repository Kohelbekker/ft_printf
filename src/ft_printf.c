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
	b->prefix_exist = 0;
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

// int	main () {
// 	char *str;
// 	int		a;
// 	int		p;

// 	p = 12;
// 	// printf("\n-----------------------------------\n");
// 	// printf("%%    d:     '%    d'\n", 1234);
// 	// printf("%%    d:     '%    d'\n", -1234);
// 	// printf("%% d:     '% d'\n", 1234);
// 	// printf("%% d:     '% d'\n", -1234);
// 	// printf("%% +d:    '%+d'\n", 1234);
// 	// printf("%%+d:  '%+d'\n", 123);
// 	// printf("%%+d:  '%+d'\n", -123);
// 	// printf("%%6d:  '%6d'\n", 123);
// 	// printf("%%-6d:  '%-6d'\n", 123);
// 	// printf("%%-6d:  '%-6d'\n", -123);
// 	// printf("%%06d:  '%06d'\n", 123);
// 	// printf("%%06d:  '%06d'\n", -123);
// 	// printf("%%+05d:  '%+05d'\n", 10);
// 	// printf("%%0+5d:  '%0+5d'\n", 10);
// 	// printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
// 	// printf("%%.1d:  '%.1d'\n", 123);
// 	// printf("%%.6d:  '%.6d'\n", -123);
// 	// printf("%%.6d:  '%.6d'//12345678\n", 12345678);
// 	// printf("%%.06d:  '%.06d'\n", 123);
// 	// printf("%%.6d:  '%.6d'\n", 123);
// 	// printf("%%8.10d: '%8.10d'\n", 12345);
// 	// printf("%%8.10d: '%8.10d'\n", 12345);

// 	// ft_printf("\n-----------------------------------\n");
// 	// ft_printf("%%    d:     '%    d'\n", 1234);
// 	// ft_printf("%%    d:     '%    d'\n", -1234);
// 	// ft_printf("%% d:     '% d'\n", 1234);
// 	// ft_printf("%% d:     '% d'\n", -1234);
// 	// ft_printf("%% +d:    '%+d'\n", 1234);
// 	// ft_printf("%%+d:  '%+d'\n", 123);
// 	// ft_printf("%%+d:  '%+d'\n", -123);
// 	// ft_printf("%%6d:  '%6d'\n", 123);
// 	// ft_printf("%%-6d:  '%-6d'\n", 123);
// 	// ft_printf("%%-6d:  '%-6d'\n", -123);
// 	// ft_printf("%%06d:  '%06d'\n", 123);
// 	// ft_printf("%%06d:  '%06d'\n", -123);
// 	// ft_printf("%%+05d:  '%+05d'\n", 10);
// 	// ft_printf("%%0+5d:  '%0+5d'\n", 10);
// 	// ft_printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
// 	// ft_printf("%%.1d:  '%.1d'\n", 123);
// 	// ft_printf("%%.6d:  '%.6d'\n", -123);
// 	// ft_printf("%%.6d:  '%.6d'//12345678\n", 12345678);
// 	// ft_printf("%%.06d:  '%.06d'\n", 123);
// 	// ft_printf("%%.6d:  '%.6d'\n", 123);
// 	// ft_printf("%%8.10d: '%8.10d'\n", 12345);
// 	// ft_printf("%%8.10d: '%8.10d'\n", 12345);
// 	// ft_printf("x = %x//1234  \nX = %X//1234  \no = %o//1234  \nu = %u//1234\n", 1234, 1234, 1234, 1234);
// 	ft_printf("\n-----------------------------------\n");

// 	// printf("%f\n", 10.0 / 4.0 + 0.01);
// 	// ft_printf("FT:\n%f\n", 10.0 / 4.0 + 0.01);
// 	// printf("%.0f\n\n", 10.0 / 1.5);
// 	// ft_printf("FT:\n%.0f\n\n", 10.0 / 1.5);
// 	// printf("%.5f\n", 10.0 / 4.0 + 0.01);
// 	// ft_printf("FT:\n%.5f\n", 10.0 / 4.0 + 0.01);

// 	printf("'%015.3f'\n", 1000.99951);
// 	ft_printf("FT:'%015.3f'\n", 1000951);
// 	printf("'%015d'\n", 1000951);
// 	ft_printf("FT:'%015d'\n", 1000951);




// 	// printf("%%x = %x//1234  \n%%X = %X//1234  \n%%o = %o//1234  \n%%u = %u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: %%x = %x//1234  \nX = %X//1234  \no = %o//1234  \nu = %u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%010x = %010x//1234  \n%%010X = %010X//1234  \n%%010o = %010o//1234  \n%%010u = %010u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: %%010x = %010x//1234  \n%%010X= %010X//1234  \n%%010o = %010o//1234  \n%%010u = %010u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%#010.1x = '%#010.1x'//1234  \n%%#010.12X = '%#010.12X'//1234  \n%%#010x = '%#010o'//1234  \n%%#010.4u = '%#010.4u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: \n%%#010.1x = '%#010.1x'//1234  \n%%#010.12X = '%#010.12X'//1234  \n%%#010x = '%#010o'//1234  \n%%#010.4u = '%#010.4u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%#010.8x = '%#010.8x'//1234  \n%%#010.8X = '%#010.8X'//1234  \n%%#010.8o = '%#010.8o'//1234  \n%%#010.8u = '%#010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: \n%%#010.8x = '%#010.8x'//1234  \n%%#010.8X = '%#010.8X'//1234  \n%%#010.8o = '%#010.8o'//1234  \n%%#010.8u = '%#010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%010.8x = '%010.8x'//1234  \n%%010.8X = '%010.8X'//1234  \n%%010.8o = '%010.8o'//1234  \n%%010.8u = '%010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: \n%%010.8x = '%010.8x'//1234  \n%%010.8X = '%010.8X'//1234  \n%%010.8o = '%010.8o'//1234  \n%%010.8u = '%010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%10.8x = '%10.8x'//1234  \n%%10.8X = '%10.8X'//1234  \n%%10.8o = '%10.8o'//1234  \n%%10.8u = '%10.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: \n%%10.8x = '%10.8x'//1234  \n%%10.8X = '%10.8X'//1234  \n%%10.8o = '%10.8o'//1234  \n%%10.8u = '%10.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%010.14x = %010.14x//1234  \n%%010.14X = %010.14X//1234  \n%%010.14o = %010.14o//1234  \n%%010.14u = %010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: %%010.14x = %010.14x//1234  \n%%010.14X = %010.14X//1234  \n%%010.14o = %010.14o//1234  \n%%010.14u = %010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("%%#010.14x = %#010.14x//1234  \n%%#010.14X= %#010.14X//1234  \n%%#010.14o = %#010.14o//1234  \n%%#010.14u = %#010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// ft_printf("FT: %%#010.14x = %#010.14x//1234  \n%%#010.14X = %#010.14X//1234  \n%%#010.14o = %#010.14o//1234  \n%%#010.14u = %#010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
// 	// printf("\n-----------------------------------\n");
// 	// printf("'#x = %#x//1234  \n#X = %#X//1234  \n#o = %#o//1234'\n", 1234, 1234, 1234);
// 	// printf("%%p: %p\n", &p);
// 	// ft_printf("'#x = %#x//1234  \n#X = %#X//1234  \n#o = %#o//1234'\n", 1234, 1234, 1234);
// 	// ft_printf("%%p: %p\n", &p);
// 	// printf("%010.8d", 1234);
// 	// ft_printf("%010.8d", 1234);
// 	return (0);
// }
