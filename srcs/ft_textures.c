/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:00:27 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void		get_path_color(t_file *file, int j, int i, int nb)
{	
	double d;
	int texx;
	int texy;
	int wallx;

	wallx = (RAY->side == 0 ? PLAYER->y + RAY->perpwalldist * RAY->raydiry :
	PLAYER->x + RAY->perpwalldist * RAY->raydirx);
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)(IMGW->width[nb]));
    if (RAY->side == 0 && RAY->raydirx > 0)
		texx = IMGW->width[nb] - texx - 1;
    if (RAY->side == 1 && RAY->raydiry < 0)
		texx = IMGW->width[nb] - texx - 1;
	d = j * 256 - F->axe_x * 128 + DRAW->lineheight * 128;
	texy = ((d * IMGW->height[nb])
	/ DRAW->lineheight) / 256;
	texy < 0 ? texy = 0 : 0;
	if (IMGW->height[nb] * IMGW->width[nb]
		> (texy * IMGW->width[nb] + texx))
		F->imgdata[(int)(j * F->axe_y + i)] = IMGW->text[nb]
		[(texy * IMGW->width[nb] + texx)];
}

void	ft_printwall(t_file *file, int j, int i)
{
	if (RAY->side == 0)
	{
		if (RAY->raydirx < 0)
			get_path_color(file, j, i, 0);
		else
			get_path_color(file, j, i, 1);
	}
	else
	{
		if (RAY->raydiry < 0)
			get_path_color(file, j, i, 3);
		else
			get_path_color(file, j, i, 2);
	}
}