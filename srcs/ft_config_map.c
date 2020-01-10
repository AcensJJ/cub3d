/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:40:56 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 19:23:25 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static int	ft_join_char_more(t_file *file, char *join, int nb)
{
	char	*tmp;

	join[++nb] = '\n';
	join[++nb] = '\0';
	tmp = ft_strjoin(F->M->mapchar, join);
	free(F->M->mapchar);
	free(join);
	F->M->mapchar = tmp;
	return (1);
}

int			ft_join_charmap(t_file *file, char *line, int i, int nb)
{
	char	*join;

	if (!(join = malloc(sizeof(char) * nb + 1)))
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
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
		|| line[i] == 'W')
			if (!(ft_verif_player_config(F, line[i], (nb + 1))))
				return (0);
		line[i] == '\0' ? 0 : (join[++nb] = line[i]);
		line[i] == '\0' ? 0 : i++;
	}
	return (ft_join_char_more(F, join, nb));
}

int			ft_set_line(t_file *file, char *line, int nb, int i)
{
	F->M->height += 1;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '2' || line[i] == '1' || line[i] == '0' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '3'
		|| line[i] == '4' || line[i] == '5')
		{
			nb += 1;
			i++;
		}
		else if (line[i] != '\0')
		{
			ft_printf("Error\nMap mauvais carractere\n");
			return (0);
		}
	}
	if (nb == 0)
		return (1);
	else if (nb == F->M->width)
		return (2);
	printf("nb = %i, witdh = %i\n", i, F->M->width);
	ft_printf("Error\nMap\n");
	return (0);
}

int			ft_first_line_map(char *line, int i, int nb, t_file *file)
{
	F->M->height += 1;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			nb++;
			i++;
		}
		else if (line[i] != '\0')
		{
			free(line);
			ft_printf("Error\nMap 1\n");
			return (0);
		}
	}
	free(line);
	return (nb);
}

int			ft_config_map(int fd, char *line, t_file *file)
{
	int i;

	if (!((F->M->width = ft_first_line_map(line, 0, 0, file)) &&
		(F->M->mapchar = ft_calloc(F->M->width + 2, 1))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
	ft_memset(F->M->mapchar, '1', F->M->width + 1);
	F->M->mapchar[F->M->width] = '\n';
	while (get_next_line(fd, &line) >= 0)
	{
		if (!(i = ft_set_line(F, line, 0, 0)))
			return (0);
		else if (i == 1)
			return (1);
		else if (!(ft_join_charmap(F, line, 0, i)))
			return (0);
		free(line);
	}
	return (1);
}
