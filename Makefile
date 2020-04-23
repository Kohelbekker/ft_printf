NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC_D = src
OBJ_D = obj
HEADER = includes

FILES	= ft_printf.c \
				flags_helpers.c \
				flags.c \
				parse_base_flags.c \
				parse_char_flag.c \
				parse_digit_flag.c \
				parse_float_flags.c \
				no_type.c

SRCS = $(addprefix $(SRC_D)/,$(FILES))
OBJS = $(addprefix $(OBJ_D)/,$(FILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_D)/%.o: $(SRC_D)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@gcc $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_D)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: fclean re all clean