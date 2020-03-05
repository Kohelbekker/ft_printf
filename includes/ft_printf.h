#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_args
{
	char	*buf;
	char	flag;
	int		start;
	int		i;
	int		zero_x;
	int		zero;
	int		minus;
	int		plus;
	int		prec;
	int		width;
	int		space;
	int		hh;
	int		h;
	int		ll;
	int		l;
	int		l_cap;
}				t_args;

int     check_length(int i);
void	width_search(t_args *b, char *str);
void	flag_sign(t_args *b);
void	find_flag(va_list argptr, t_args *b, char *str);
void	add_to_buffer(t_args *b, char *str, int start, int end);
void	parse_char_flag(t_args *b, char c, char *str);
void	number_flags(va_list argptr, t_args *b);
void  float_flags();
void  base_flags();

#endif