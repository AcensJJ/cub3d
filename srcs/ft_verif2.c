/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:27:46 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 04:44:32 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_verif_reso(t_file *file)
{
	if ((F->axe_x < 1 || F->axe_x > 2880) ||
	(F->axe_y < 1 || F->axe_y > 5120))
	{
		ft_printf("Error\nMauvaise résolution\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}

int			ft_verif_path_img(t_file *file)
{
	if (open(PATH->east, O_RDONLY) < 0 || open(PATH->north, O_RDONLY) < 0 ||
	open(PATH->west, O_RDONLY) < 0 || open(PATH->south, O_RDONLY) < 0)
	{
		ft_printf("Error\nMauvais path\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}
