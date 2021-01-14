/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:40:56 by jacens            #+#    #+#             */
/*   Updated: 2021/01/14 15:21:10 by jacens           ###   ########lyon.fr   */
/*                                                                            */
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

int			ft_error_parse(t_file *file, int fd, char *line)
{
	if (fd > 0)
	{
		free(line);
		close(fd);
		return (1);
	}
	close(fd);
	ft_free_fil(F);
	ft_printf("Error\nBad file\n");
	return (0);
}
