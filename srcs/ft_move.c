/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 04:39:55 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 12:20:35 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_move3(t_file *file)
{
	float olddirx;
	float oldplanex;

	olddirx = F->PL->dirx;
	oldplanex = F->PL->planx;
	if (F->K->mvright)
	{
		F->PL->dirx = F->PL->dirx * cos(-0.050) -
		F->PL->diry * sin(-0.050);
		F->PL->diry = olddirx * sin(-0.050) + F->PL->diry * cos(-0.050);
		F->PL->planx = F->PL->planx * cos(-0.050) -
		F->PL->plany * sin(-0.050);
		F->PL->plany = oldplanex * sin(-0.050) + F->PL->plany * cos(-0.050);
	}
	olddirx = F->PL->dirx;
	oldplanex = F->PL->planx;
	if (F->K->mvleft)
	{
		F->PL->dirx = F->PL->dirx * cos(0.050) -
		F->PL->diry * sin(0.050);
		F->PL->diry = olddirx * sin(0.050) + F->PL->diry * cos(0.050);
		F->PL->planx = F->PL->planx * cos(0.050) -
		F->PL->plany * sin(0.050);
		F->PL->plany = oldplanex * sin(0.050) + F->PL->plany * cos(0.050);
	}
}

static void	ft_move2(t_file *file)
{
	if (F->K->right)
	{
		if (F->M->map[(int)(F->PL->x + F->PL->diry * 0.05)]
			[(int)(F->PL->y)] != '1')
			F->PL->x += F->PL->diry * 0.05;
		if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y -
			F->PL->dirx * 0.05)] != '1')
			F->PL->y -= F->PL->dirx * 0.05;
	}
	if (F->K->left)
	{
		if (F->M->map[(int)(F->PL->x - F->PL->diry * 0.05)]
			[(int)(F->PL->y)] != '1')
			F->PL->x -= F->PL->diry * 0.05;
		if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y +
			F->PL->dirx * 0.05)] != '1')
			F->PL->y += F->PL->dirx * 0.05;
	}
	ft_move3(F);
}

void		ft_move(t_file *file)
{
	if (F->K->up)
	{
		if (F->M->map[(int)(F->PL->x + F->PL->dirx * 0.05)]
			[(int)(F->PL->y)] != '1')
			F->PL->x += F->PL->dirx * 0.05;
		if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y +
			F->PL->diry * 0.05)] != '1')
			F->PL->y += F->PL->diry * 0.05;
	}
	if (F->K->down)
	{
		if (F->M->map[(int)(F->PL->x - F->PL->dirx * 0.05)]
			[(int)(F->PL->y)] != '1')
			F->PL->x -= F->PL->dirx * 0.05;
		if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y -
			F->PL->diry * 0.05)] != '1')
			F->PL->y -= F->PL->diry * 0.05;
	}
	ft_move2(F);
}
