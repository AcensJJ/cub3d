/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:27:46 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 01:58:27 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_verif_player_config(t_file *file, char line, int nb)
{
	if (PLAYER->direction != 0 && PLAYER->y != 0 && PLAYER->x != 0)
	{
		ft_printf("Error\nplayer\n");
		return (0);
	}
	else
	{
		PLAYER->direction = line;
		if (line == 'N' || line == 'S')
		{
			PLAYER->dirx = line == 'N' ? -1 : 1;
			PLAYER->plany = line == 'N' ? 0.66f : -0.66f;
			PLAYER->diry = 0;
			PLAYER->planx = 0;
		}
		if (line == 'W' || line == 'E')
		{
			PLAYER->diry = line == 'W' ? -1 : 1;
			PLAYER->planx = line == 'W' ? -0.66f : 0.66f;
			PLAYER->dirx = 0;
			PLAYER->plany = 0;
		}
		PLAYER->x = ft_strcount_char(MAP->mapchar, '\n') + 0.5;
		PLAYER->y = nb + 0.5;
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
	if (!PATH->north || !PATH->south ||
			!PATH->east || !PATH->west || !PATH->sprite)
	{
		ft_printf("Error\nPas tout les path\n");
		ft_free_fil(F);
		return (0);
	}
	if (PATH->north[0] == '\0' || PATH->south[0] == '\0' ||
			PATH->east[0] == '\0' || PATH->west[0] == '\0' ||
			PATH->sprite[0] == '\0')
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
	while (MAP->map[++i])
	{
		if (!(MAP->map[i][0] == '1' && MAP->map[i][MAP->width - 1] == '1'))
		{
			ft_free_fil(F);
			ft_printf("Error\nPas de contour de map\n");
			return (0);
		}
	}
	i = -1;
	while (MAP->map[MAP->height - 2][++i])
		if (MAP->map[MAP->height - 2][i] != '1')
		{
			ft_free_fil(F);
			ft_printf("Error\nPas de contour de map SOUTH\n");
			return (0);
		}
	return (1);
}

int			ft_verif_map(t_file *file)
{
	if (!PLAYER->direction)
	{
		ft_free_fil(F);
		ft_printf("Error\nPas de player Point\n");
		return (0);
	}
	if (MAP->height < 3 || MAP->width < 3)
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
	&& ft_init_player(F) && ft_init_ray(F) && ft_init_draw(F)))
		return (0);
	if (!(ft_parse_cube(av[1], F)))
		return (0);
	if (!(MAP->map = ft_split(MAP->mapchar, '\n')))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc split\n");
		return (0);
	}
	if (!(ft_verif_color_path(F) && ft_verif_map(F)))
		return (0);
	return (1);
}
