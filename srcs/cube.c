/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:04:08 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 14:52:01 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_cube(t_file *file)
{
	int		bits;
	int		sizeline;
	int		end;

	F->mlx = mlx_init();
	ft_readxpm(F, F->PA->north, 3);
	ft_readxpm(F, F->PA->south, 2);
	ft_readxpm(F, F->PA->east, 1);
	ft_readxpm(F, F->PA->west, 0);
	ft_readxpm(F, F->PA->sprite, 4);
	ft_readxpm(F, "./textures_hi/heart.xpm", 5);
	ft_readxpm(F, "./textures_hi/boo.xpm", 6);
	ft_readxpm(F, "./textures_hi/1upshroom.xpm", 7);
	F->win = mlx_new_window(F->mlx, F->axe_y, F->axe_x, "Have FUN");
	F->save ? ft_smile(F) : 0;
	F->img = mlx_new_image(F->mlx, F->axe_y, F->axe_x);
	F->imgdata = (int *)mlx_get_data_addr(F->img, &bits, &sizeline, &end);
	mlx_loop_hook(F->mlx, ft_snakeoil, (void *)F);
	mlx_hook(F->win, 2, 0, ft_appui, (void *)F);
	mlx_hook(F->win, 3, 0, ft_relache, (void *)F);
	mlx_hook(F->win, 17, 0, ft_quit, (void *)F);
	mlx_loop(F->mlx);
}

static int	ft_parse_cube2(t_file *file, char *line, int i)
{
	if (!ft_strncmp(&line[i], "C ", 2))
		ft_colorchr(&line[i], F, 1, 1);
	else if (!ft_strncmp(&line[i], "F ", 2))
		ft_colorchr(&line[i], F, 0, 1);
	else if (!ft_strncmp(&line[i], "SO ", 3) && !F->PA->south)
		ft_pathchr(&line[i], F, 0);
	else if (!ft_strncmp(&line[i], "NO ", 3) && !F->PA->north)
		ft_pathchr(&line[i], F, 1);
	else if (!ft_strncmp(&line[i], "WE ", 3) && !F->PA->west)
		ft_pathchr(&line[i], F, 2);
	else if (!ft_strncmp(&line[i], "EA ", 3) && !F->PA->east)
		ft_pathchr(&line[i], F, 3);
	else if (!ft_strncmp(&line[i], "S ", 2) && !F->PA->sprite)
		ft_pathchr(&line[i], F, 4);
	else if (line[i] != '\0' && line[i] != '1')
	{
		free(line);
		ft_printf("Error\nParsing\n");
		return (0);
	}
	return (1);
}

int			ft_parse_cube(char *fichier, t_file *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(fichier, O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (!ft_strncmp(&line[i], "R ", 2))
			ft_resochr(&line[i], F);
		else if (!(ft_parse_cube2(F, line, i)))
			return (0);
		if (ft_strncmp(&line[i], "1", 1))
			free(line);
		else if (!ft_config_map(fd, line, file))
			return (0);
	}
	return (ft_error_parse(F, fd, line));
}

int			main(int ac, char **av)
{
	t_file	*file;
	int		i;

	if (ac < 2 || (ac > 2 && ft_strcmp(&av[2][0], "-save")))
	{
		ft_printf("Error\nArguments\n");
		return (1);
	}
	i = ft_strlen(av[1]);
	if (ft_strcmp(&av[1][i - 4], ".cub"))
	{
		ft_printf("Error\nPas la bonne extension\n");
		return (1);
	}
	if (!(F = malloc(sizeof(t_file))))
	{
		ft_printf("Error\nMalloc file\n");
		return (0);
	}
	if (!(ft_start_verif(F, av)))
		return (1);
	ac == 3 ? F->save = 1 : 0;
	ft_cube(F);
	return (0);
}
