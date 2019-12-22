/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_loop.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 06:09:01 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_ray(t_file *file, int i)
{
	if (RAY->raydirx < 0)
	{
		RAY->stepx = -1;
		RAY->sidex = (PLAYER->x - RAY->mapx) * RAY->deltdistx;
	}
	else
	{
		RAY->stepx = 1;
		RAY->sidex = (RAY->mapx + 1.0 - PLAYER->x) * RAY->deltdistx;
	}
	if (RAY->raydiry < 0)
	{
		RAY->stepy = -1;
		RAY->sidey = (PLAYER->y - RAY->mapy) * RAY->deltdisty;
	}
	else
	{
		RAY->stepy = 1;
		RAY->sidey = (RAY->mapy + 1.0 - PLAYER->y) * RAY->deltdisty;
	}
	ft_wallhit(F, i);
}

static void	raycast(t_file *file)
{
	int	i;

	i = 0;
	while (i < F->axe_y)
	{
		RAY->hit = 0;
		RAY->mapx = (int)PLAYER->x;
		RAY->mapy = (int)PLAYER->y;
		PLAYER->camx = 2 * i / (float)F->axe_y - 1;
		RAY->raydirx = PLAYER->dirx + PLAYER->planx * PLAYER->camx;
		RAY->raydiry = PLAYER->diry + PLAYER->plany * PLAYER->camx;
		RAY->deltdistx = fabs(1 / RAY->raydirx);
		RAY->deltdisty = fabs(1 / RAY->raydiry);
		ft_ray(file, i);
		i++;
	}
	mlx_put_image_to_window(F->mlx, F->win, F->img, 0, 0);
}

int			ft_snakeoil(t_file *file)
{
	//mlx_clear_window(F->mlx, F->win);
	raycast(F);
	ft_move(F);
	return (1);
}
