/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 11:39:02 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 21:00:39 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void ft_draw_sprite_calc(t_file *file, int i, t_sprite *sprite)
{
	(void)F;
	i++;
	(void)sprite;
}

void	ft_draw_sprite(t_file *file, int i)
{
	t_sprite *beg_lst;
	t_sprite *tmp;

	beg_lst = F->SP;
	F->SP = NULL;
	while (beg_lst != NULL)
	{
		ft_draw_sprite_calc(F, i, beg_lst);
		tmp = beg_lst->next;
		free(beg_lst);
		beg_lst = tmp;
	}
}
