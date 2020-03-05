#include "../includes/ft_printf.h"

void     parse_digit_flag(t_args *b, long long int a)
{
	char	*num;
  char  *tmp;
  char  *res;
  int   len;
  int   i;

  i = 0;
	num = ft_itoa(a);
  len = b->space ? ft_strlen(num) + 1 : ft_strlen(num);
  len += (b->plus && (a > 0)) ? 1 : 0;
  if (b->space || b->plus)
  {
    tmp = ft_strdup(num);
    free(num);
    num = (char *)malloc(len + 1);
    num[len] = '\0';
    if (b->space)
      num[i++] = ' ';
    if (b->plus && a > 0)
      num[i] = '+';
  }
  if (b->prec > b->width)
  {
    b->width = b->prec;
    b->zero = 1;
  }
  if (b->width > len)
  {
    tmp = (char *)malloc(b->width + 1);
		tmp[b->width] = '\0';
		ft_memset(tmp, (b->zero) ? '0' : ' ', b->width);
		if (b->minus)
			tmp = ft_memcpy(tmp, str, len);
		else
			tmp = write_after_padding(b, c, str, tmp);
  }

}

void	number_flags(va_list argptr, t_args *b)
{
	long long int a;
	if (b->h)
		a = (short)va_arg(argptr, int);
	else if (b->hh)
		a = (char)va_arg(argptr, int);
	else if (b->l)
		a = va_arg(argptr, long int);
	else if (b->ll)
		a = va_arg(argptr, long long int);
	else
		a = va_arg(argptr, int);
	parse_digit_flag(b, a);
}
