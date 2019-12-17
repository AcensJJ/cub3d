/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_struct.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:38:22 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 19:26:20 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_resochr(char *line, t_file *file)
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
	p == 1 ? (FC->c3 = ft_atoi((char *)line + i)) :
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
