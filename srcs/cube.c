/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:04:08 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 18:32:31 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_quit(t_file *file)
{
	mlx_destroy_window(F->mlx, F->win);
	exit(EXIT_SUCCESS);
}

void		ft_cube(t_file *file)
{
	int		bits;
	int		sizeline;
	int		end;

	F->mlx = mlx_init();
	F->win = mlx_new_window(F->mlx, F->axe_x, F->axe_y, "Have FUN");
	F->img = mlx_new_image(F->mlx, F->axe_x, F->axe_y);
	F->imgdata = (int *)mlx_get_data_addr(F->img, &bits, &sizeline, &end);
	F->imgdata[540 * 1920 + 960] = ft_rgbtoint(FC->c1, FC->c2, FC->c3);
	mlx_put_image_to_window(F->mlx, F->win, F->img, 0, 0);
	mlx_loop_hook(F->mlx, ft_snakeoil, (void *)F);
	/*mlx_hook(F->win, 2, 0, holdinput, (void *)F);
	  mlx_hook(F->win, 3, 0, releaseinput, (void *)F);*/
	mlx_hook(F->win, 17, 0, ft_quit, (void *)F);
	mlx_loop(F->mlx);
}

static int	ft_parse_cube2(t_file *file, char *line, int i)
{
	if (!ft_strncmp(&line[i], "C ", 2))
		ft_colorchr(&line[i], F, 1);
	else if (!ft_strncmp(&line[i], "F ", 2))
		ft_colorchr(&line[i], F, 0);
	else if (!ft_strncmp(&line[i], "SO ", 3) && !PATH->south)
		ft_pathchr(&line[i], F, 0);
	else if (!ft_strncmp(&line[i], "NO ", 3) && !PATH->north)
		ft_pathchr(&line[i], F, 1);
	else if (!ft_strncmp(&line[i], "WE ", 3) && !PATH->west)
		ft_pathchr(&line[i], F, 2);
	else if (!ft_strncmp(&line[i], "EA ", 3) && !PATH->east)
		ft_pathchr(&line[i], F, 3);
	else if (!ft_strncmp(&line[i], "S ", 2) && !PATH->sprite)
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
	return (1);
}

int			main(int ac, char **av)
{
	t_file	*file;

	if (ac < 2)
	{
		ft_printf("Error\nPas tout les arguments\n");
		return (1);
	}
	if (!(F = malloc(sizeof(t_file))))
	{
		ft_printf("Error\nMalloc file\n");
		return (0);
	}
	if (!(ft_start_verif(F, av)))
		return (1);
	ft_cube(F);
	return (0);
}
