/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 22:10:36 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		get_path_colorn(t_file *file, float j)
{
	float	max;
	float	percent;
	float	y;
	float 	sidetmp;
	float 	raytmp;

	sidetmp = (int)(RAY->sidey * 1000);
	raytmp = (int)(RAY->raydiry * 1000);
	sidetmp /= 1000;
	raytmp /= 1000;
	y = sidetmp * raytmp + PLAYER->y;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->ntext[(int)(IMGW->height[0] * percent + y)]);
}

int		get_path_colors(t_file *file, float j)
{
	float	max;
	float	percent;
	float	y;
	float 	sidetmp;
	float 	raytmp;

	sidetmp = (int)(RAY->sidey * 1000);
	raytmp = (int)(RAY->raydiry * 1000);
	sidetmp /= 1000;
	raytmp /= 1000;
	y = sidetmp * raytmp + PLAYER->y;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->stext[(int)(IMGW->width[1] * percent + y)]);
}

int		get_path_colore(t_file *file, float j)
{
	float	max;
	float	percent;
	float	x;
	float 	sidetmp;
	float 	raytmp;

	sidetmp = (int)(RAY->sidex * 1000);
	raytmp = (int)(RAY->raydirx * 1000);
	sidetmp /= 1000;
	raytmp /= 1000;
	x = sidetmp * raytmp + PLAYER->x;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->etext[(int)(IMGW->width[2] * percent + x)]);
}

int		get_path_colorw(t_file *file, float j)
{
	float	max;
	float	percent;
	float	x;
	float 	sidetmp;
	float 	raytmp;

	sidetmp = (int)(RAY->sidex * 1000);
	raytmp = (int)(RAY->raydirx * 1000);
	sidetmp /= 1000;
	raytmp /= 1000;
	x = sidetmp * raytmp + PLAYER->x;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->wtext[(int)(IMGW->width[2] * percent + x)]);
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
			F->imgdata[(j * F->axe_y + i)] = get_path_colorn(file, j);
		else
		{
			F->imgdata[(j * F->axe_y + i)] = get_path_colors(file, j);
		}
	}
	else
	{
		if (RAY->raydiry < 0)
			F->imgdata[(j * F->axe_y + i)] = get_path_colorw(file, j);
		else
			F->imgdata[(j * F->axe_y + i)] = get_path_colore(file, j);
	}
}
