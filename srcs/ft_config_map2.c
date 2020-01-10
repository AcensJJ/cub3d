/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_map2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:40:56 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 21:25:44 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_config_map2(int i, char *line, t_file *file)
{
	if (!(i = ft_set_line(F, line, 0, 0)))
	{
		free(line);
		return (0);
	}
	else if (i == 1)
	{
		free(line);
		return (1);
	}
	else if (!(ft_join_charmap(F, line, 0, i)))
	{
		free(line);
		return (0);
	}
	free(line);
	return (2);
}
