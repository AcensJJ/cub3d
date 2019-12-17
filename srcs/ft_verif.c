/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:27:46 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:02:50 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_verif_spawn_config(t_file *file, char line, int nb)
{
	if (FS->direction != 0 && FS->y != 0 && FS->x != 0)
	{
		ft_printf("Error\nSpawn\n");
		return (0);
	}
	else
	{
		FS->direction = line;
		line == 'N' ? FS->rotation = 0 : 0;
		line == 'E' ? FS->rotation = 90 : 0;
		line == 'S' ? FS->rotation = 180 : 0;
		line == 'W' ? FS->rotation = 270 : 0;
		FS->y = nb + 1;
		FS->x = ft_strcount_char(FM->mapchar, '\n');
	}
	return (1);
}

int			ft_verif_color_path(t_file *file)
{
	if (FC->f1 < 0 || FC->f1 > 255 || FC->f2 < 0
			|| FC->f2 > 255 || FC->f3 < 0 || FC->f3 > 255
			|| FC->c1 < 0 || FC->c1 > 255 || FC->c2 < 0
			|| FC->c2 > 255 || FC->c3 < 0 || FC->c3 > 255)
	{
		ft_printf("Error\nPas tout les colors\n");
		ft_free_fil(F);
		return (0);
	}
	if (!FP->north || !FP->south ||
			!FP->east || !FP->west || !FP->sprite)
	{
		ft_printf("Error\nPas tout les path\n");
		ft_free_fil(F);
		return (0);
	}
	if (FP->north[0] == '\0' || FP->south[0] == '\0' ||
			FP->east[0] == '\0' || FP->west[0] == '\0' ||
			FP->sprite[0] == '\0')
	{
		ft_printf("Error\nPas tout les path\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}

static int	ft_verif_map2(t_file *file)
{
	int i;

	i = -1;
	while (FM->map[++i])
	{
		if (!(FM->map[i][0] == '1' && FM->map[i][FM->width - 1] == '1'))
		{
			ft_free_fil(F);
			ft_printf("Error\nPas de contour de map\n");
			return (0);
		}
	}
	i = -1;
	while (FM->map[FM->height - 2][++i])
		if (FM->map[FM->height - 2][i] != '1')
		{
			ft_free_fil(F);
			ft_printf("Error\nPas de contour de map SOUTH\n");
			return (0);
		}
	return (1);
}

int			ft_verif_map(t_file *file)
{
	if (!FS->direction)
	{
		ft_free_fil(F);
		ft_printf("Error\nPas de Spawn Point\n");
		return (0);
	}
	if (FM->height < 3 || FM->width < 3)
	{
		ft_free_fil(F);
		ft_printf("Error\nMap trop petite\n");
		return (0);
	}
	if (!(ft_verif_map2(F)))
		return (0);
	return (1);
}

int			ft_start_verif(t_file *file, char **av)
{
	if (!(ft_init_color(F) && ft_init_path(F) && ft_init_map(F)
	&& ft_init_spawn(F)))
		return (0);
	if (!(ft_parse_cube(av[1], F)))
		return (0);
	if (!(FM->map = ft_split(FM->mapchar, '\n')))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc split\n");
		return (0);
	}
	if (!(ft_verif_color_path(F) && ft_verif_map(F)))
		return (0);
	return (1);
}
