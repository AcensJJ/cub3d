/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 23:16:08 by jacens      ###    #+. /#+    ###.fr     */
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

	sidetmp = (int)(RAY->sidey * 1000000);
	raytmp = (int)(RAY->raydiry * 1000000);
	sidetmp /= 1000000;
	raytmp /= 1000000;
	y = sidetmp * raytmp + PLAYER->y;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->ntext[(int)(IMGW->width[0] * percent + (int)y)]);
}

int		get_path_colors(t_file *file, float j)
{
	float	max;
	float	percent;
	float	y;
	float 	sidetmp;
	float 	raytmp;

	sidetmp = (int)(RAY->sidey * 10000);
	raytmp = (int)(RAY->raydiry * 10000);
	sidetmp /= 10000;
	raytmp /= 10000;
	y = sidetmp * raytmp + PLAYER->y;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->stext[(int)(IMGW->width[1] * percent + (int)y)]);
}

int		get_path_colore(t_file *file, float j)
{
	float	max;
	float	percent;
	float	x;
	float 	sidetmp;
	float 	raytmp;

	sidetmp = (int)(RAY->sidex * 10000);
	raytmp = (int)(RAY->raydirx * 10000);
	sidetmp /= 10000;
	raytmp /= 10000;
	x = sidetmp * raytmp + PLAYER->x;
	max = (DRAW->end + DRAW->startneg) - (DRAW->start - DRAW->endneg);
	percent = j -  DRAW->start + DRAW->startneg;
	percent /= max;
	return (IMGW->etext[(int)(IMGW->width[2] * percent + (int)x)]);
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
	return (IMGW->wtext[(int)(IMGW->width[2] * percent + (int)x)]);
}

void	ft_printwall(t_file *file, float j, float i)
{
	if (RAY->side == 0)
	{
		if (RAY->raydirx < 0)
			F->imgdata[(int)(j * F->axe_y + i)] = get_path_colorn(file, j);
		else
		{
			F->imgdata[(int)(j * F->axe_y + i)] = get_path_colors(file, j);
		}
	}
	else
	{
		if (RAY->raydiry < 0)
			F->imgdata[(int)(j * F->axe_y + i)] = get_path_colorw(file, j);
		else
			F->imgdata[(int)(j * F->axe_y + i)] = get_path_colore(file, j);
	}
}
