/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:50:59 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 13:59:49 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_free_path(t_file *file)
{
	if (FP->north)
		free(FP->north);
	if (FP->south)
		free(FP->south);
	if (FP->east)
		free(FP->east);
	if (FP->west)
		free(FP->west);
	if (FP->sprite)
		free(FP->sprite);
	free(FP);
}

void	ft_free_map(t_file *file)
{
	int i;

	i = -1;
	free(FM->mapchar);
	if (FM->map)
	{
		while (FM->map[++i])
			free(FM->map[i]);
	}
	free(FM);
}

void	ft_free_fil(t_file *file)
{
	FP ? ft_free_path(F) : 0;
	FS ? free(FS) : 0;
	FC ? free(FC) : 0;
	FM ? ft_free_map(F) : 0;
	free(F);
}
