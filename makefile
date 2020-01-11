# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/10 09:26:26 by jacens       #+#   ##    ##    #+#        #
#    Updated: 2020/01/11 14:39:52 by jacens      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#								VARIABLES									   #
# **************************************************************************** #
HEADER		=					./includes/cube.h
MINILIBX	=					libmlx.a
MINILIBXS	=					minilibx/libmlx.a
LIB			=					libftprintf.a
LIBS		=					ft_printf/libftprintf.a
SRC_PATH	=					srcs
SRCS_NAME	= 					cube.c ft_loop.c ft_set_color.c ft_move.c\
								ft_init.c ft_init2.c ft_init3.c ft_free.c\
								ft_free2.c  ft_config_map.c ft_config_map2.c\
								ft_verif.c ft_keys.c ft_verif2.c ft_wall.c\
								ft_sprite_draw.c ft_bmp_conv.c ft_hud.c\
								ft_config_struct.c ft_sprite_lst.c
OBJS		= 					${SRCS:.c=.o}
FW_PATH     =                   ./frameworks
LIBSDL2     =                   -framework SDL2 -F $(FW_PATH) -framework SDL2_mixer -rpath $(FW_PATH)
LIBRARIES   =                   $(LIBSDL2) $(LIBS) $(MINILIBXS)
NAME		= 					Cub3D
RM			= 					rm -f
FLAGS 		= 					-Wall -Wextra -Werror -g3
GFLAGS 		=					-Wall -Wextra -Werror -g3 -fsanitize=address -lmlx -framework OpenGL -framework AppKit\
								-I$(INCLUDE_PATH)\
								-I./$(LIBSDLMIXER)/\
								-I$(FW_PATH)/SDL2.framework/Headers/\
								-I$(FW_PATH)/SDL2_mixer.framework/Headers/
GFLAGS2 	=					-Wall -Wextra -Werror -g3\
								-I./$(LIBSDLMIXER)/\
								-I$(INCLUDE_PATH)\
								-I$(FW_PATH)/SDL2.framework/Headers/\
								-I$(FW_PATH)/SDL2_mixer.framework/Headers/
SRCS 		= 					$(addprefix $(SRC_PATH)/,$(SRCS_NAME))
INCLUDE_PATH = 					./includes
# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #
all:							$(NAME)
%.o: %.c 						$(HEADER) $(LIBS) $(MINILIBXS)
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
								@gcc  $(GFLAGS2) -I $(HEADER) -c $< -o $@
$(NAME):						$(MINILIBX) $(LIB) $(OBJS) $(HEADER)
								@gcc  $(OBJS) -L minilibx $(GFLAGS) $(LIBRARIES) -o $(NAME) -lm
								@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Cube3D\033[0m"
$(MINILIBX) :
								@$(MAKE) -C minilibx all
$(LIB):
								@$(MAKE) -C ft_printf all
clean:
								@$(MAKE) -C ft_printf clean
								@$(MAKE) -C minilibx clean
								@echo "\x1b[36m[OK] \033[0m \x1b[34m Removing ALL File object\033[0m"
								@$(RM) $(OBJS)
fclean:							clean
								@$(MAKE) -C ft_printf fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[32m All is Removing\033[0m"
								@$(RM) $(NAME)
re:								fclean all
bonus:							all
.PHONY: 						clean fclean