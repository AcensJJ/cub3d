/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 07:26:03 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		get_path_colorn(t_file *file, float x, float current, int last)
{
	float		test;
	int			y;

	test = x - (int)x + 0.5;
	if (test > 1)
		test--;
	test = (int)(test * IMGW->width[0]);
	y = (int)((current / last) * IMGW->width[0]);
	test += y * IMGW->width[0];
	return (IMGW->ntext[(long int)test]);
}

int		get_path_colors(t_file *file, float x, float current, int last)
{
	float	test;
	int		y;

	test = 1 - (x - (int)x + 0.5);
	if (test < 1)
		test++;
	test = (int)(test * IMGW->width[1]);
	y = (int)((current / last) * IMGW->width[1]);
	test += y * IMGW->width[1];
	return (IMGW->stext[(int)test]);
}

int		get_path_colore(t_file *file, float x, float current, int last)
{
	float	test;
	int		y;

	test = x - (int)x + 0.5;
	if (test > 1)
		test--;
	test = (int)(test * IMGW->width[2]);
	y = (int)((current / last) * IMGW->width[2]);
	test += y * IMGW->width[2];
	return (IMGW->etext[(int)test]);
}

int		get_path_colorw(t_file *file, float x, float current, int last)
{
	float	test;
	int		y;

	test = 1 - (x - (int)x + 0.5);
	if (test < 0)
		test++;
	test = (int)(test * IMGW->width[3]);
	y = (int)((current / last) * IMGW->width[3]);
	test += y * IMGW->width[3];
	return (IMGW->wtext[(int)test]);
}

void	ft_printwall(t_file *file, int j, int i)
{
	// if (RAY->side == 0)
	// {
	// 	if (RAY->raydirx < 0)
	// 		F->imgdata[(j * F->axe_y + i)] = get_path_colorn(file,
	// 			PLAYER->y, DRAW->start, DRAW->end);
	// 	else
	// 		F->imgdata[(j * F->axe_y + i)] = get_path_colors(file,
	// 			PLAYER->y, DRAW->start, DRAW->end);
	// }
	// else
	// {
	// 	if (RAY->raydiry < 0)
	// 		F->imgdata[(j * F->axe_y + i)] = get_path_colorw(file,
	// 			PLAYER->y, DRAW->start, DRAW->end);
	// 	else
	// 		F->imgdata[(j * F->axe_y + i)] = get_path_colore(F,
	// 			PLAYER->y, DRAW->start, DRAW->end);
	// }
	if (RAY->side == 0)
	{
		if (RAY->raydirx < 0)
			F->imgdata[(j * F->axe_y + i)] = get_path_colorn(file,
				PLAYER->y, DRAW->start, DRAW->end);
		else
			F->imgdata[(j * F->axe_y + i)] = 000000;
	}
	else
	{
		if (RAY->raydiry < 0)
			F->imgdata[(j * F->axe_y + i)] = 404040;
		else
			F->imgdata[(j * F->axe_y + i)] = 803050;
	}
}
