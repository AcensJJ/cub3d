# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/18 15:41:28 by jacens       #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 17:57:53 by jacens      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    =   libftprintf.a

CC      =   gcc 
CFLAGS  =   -Wall -Wextra -Werror
DIR_LIB =	libft/
HEADER  =   includes

LFLAGS  =   -I $(HEADER)

SRCS    =	srcs/ft_printf.c\
			srcs/ft_printf_outils.c\
			srcs/ft_printf_outils2.c\
			srcs/ft_printf_outils3.c\
			srcs/ft_flags_printf.c\
			srcs/ft_pre_printf.c\
			srcs/ft_config_stru.c\
			srcs/ft_check_va.c\
			srcs/ft_pre_cas_d.c\
			srcs/ft_pre_cas_d_2.c\
			srcs/ft_pre_cas_d_3.c\
			srcs/ft_pre_cas_d_4.c\

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