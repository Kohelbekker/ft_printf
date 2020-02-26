#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_args
{
  char  *type;
	int   i;
	int   zero_x;
	int   zero;
	int   minus;
	int   plus;
	int   prec;
	int   width;
	int   space;
	int   hh;
	int   h;
	int   ll;
	int   l;
	int   l_cap;
}				t_args ;

#endif