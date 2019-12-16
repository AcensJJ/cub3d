/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:04:08 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 21:57:40 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		ft_rgbtoint(int red, int green, int blue)
{
	return((256* 256 * red) + (256 * green) + blue);
}

int		ft_snakeoil()
{
	//ft_printf("yo");
	return (1);
}

int 	ft_quit(t_file *file)
{
	mlx_destroy_window(F->mlx, F->win);
	exit(EXIT_SUCCESS);
}

void    ft_cube(t_file *file)
{
	int		bits;
	int		sizeline;
	int		end;

	F->mlx = mlx_init();
	F->win = mlx_new_window(F->mlx, F->axe_x, F->axe_y, "Have FUN");
	F->img = mlx_new_image(F->mlx, F->axe_x, F->axe_y);
	F->imgdata = (int *)mlx_get_data_addr(F->img, &bits, &sizeline, &end);
	F->imgdata[540 * 1920 + 960] =
	ft_rgbtoint(FC->c1,FC->c2,FC->c3);
	mlx_put_image_to_window(F->mlx, F->win, F->img, 0, 0);
	mlx_loop_hook(F->mlx, ft_snakeoil, (void *)F);
	/*mlx_hook(F->win, 2, 0, holdinput, (void *)F);
	  mlx_hook(F->win, 3, 0, releaseinput, (void *)F);*/
	mlx_hook(F->win, 17, 0, ft_quit, (void *)F);
	mlx_loop(F->mlx);
}

void 	ft_resochr(char *line, t_file *file)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	F->axe_x = ft_atoi((char *)line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	F->axe_y = ft_atoi((char *)line + i);
}

void	ft_colorchr(char *line, t_file *file, int p)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	p == 1 ? (FC->c1 = ft_atoi((char *)line + i)) :
	(FC->f1 = ft_atoi((char *)line + i));
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	p == 1 ? (FC->c2 = ft_atoi((char *)line + i)) :
	(FC->f2 = ft_atoi((char *)line + i));
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	p == 1? (FC->c3 = ft_atoi((char *)line + i)) :
	(FC->f3 = ft_atoi((char *)line + i));
}

void	ft_pathchr(char *line, t_file *file, int p)
{
	int i;
	int j;

	i = (p == 4 ? 1 : 2);
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] != ' ' && line[i])
		i++;
	p == 0 ? (FP->south = ft_substr(line, j, i)) : 0;
	p == 1 ? (FP->north = ft_substr(line, j, i)) : 0;
	p == 2 ? (FP->west = ft_substr(line, j, i)) : 0;
	p == 3 ? (FP->east = ft_substr(line, j, i)) : 0;
	p == 4 ? (FP->sprite = ft_substr(line, j, i)) : 0;
}

int		ft_first_line_map(char *line, int i, int nb, t_file *file)
{
	FM->height += 1;
	while (line[++i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			nb += 1;
			i++;
		}
		else if (line[i] != '\0')
		{
			free(line);
			ft_printf("Error\nMap1\n");
			return (0);
		}
	}
	free(line);
	return (nb);
}

