/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:50:59 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 04:44:44 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_free_path(t_file *file)
{
	if (PATH->north)
		free(PATH->north);
	if (PATH->south)
		free(PATH->south);
	if (PATH->east)
		free(PATH->east);
	if (PATH->west)
		free(PATH->west);
	if (PATH->sprite)
		free(PATH->sprite);
	free(PATH);
}

static void	ft_free_map(t_file *file)
{
	int i;

	i = -1;
	free(MAP->mapchar);
	if (MAP->map)
	{
		while (MAP->map[++i])
			free(MAP->map[i]);
	}
	free(MAP);
}

static void	ft_destroy(t_file *file)
{
	IMGW->ntext ? 1 : 0;
	// IMGW->ntext ? mlx_destroy_image(F->mlx, IMGW->ntext) : 0;
	// IMGW->stext ? mlx_destroy_image(F->mlx, IMGW->stext) : 0;
	// IMGW->etext ? mlx_destroy_image(F->mlx, IMGW->etext) : 0;
	// IMGW->wtext ? mlx_destroy_image(F->mlx, IMGW->wtext) : 0;
}

void		ft_free_fil(t_file *file)
{
	PATH ? ft_free_path(F) : 0;
	RAY ? free(RAY) : 0;
	PLAYER ? free(PLAYER) : 0;
	DRAW ? free(DRAW) : 0;
	KEY ? free(KEY) : 0;
	FC ? free(FC) : 0;
	MAP ? ft_free_map(F) : 0;
	SPRITE ? free(SPRITE) : 0;
	IMGW ? ft_destroy(F) : 0;
	IMGW ? free(IMGW) : 0;
	free(F);
}
