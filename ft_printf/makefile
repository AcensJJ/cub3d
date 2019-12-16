# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/18 15:41:28 by jacens       #+#   ##    ##    #+#        #
#    Updated: 2019/12/16 15:07:04 by jacens      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    =   libftprintf.a

CC      =   gcc 
CFLAGS  =   -Wall -Wextra -Werror
DIR_LIB =	libft/
HEADER  =   includes

LFLAGS  =   -I $(HEADER)

SRCS    =	$(shell find . -name "*.c")

OBJ     =   $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	make -C $(DIR_LIB)

$(NAME): $(OBJ) $(DIR_LIB)libft.a
	cp $(DIR_LIB)libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c $(HEADER)/ft_printf.h
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(DIR_LIB)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C $(DIR_LIB)

re : fclean all

.PHONY : all clean fclean remake