/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 11:39:02 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 16:10:49 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_draw_sprite(t_file *file, double *buffer)
{
	t_sprite *beg_lst;

	beg_lst = F->SP;
	(void)buffer;
	ft_free_sprite(F);
}
