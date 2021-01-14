/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:07:58 by jacens            #+#    #+#             */
/*   Updated: 2021/01/14 15:21:10 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void		ft_readxpm(t_file *file, char *str, int n)
{
	int		bits;
	int		sl;
	int		endian;

	if ((F->IW->img[n] = mlx_xpm_file_to_image(F->mlx, str, &F->IW->width[n],
	&F->IW->height[n])))
		F->IW->text[n] = (int *)mlx_get_data_addr(F->IW->img[n],
		&bits, &sl, &endian);
}

int			ft_rgbtoint(int red, int green, int blue)
{
	return ((256 * 256 * red) + (256 * green) + blue);
}
