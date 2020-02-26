NAME =  libftprintf.a.

SRC				= main.c\
			      ls_lists.c \
			      ls_sorting.c \
			      path_lists.c \
			      path_sorting.c \
			      print_loop.c \
				  print_loop2.c \
				  flags.c \
				  ls_loop.c \
				  sort_type.c \
			      dir_loop.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), ft_printf.h)

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P), libft.a)
INC_LIB			= -I./libft
LNK_LIB			= -L./libft -lft

CC 				= gcc
CFLAGS			= -Wall -Wextra -Werror -c

all: obj $(ADD_LIB) $(NAME)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	$(CC) $(CFLAGS) $(INC_LIB) -I $(INC_P) -o $@ -c $<

$(ADD_LIB):
	make -C $(LIB_P)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_P)
	make -C $(LIB_P) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_P) fclean

re: fclean all

.PHONY: all clean fclean re