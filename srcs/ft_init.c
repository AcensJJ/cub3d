/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:51:04 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 16:36:08 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		ft_init_color(t_file *file)
{
	if (!(FC = malloc(sizeof(t_color))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc color\n");
		return (0);
	}
	FC->f1 = -1;
	FC->f2 = -1;
	FC->f3 = -1;
	FC->c1 = -1;
	FC->c2 = -1;
	FC->c3 = -1;
	return (1);
}

int		ft_init_map(t_file *file)
{
	if (!(FM = malloc(sizeof(t_map))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc map\n");
		return (0);
	}
	FM->map = NULL;
	FM->width = 0;
	FM->height = 0;
	FM->mapchar = NULL;
	return (1);
}

int		ft_init_spawn(t_file *file)
{
	if (!(FS = malloc(sizeof(t_map))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc spawn\n");
		return (0);
	}
	FS->direction = 0;
	FS->y = -1;
	FS->x = -1;
	return (1);
}

int		ft_init_path(t_file *file)
{
	if (!(FP = malloc(sizeof(t_path))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc init\n");
		return (0);
	}
	FP->north = NULL;
	FP->south = NULL;
	FP->east = NULL;
	FP->west = NULL;
	FP->sprite = NULL;
	return (1);
}
