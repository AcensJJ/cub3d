# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:41:28 by jacens            #+#    #+#              #
#    Updated: 2021/01/14 15:20:38 by jacens           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    =   libftprintf.a

CC      =   gcc 
CFLAGS  =   -Wall -Wextra -Werror
DIR_LIB =	libft/
HEADER  =   includes

LFLAGS  =   -I $(HEADER)

SRCS    =	$(shell find srcs -name "*.c")

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

fclean: clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)

re : fclean all

.PHONY : all clean fclean re lib
