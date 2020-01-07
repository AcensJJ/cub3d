/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:50:59 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 15:24:02 by jacens      ###    #+. /#+    ###.fr     */
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
	IMGW->img[0] ? mlx_destroy_image(F->mlx, IMGW->img[0]) : 0;
	IMGW->img[1] ? mlx_destroy_image(F->mlx, IMGW->img[1]) : 0;
	IMGW->img[2] ? mlx_destroy_image(F->mlx, IMGW->img[2]) : 0;
	IMGW->img[3] ? mlx_destroy_image(F->mlx, IMGW->img[3]) : 0;
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
