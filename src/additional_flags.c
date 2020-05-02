#include "../includes/ft_printf.h"

void    additional_flags(t_args *b)
{
	time_t now;
	struct tm *s_time;
	char **tmp;
	char *str;

	time(&now);
	s_time = localtime(&now);
	tmp = ft_strsplit(asctime(s_time), ' ');
	if (b->flag == 't')
		add_to_buffer(b, tmp[3], 0, ft_strlen(tmp[3]));
	else
	{
		str = ft_strjoin(ft_strjoin(ft_strjoin(tmp[1], "/"), ft_strjoin(tmp[2], "/")), tmp[4]);
		add_to_buffer(b, str, 0, ft_strlen(str));
		free(str);
	}
	free(tmp);
}