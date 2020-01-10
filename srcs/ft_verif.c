/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:27:46 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 20:01:32 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_verif_player_config(t_file *file, char line, int nb)
{
	if (F->PL->direction != 0 && F->PL->y != 0 && F->PL->x != 0)
	{
		ft_printf("Error\nplayer\n");
		return (0);
	}
	F->PL->direction = line;
	if (line == 'N' || line == 'S')
	{
		F->PL->dirx = line == 'N' ? -1 : 1;
		F->PL->plany = line == 'N' ? 0.66f : -0.66f;
		F->PL->diry = 0;
		F->PL->planx = 0;
	}
	if (line == 'W' || line == 'E')
	{
		F->PL->diry = line == 'W' ? -1 : 1;
		F->PL->planx = line == 'W' ? -0.66f : 0.66f;
		F->PL->dirx = 0;
		F->PL->plany = 0;
	}
	F->PL->x = ft_strcount_char(F->M->mapchar, '\n') + 0.5;
	F->PL->y = nb + 0.5;
	return (1);
}

int			ft_verif_color_path(t_file *file)
{
	if (F->FC->f1 < 0 || F->FC->f1 > 255 || F->FC->f2 < 0
	|| F->FC->f2 > 255 || F->FC->f3 < 0 || F->FC->f3 > 255
	|| F->FC->c1 < 0 || F->FC->c1 > 255 || F->FC->c2 < 0
	|| F->FC->c2 > 255 || F->FC->c3 < 0 || F->FC->c3 > 255)
	{
		ft_printf("Error\nPas tout les colors\n");
		ft_free_fil(F);
		return (0);
	}
	if (!F->PA->north || !F->PA->south ||
			!F->PA->east || !F->PA->west || !F->PA->sprite)
	{
		ft_printf("Error\nPas tout les path\n");
		ft_free_fil(F);
		return (0);
	}
	if (F->PA->north[0] == '\0' || F->PA->south[0] == '\0' ||
			F->PA->east[0] == '\0' || F->PA->west[0] == '\0' ||
			F->PA->sprite[0] == '\0')
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
	while (F->M->map[++i])
	{
		if (!(F->M->map[i][0] == '1' && F->M->map[i][F->M->width - 1] == '1'))
		{
			ft_free_fil(F);
			ft_printf("Error\nPas de contour de map\n");
			return (0);
		}
	}
	i = -1;
	while (F->M->map[F->M->height - 2][++i])
		if (F->M->map[F->M->height - 2][i] != '1')
		{
			ft_free_fil(F);
			ft_printf("Error\nPas de contour de map SOUTH\n");
			return (0);
		}
	return (1);
}

int			ft_verif_map(t_file *file)
{
	if (!F->PL->direction)
	{
		ft_free_fil(F);
		ft_printf("Error\nPas de F->PLPoint\n");
		return (0);
	}
	if (F->M->height < 3 || F->M->width < 3)
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
	F->SP = NULL;
	F->save = 0;
	if (!(ft_init_color(F) && ft_init_path(F) && ft_init_map(F)
	&& ft_init_player(F) && ft_init_ray(F) && ft_init_key(F)
	&& ft_init_draw(F) && ft_init_draw_sprite(F) && ft_init_imgw(F)
	&& ft_init_hubdraw(F) && ft_init_audio(F)))
		return (0);
	if (!(ft_parse_cube(av[1], F)))
		return (0);
	if (!(F->M->map = ft_split(F->M->mapchar, '\n')))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc split\n");
		return (0);
	}
	if (!(ft_verif_color_path(F) && ft_verif_map(F) && ft_verif_reso(F)
	&& ft_verif_path_img(F)))
		return (0);
	return (1);
}
