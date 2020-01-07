/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 20:04:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:00:28 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		ft_init_draw(t_file *file)
{
	if (!(DRAW = malloc(sizeof(t_draw))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc ray\n");
		return (0);
	}
	DRAW->start = 0;
	DRAW->end = 0;
	DRAW->lineheight = 0;
	return (1);
}

int		ft_init_key(t_file *file)
{
	if (!(KEY = malloc(sizeof(t_key))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc key\n");
		return (0);
	}
	KEY->mvleft = 0;
	KEY->mvright = 0;
	KEY->left = 0;
	KEY->right = 0;
	KEY->up = 0;
	KEY->down = 0;
	return (1);
}

int		ft_init_sprite(t_file *file, int x, int y)
{
	if (!(SPRITE = malloc(sizeof(t_sprite))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc sprite\n");
		return (0);
	}
	SPRITE->y = y;
	SPRITE->x = x;
	SPRITE->next = NULL;
	return (1);
}

int		ft_init_imgw(t_file *file)
{
	if (!(IMGW = malloc(sizeof(t_imgw))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc image wall\n");
		return (0);
	}
	IMGW->text[0] = NULL;
	IMGW->text[1] = NULL;
	IMGW->text[2] = NULL;
	IMGW->text[3] = NULL;
	IMGW->text[4] = NULL;
	IMGW->img[0] = NULL;
	IMGW->img[1] = NULL;
	IMGW->img[2] = NULL;
	IMGW->img[3] = NULL;
	IMGW->img[4] = NULL;
	return (1);
}
