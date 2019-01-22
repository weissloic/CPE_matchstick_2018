#allo

CC = gcc

SRC = 	adresspointer.c \
		base.c \
		printfunc.c \
		printfdeux.c \
		printftrois.c \
		my_strcpy.c \
		my_put_nbr.c \
		my_put_nbr2.c \
		my_putchar.c \
		my_putstr.c \
		my_putstroctal.c \
		my_strlen.c \
		my_printf.c


OBJ = $(SRC:.c=.o) 

NAME = libmy.a

MYH = my.h

all: $(NAME)

$(NAME): $(OBJ)
	cp $(MYH) ../../include/
	ar rc $(NAME) $(OBJ)
	rm -f *.o

	

clean : 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean 