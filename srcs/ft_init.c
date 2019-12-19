/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:51:04 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 18:55:38 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		ft_init_ray(t_file *file)
{
	if (!(RAY = malloc(sizeof(t_ray))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc ray\n");
		return (0);
	}
	RAY->hit = 0;
	RAY->mapy = 0;
	RAY->mapx = 0;
	RAY->side = 0;
	RAY->sidex = 0;
	RAY->sidey = 0;
	RAY->stepy = 0;
	RAY->stepx = 0;
	RAY->raydiry = 0;
	RAY->raydirx = 0;
	RAY->deltdistx = 0;
	RAY->deltdisty = 0;
	RAY->perpWallDist = 0;
	return (1);
}

int		ft_init_color(t_file *file)
{
	if (!(FC = malloc(sizeof(t_color))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc color\n");
		return (0);
	}
	FC->f1 = -1;
	FC->f2 = -1;
	FC->f3 = -1;
	FC->c1 = -1;
	FC->c2 = -1;
	FC->c3 = -1;
	return (1);
}

int		ft_init_map(t_file *file)
{
	if (!(MAP = malloc(sizeof(t_map))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc map\n");
		return (0);
	}
	MAP->map = NULL;
	MAP->width = 0;
	MAP->height = 0;
	MAP->mapchar = NULL;
	return (1);
}

int		ft_init_player(t_file *file)
{
	if (!(PLAYER = malloc(sizeof(t_player))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc player\n");
		return (0);
	}
	PLAYER->direction = 0;
	PLAYER->rotation = 0;
	PLAYER->y = -1;
	PLAYER->x = -1;
	PLAYER->camx = 0;
	PLAYER->diry = 0;
	PLAYER->dirx = 0;
	PLAYER->plany = 0;
	PLAYER->planx = 0;
	return (1);
}

int		ft_init_path(t_file *file)
{
	if (!(PATH = malloc(sizeof(t_path))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc init\n");
		return (0);
	}
	PATH->north = NULL;
	PATH->south = NULL;
	PATH->east = NULL;
	PATH->west = NULL;
	PATH->sprite = NULL;
	return (1);
}
