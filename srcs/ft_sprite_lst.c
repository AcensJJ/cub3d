/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sprite_lst.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 10:38:27 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:32:02 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static t_sprite		*ft_sprit_add_lstlast(t_file *file)
{
	t_sprite	*beg_lst;

	if (F->SP == NULL)
		return (NULL);
	beg_lst = F->SP;
	while (beg_lst->next != NULL)
		beg_lst = beg_lst->next;
	return (beg_lst);
}

static int			ft_sprit_add_lst(t_file *file, t_sprite *sprite)
{
	t_sprite *beg_lst;

	if (F == NULL || sprite == NULL)
		return (-1);
	if (F->SP == NULL)
		F->SP = sprite;
	else
	{
		beg_lst = ft_sprit_add_lstlast(F);
		beg_lst->next = sprite;
	}
	return (0);
}

void				ft_sprit_verif_lst(t_file *file)
{
	float dist;

	if (F->R->side == 0)
		dist =
			(F->R->mapx - F->PL->x + (1 - F->R->stepx) / 2) / F->R->raydirx;
	else
		dist =
			(F->R->mapy - F->PL->y + (1 - F->R->stepy) / 2) / F->R->raydiry;
	if (ft_sprit_add_lst(F, ft_init_sprite(F, F->R->mapx, F->R->mapy, dist)))
	{
		ft_printf("Error\nCreate sprite\n");
		ft_quit(F);
	}
}
