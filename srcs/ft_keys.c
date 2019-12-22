/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keys.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 05:44:25 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:01:35 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_quit(t_file *file)
{
	mlx_destroy_window(F->mlx, F->win);
	ft_free_fil(F);
	exit(EXIT_SUCCESS);
}

int			ft_appui(int i, t_file *file)
{
	if (i == 53)
		ft_quit(F);
	if (i == 123)
		KEY->mvleft = 1;
	if (i == 124)
		KEY->mvright = 1;
	if (i == 13)
		KEY->up = 1;
	if (i == 1)
		KEY->down = 1;
	if (i == 0)
		KEY->left = 1;
	if (i == 2)
		KEY->right = 1;
	return (1);
}

int			ft_relache(int i, t_file *file)
{
	if (i == 123)
		KEY->mvleft = 0;
	if (i == 124)
		KEY->mvright = 0;
	if (i == 13)
		KEY->up = 0;
	if (i == 1)
		KEY->down = 0;
	if (i == 0)
		KEY->left = 0;
	if (i == 2)
		KEY->right = 0;
	return (1);
}