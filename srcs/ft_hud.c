/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hud.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 09:27:23 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:49:51 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_draw_hud(t_file *file, int i)
{
	F->HD->color = 0;
	F->HD->hmin = F->axe_x * 0.850;
	F->HD->hmax = F->axe_x * 0.950;
	F->HD->wmin = F->axe_y * 0.850;
	F->HD->wmax = F->axe_y * 0.950;
	F->HD->w = i - F->HD->wmin;
	F->HD->h = F->HD->hmin - 1;
	F->HD->percentw = (F->HD->w / (float)(F->HD->wmax - F->HD->wmin));
	while (++F->HD->h < F->HD->hmax)
	{
		F->HD->percenth = (F->HD->h - F->HD->hmin) /
		(float)(F->HD->hmax - F->HD->hmin);
		F->HD->color = F->IW->text[5][(int)(F->IW->width[5] * F->HD->percentw)
		+ F->IW->width[5] * (int)(F->IW->height[5] * F->HD->percenth)];
		(F->HD->color > 0) ? F->imgdata[(int)F->HD->h * F->axe_y + i] =
		10559749 : 0;
	}
}
