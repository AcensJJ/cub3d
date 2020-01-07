/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_loop.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:27:53 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void		ray_cast_suite(t_file *file)
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
}

void		raycast(t_file *file)
{
	int		i;

	i = 0;
	RAY->mapx = (int)PLAYER->x;
	RAY->mapy = (int)PLAYER->y;
	mlx_clear_window(F->mlx, F->win);
	while (i < F->axe_y)
	{
		RAY->hit = 0;
		PLAYER->camx = 2 * i / (double)F->axe_y - 1;
		RAY->raydirx = PLAYER->dirx + PLAYER->planx * PLAYER->camx;
		RAY->raydiry = PLAYER->diry + PLAYER->plany * PLAYER->camx;
		RAY->mapx = (int)PLAYER->x;
		RAY->mapy = (int)PLAYER->y;
		RAY->deltdistx = fabs(1 / RAY->raydirx);
		RAY->deltdisty = fabs(1 / RAY->raydiry);
		ray_cast_suite(file);
		hit_wall(file);
		draw(file, i);
		i++;
	}
//	draw_sprite(mlx, buffer);
//	if (mlx->save == 0)
		mlx_put_image_to_window(F->mlx, F->win, F->img, 0, 0);
}

int			ft_snakeoil(t_file *file)
{
	raycast(F);
	ft_move(F);
	return (1);
}
