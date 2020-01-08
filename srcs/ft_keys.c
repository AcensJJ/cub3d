/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keys.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 05:44:25 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:14:38 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_quit(t_file *file)
{
	mlx_destroy_window(F->mlx, F->win);
	ft_free_fil(F);
	exit(EXIT_SUCCESS);
	return (0);
}

int			ft_appui(int i, t_file *file)
{
	if (i == 53)
		ft_quit(F);
	if (i == 123)
		F->K->mvleft = 1;
	if (i == 124)
		F->K->mvright = 1;
	if (i == 13)
		F->K->up = 1;
	if (i == 1)
		F->K->down = 1;
	if (i == 0)
		F->K->left = 1;
	if (i == 2)
		F->K->right = 1;
	return (1);
}

int			ft_relache(int i, t_file *file)
{
	if (i == 123)
		F->K->mvleft = 0;
	if (i == 124)
		F->K->mvright = 0;
	if (i == 13)
		F->K->up = 0;
	if (i == 1)
		F->K->down = 0;
	if (i == 0)
		F->K->left = 0;
	if (i == 2)
		F->K->right = 0;
	return (1);
}
