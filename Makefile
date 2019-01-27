##
## EPITECH PROJECT, 2018
## 104pong_2018
## File description:
## The Makefile of the 104intersection project
##

NAME = matchstick

SRC =	main.c \
		create_map.c \
		my_atoi.c \
		lib.c \
		ai.c \
		player.c \
		lib/my/adresspointer.c \
		lib/my/base.c \
		lib/my/printfunc.c \
		lib/my/printfdeux.c \
		lib/my/printftrois.c \
		lib/my/my_put_nbr.c \
		lib/my/my_put_nbr2.c \
		lib/my/my_putchar.c \
		lib/my/my_putstr.c \
		lib/my/my_putstroctal.c \
		lib/my/my_strlen.c \
		lib/my/my_printf.c


OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -sC lib/my
	gcc -o $(NAME) $(SRC) -lm

clean:
	rm *.o
fclean:
	rm -f $(NAME)
	make clean

re: fclean all

.phony: all clean fclean $(NAME)
