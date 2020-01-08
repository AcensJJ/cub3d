/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_struct.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:38:22 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:18:04 by jacens      ###    #+. /#+    ###.fr     */
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
	F->axe_y = ft_isdigit(line[i]) ? (int)(ft_atoi((char *)line + i)) : -1;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	F->axe_x = ft_isdigit(line[i]) ? (int)(ft_atoi((char *)line + i)) : -1;
}

void	ft_colorchr(char *line, t_file *file, int p, int i)
{
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		p == 1 ? (F->FC->c1 = ft_atoi((char *)line + i)) :
		(F->FC->f1 = ft_atoi((char *)line + i));
	}
	while (ft_isdigit(line[i]))
		i++;
	line[i] == ',' ? i++ : 0;
	if (ft_isdigit(line[i]))
	{
		p == 1 ? (F->FC->c2 = ft_atoi((char *)line + i)) :
		(F->FC->f2 = ft_atoi((char *)line + i));
	}
	while (ft_isdigit(line[i]))
		i++;
	line[i] == ',' ? i++ : 0;
	if (ft_isdigit(line[i]))
	{
		p == 1 ? (F->FC->c3 = ft_atoi((char *)line + i)) :
		(F->FC->f3 = ft_atoi((char *)line + i));
	}
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
	p == 0 ? (F->PA->south = ft_substr(line, j, i)) : 0;
	p == 1 ? (F->PA->north = ft_substr(line, j, i)) : 0;
	p == 2 ? (F->PA->west = ft_substr(line, j, i)) : 0;
	p == 3 ? (F->PA->east = ft_substr(line, j, i)) : 0;
	p == 4 ? (F->PA->sprite = ft_substr(line, j, i)) : 0;
}
