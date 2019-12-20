/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 02:35:28 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_walldist(t_file *file, int i)
{
	int j;

	if (RAY->side == 0)
	{
		RAY->perpwalldist = (RAY->mapx - PLAYER->x +
		(1 - RAY->stepx) / 2) / RAY->raydirx;
	}
	else
		RAY->perpwalldist = (RAY->mapy - PLAYER->y +
		(1 - RAY->stepy) / 2) / RAY->raydiry;
	DRAW->lineheight = (int)(F->axe_x / RAY->perpwalldist);
	DRAW->start = -DRAW->lineheight / 2 + F->axe_x / 2;
	DRAW->start < 0 ? DRAW->start = 0 : 0;
	DRAW->end = DRAW->lineheight / 2 + F->axe_x / 2;
	DRAW->end >= F->axe_x ? DRAW->end = F->axe_x - 1 : 0;
	j = -1;
	while (++j < F->axe_x)
	{
		j <= DRAW->start ? F->imgdata[j * F->axe_y + i] =
		ft_rgbtoint(FC->f1, FC->f2, FC->f3) : 0;
		j < DRAW->end && j > DRAW->start ? F->imgdata[j * F->axe_y + i] =
		ft_rgbtoint(60, 60, 60) : 0;
		j >= DRAW->end ? F->imgdata[j * F->axe_y + i] =
		ft_rgbtoint(FC->c1, FC->c2, FC->c3) : 0;
	}
}

static void	ft_wallhit(t_file *file, int i)
{
	while (RAY->hit == 0)
	{
		if (RAY->sidex < RAY->sidey)
		{
			RAY->sidex += RAY->deltdistx;
			RAY->mapx += RAY->stepx;
			RAY->side = 0;
		}
		else
		{
			RAY->sidey += RAY->deltdisty;
			RAY->mapy += RAY->stepy;
			RAY->side = 1;
		}
		(MAP->map[RAY->mapx][RAY->mapy] == '1') ? RAY->hit = 1 : 0;
	}
	printf("wall hit at = x = %i, y = %i\n", RAY->mapx, RAY->mapy);
	ft_walldist(F, i);
}

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
	raycast(F);
	return (1);
}