int		ft_config_map_dest(int fd, char *line, t_file *file)
{
	int 	nb;
	int 	i;
	char	*dest;
	char	*join;
	char	*tmp;

	if (!((FM->width = ft_first_line_map(line, -1, 0, file)) &&
	(dest = ft_calloc(FM->width + 2, 1))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
	ft_memset(dest,	49, FM->width);
	dest[FM->width + 1] = '\n';
	while (get_next_line(fd, &line) >= 0)
	{
		FM->height += 1;
		i = 0;
		nb = 0;
		while (line[i] != '\0')
		{
			while (line[i] == ' ')
				i++;	
			if (line[i] == '2' || line[i] == '1' || line[i] == '0' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			{
				nb += 1;
				i++;
			}
			else if (line[i] != '\0')
			{
				free(dest);
				ft_printf("Error\nMap2\n");
				return (0);
			}
		}
		if (nb == 0)
			return (1);
		else if (nb != FM->width)
		{
			free(dest);
			ft_printf("Error\nMap3\n");
			return (0);
		}
		else
		{
			if (!(join = malloc(sizeof(char) * nb + 2)))
			{
				ft_printf("Error\nMalloc\n");
				return (0);
			}
			i = 0;
			nb = -1;
			while (line[i] != '\0')
			{
				while (line[i] == ' ')
					i++;
				join[++nb] = line[i];
				i++;
			}
			join[++nb] = '\n';
			join[++nb] = '\0';
			tmp = ft_strjoin(dest, join);
			free(dest);
			free(join);
			dest = tmp;
		}
		free(line);
	}
	return (1);
}

int		ft_parse_cube(char	*fichier, t_file *file)
{
	char 	*line;
	int		i;
	int 	fd;

	fd = open(fichier, O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (!ft_strncmp(&line[i], "R ", 2))
			ft_resochr(&line[i], F);
		else if (!ft_strncmp(&line[i], "C ", 2))
			ft_colorchr(&line[i], F, 1);
		else if (!ft_strncmp(&line[i], "F ", 2))
			ft_colorchr(&line[i], F, 0);
		else if (!ft_strncmp(&line[i], "SO ", 3) && !FP->south)
			ft_pathchr(&line[i], F, 0);
		else if (!ft_strncmp(&line[i], "NO ", 3) && !FP->north)
			ft_pathchr(&line[i], F, 1);
		else if (!ft_strncmp(&line[i], "WE ", 3) && !FP->west)
			ft_pathchr(&line[i], F, 2);
		else if (!ft_strncmp(&line[i], "EA ", 3) && !FP->east)			
			ft_pathchr(&line[i], F, 3);
		else if (!ft_strncmp(&line[i], "S ", 2) && !FP->sprite)
			ft_pathchr(&line[i], F, 4);
		else if (line[i] != '\0' && line[i] != '1')
		{
			free(line);
			ft_printf("Error\nParsing\n");
			return (0);
		}
		if (ft_strncmp(&line[i], "1", 1))
			free(line);
		else
			if (!ft_config_map_dest(fd, line, file))
				return (0);
	}
	return (1);
}

int    ft_init_color(t_file *file)
{
	if (!(FC = malloc(sizeof(t_color))))
	{
		ft_printf("Error\nMalloc\n");
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

int    ft_init_map(t_file *file)
{
	if (!(FM = malloc(sizeof(t_map))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
    FM->map = NULL;
	FM->width = 0;
	FM->height = 0;
	return (1);
}

int    ft_init_spawn(t_file *file)
{
	if (!(FS = malloc(sizeof(t_map))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
    FS->direction = 0;
    FS->col = -1;
    FS->row = -1;
	return (1);
}

int    ft_init_path(t_file *file)
{
	if (!(FP = malloc(sizeof(t_path))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
    FP->north = NULL;
    FP->south = NULL;
    FP->east = NULL;
    FP->west = NULL;
    FP->sprite = NULL;
	return (1);
}

void	ft_free_path(t_file *file)
{
	if (FP->north)
		free(FP->north);
	if (FP->south)
		free(FP->south);
	if (FP->east)
		free(FP->east);
	if (FP->west)
		free(FP->west);
	if (FP->sprite)
		free(FP->sprite);
}

void	ft_free_map(t_file *file)
{
	int i;

	i = -1;
	while (FM->map[++i])
		free(FM->map[i]);
	free(F->map);
	F->map = NULL;
}

void	ft_free_fil(t_file *file)
{
	ft_free_path(F);
	free(FP);
	free(FS);
	FP = NULL;
	ft_init_color(F);
	free(FC);
	FC = NULL;
	FM ? ft_free_map(F) : 0;
	free(F);
}

int		ft_verif_color_path(t_file *file)
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

int		ft_verif_map(void)
{
	return (1);
}

int 	main(int ac, char **av)
{
	t_file	*file;

	if (ac < 2)
	{
		ft_printf("Error\nPas tout les arguments\n");
		return (1);
	}
	if (!(F = malloc(sizeof(t_file))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
	if (!(ft_init_color(F) && ft_init_path(F) && ft_init_map(F) && ft_init_spawn(F)))
		return (0);
	if (!(ft_parse_cube(av[1], F)))
		return (0);
	if (!(ft_verif_color_path(F) && ft_verif_map()))
		return (0);
	ac = 0;
	ft_cube(F);
	return (0);
}
