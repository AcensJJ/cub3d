/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wall.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 21:54:53 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			*ft_readxpm(t_file *file, char *str, char c)
{
	int		*data;
	int		bits;
	int		sl;
	int		endian;

	if (c == 'N')
		if ((IMGW->nimg = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[0],
		&IMGW->height[0])))
			data = (int *)mlx_get_data_addr(IMGW->nimg, &bits, &sl, &endian);
	if (c == 'S')
		if ((IMGW->simg = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[1],
		&IMGW->height[1])))
			data = (int *)mlx_get_data_addr(IMGW->simg, &bits, &sl, &endian);
	if (c == 'E')
		if ((IMGW->eimg = mlx_xpm_file_to_image(F->mlx, str, &(IMGW->width[2]),
		&(IMGW->height[2]))))
			data = (int *)mlx_get_data_addr(IMGW->eimg, &bits, &sl, &endian);
	if (c == 'W')
		if ((IMGW->wimg = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[3],
		&IMGW->height[3])))
			data = (int *)mlx_get_data_addr(IMGW->wimg, &bits, &sl, &endian);
	return (data);
}

void		ft_walldist(t_file *file, int i)
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
	DRAW->startneg = (DRAW->start < 0 ? -DRAW->start : 0);
	DRAW->start < 0 ? DRAW->start = 0 : 0;
	DRAW->end = DRAW->lineheight / 2 + F->axe_x / 2;
	DRAW->endneg = (DRAW->end >= F->axe_x ? DRAW->end - (F->axe_x - 1) : 0);
	DRAW->end >= F->axe_x ? DRAW->end = F->axe_x - 1 : 0;
	j = -1;
	while (++j < F->axe_x)
	{
		j < DRAW->start ? F->imgdata[j * F->axe_y + i] =
		ft_rgbtoint(FC->f1, FC->f2, FC->f3) : 0;
		j >= DRAW->start && j <= DRAW->end ? ft_printwall(F, j, i) : 0;
		j > DRAW->end ? F->imgdata[j * F->axe_y + i] =
		ft_rgbtoint(FC->c1, FC->c2, FC->c3) : 0;
	}
}

void		ft_wallhit(t_file *file, int i)
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
	ft_walldist(F, i);
}
