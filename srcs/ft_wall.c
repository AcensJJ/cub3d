/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wall.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:30:47 by jacens      ###    #+. /#+    ###.fr     */
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
		if ((IMGW->img[0] = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[0],
		&IMGW->height[0])))
			data = (int *)mlx_get_data_addr(IMGW->img[0], &bits, &sl, &endian);
	if (c == 'S')
		if ((IMGW->img[1] = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[1],
		&IMGW->height[1])))
			data = (int *)mlx_get_data_addr(IMGW->img[1], &bits, &sl, &endian);
	if (c == 'E')
		if ((IMGW->img[2] = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[2],
		&IMGW->height[2])))
			data = (int *)mlx_get_data_addr(IMGW->img[2], &bits, &sl, &endian);
	if (c == 'W')
		if ((IMGW->img[3] = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[3],
		&IMGW->height[3])))
			data = (int *)mlx_get_data_addr(IMGW->img[3], &bits, &sl, &endian);
	if (c == 'Z')
		if ((IMGW->img[4] = mlx_xpm_file_to_image(F->mlx, str, &IMGW->width[4],
		&IMGW->height[4])))
			data = (int *)mlx_get_data_addr(IMGW->img[4], &bits, &sl, &endian);
	return (data);
}

void		draw_suite(t_file *file, int x, int texnum)
{
	int y = 0;

	while (y < F->axe_x)
	{
		if (y < DRAW->start)
			F->imgdata[y * F->axe_y + x] = ft_rgbtoint(FC->f1, FC->f2, FC->f3);
		if (y >= DRAW->start && y <= DRAW->end)
		{
			DRAW->d = y * 256 - F->axe_x * 128 + DRAW->lineheight * 128;
			DRAW->texy = ((DRAW->d * IMGW->height[texnum])
			/ DRAW->lineheight) / 256;
			DRAW->texy < 0 ? DRAW->texy = 0 : 0;
			if (IMGW->height[texnum] * IMGW->width[texnum]
				> (DRAW->texy * IMGW->width[texnum] + DRAW->texx))
				F->imgdata[y * F->axe_y + x] = IMGW->text[texnum][(DRAW->texy
				* IMGW->width[texnum] + DRAW->texx)];
		}
		if (y >= DRAW->end)
			F->imgdata[y * F->axe_y + x] = ft_rgbtoint(FC->c1, FC->c2, FC->c3);
		y++;
	}
}

void		draw(t_file *file, int x)
{
	int		texnum;
	double	wallx;

	texnum = 10;
	(RAY->side == 0 && RAY->mapx > PLAYER->x) ? (texnum = 2) : 0;
	(RAY->side == 0 && RAY->mapx < PLAYER->x) ? (texnum = 0) : 0;
	(RAY->side == 1 && RAY->mapy > PLAYER->y) ? (texnum = 1) : 0;
	(RAY->side == 1 && RAY->mapy < PLAYER->y) ? (texnum = 3) : 0;
	wallx = RAY->side == 0 ? PLAYER->y + RAY->perpwalldist
	* RAY->raydiry :
	PLAYER->x + RAY->perpwalldist * RAY->raydirx;
	wallx -= floor(wallx);
	DRAW->texx = (int)(wallx * (double)IMGW->width[texnum]);
	if ((RAY->side == 0 && RAY->raydirx > 0) ||
		(RAY->side == 1 && RAY->raydiry < 0))
		DRAW->texx = IMGW->width[texnum] - DRAW->texx - 1;
	DRAW->lineheight = (int)(F->axe_x / RAY->perpwalldist);
	DRAW->lineheight > 19 * F->axe_x ? DRAW->lineheight = 19 * F->axe_x : 0;
	DRAW->start = -DRAW->lineheight / 2 + F->axe_x / 2;
	DRAW->end = DRAW->lineheight / 2 + F->axe_x / 2;
	(DRAW->start < 0) ? DRAW->start = 0 : 0;
	(DRAW->end >= F->axe_x) ? DRAW->end = F->axe_x - 1 : 0;
	draw_suite(F, x, texnum);
}

void		hit_wall(t_file *file)
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
		if (MAP->map[RAY->mapx][RAY->mapy] == '1')
			RAY->hit = 1;
	}
	if (RAY->side == 0)
		RAY->perpwalldist =
			(RAY->mapx - PLAYER->x + (1 - RAY->stepx) / 2) / RAY->raydirx;
	else
		RAY->perpwalldist =
			(RAY->mapy - PLAYER->y + (1 - RAY->stepy) / 2) / RAY->raydiry;
}
