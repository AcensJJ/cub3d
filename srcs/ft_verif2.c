/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:27:46 by jacens            #+#    #+#             */
/*   Updated: 2021/01/14 15:21:10 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_verif_reso(t_file *file)
{
	if ((F->axe_x < 1 || F->axe_x > (2880 / 2)) ||
		(F->axe_y < 1 || F->axe_y > (5120 / 2)))
	{
		ft_printf("Error\nMauvaise résolution\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}

int			ft_verif_path_img(t_file *file)
{
	if (open(F->PA->east, O_RDONLY) < 0 || open(F->PA->north, O_RDONLY) < 0 ||
		open(F->PA->west, O_RDONLY) < 0 || open(F->PA->south, O_RDONLY) < 0 ||
		open(F->PA->sprite, O_RDONLY) < 0
		|| open("./textures_hi/heart.xpm", O_RDONLY) < 0
		|| open("./textures_hi/barrel_wood.xpm", O_RDONLY) < 0)
	{
		ft_printf("Error\nMauvais path\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}
