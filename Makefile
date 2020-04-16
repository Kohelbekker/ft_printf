NAME = libftprintf.a #Makefile піжжєний!!!

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADER = includes

SOURCES	= ft_printf.c \
					flags_helpers.c \
					flags.c \
					parse_base_flags.c \
					parse_char_flag.c \
					parse_digit_flag.c \
					parse_float_flags.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean