NAME = iganich.filler

FLAGS = -Wall -Wextra -Werror -o

SRCS =	src/checkingmap.c \
	src/different.c \
	src/inserting.c \
	src/reading.c \
	src/main.c \

OBJ=$(SRCS:.c=.o)

all: $(NAME)
	
$(NAME) : $(OBJ)
	make -C libft/
	make -C ft_printf/libft/
	make -C ft_printf/
	gcc $(FLAGS) $(NAME) $(SRCS)  -I /bin/ -L./libft -lft -L./ft_printf -lftprintf
clean:
	make -C libft/ clean
	make -C ft_printf/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f libft/libft.a
	rm -f ft_printf/libftprintf.a
	rm -f ft_printf/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
.NOTPARALLEL: all clean fclean re norm

norm:
	norminette *.c *.h
