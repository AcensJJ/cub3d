/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 04:39:55 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:46:30 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_move3(t_file *file)
{
	float olddirx;
	float oldplanex;

	olddirx = PLAYER->dirx;
	oldplanex = PLAYER->planx;
	if (KEY->mvright)
	{
		PLAYER->dirx = PLAYER->dirx * cos(-0.050) -
		PLAYER->diry * sin(-0.050);
		PLAYER->diry = olddirx * sin(-0.050) + PLAYER->diry * cos(-0.050);
		PLAYER->planx = PLAYER->planx * cos(-0.050) -
		PLAYER->plany * sin(-0.050);
		PLAYER->plany = oldplanex * sin(-0.050) + PLAYER->plany * cos(-0.050);
	}
	olddirx = PLAYER->dirx;
	oldplanex = PLAYER->planx;
	if (KEY->mvleft)
	{
		PLAYER->dirx = PLAYER->dirx * cos(0.050) -
		PLAYER->diry * sin(0.050);
		PLAYER->diry = olddirx * sin(0.050) + PLAYER->diry * cos(0.050);
		PLAYER->planx = PLAYER->planx * cos(0.050) -
		PLAYER->plany * sin(0.050);
		PLAYER->plany = oldplanex * sin(0.050) + PLAYER->plany * cos(0.050);
	}
}

static void	ft_move2(t_file *file)
{
	if (KEY->right)
	{
		if ((MAP->map[(int)(PLAYER->x + PLAYER->diry * 0.050)]
					[(int)(PLAYER->y)] != '1') &&
				(MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y -
				PLAYER->dirx * 0.050)] != '1'))
		{
			PLAYER->x += PLAYER->diry * 0.050;
			PLAYER->y -= PLAYER->dirx * 0.050;
		}
	}
	if (KEY->left)
	{
		if ((MAP->map[(int)(PLAYER->x - PLAYER->diry * 0.050)]
					[(int)(PLAYER->y)] != '1') &&
				(MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y +
				PLAYER->dirx * 0.050)] != '1'))
		{
			PLAYER->x -= PLAYER->diry * 0.050;
			PLAYER->y += PLAYER->dirx * 0.050;
		}
	}
	ft_move3(F);
}

void		ft_move(t_file *file)
{
	if (KEY->up)
	{
		if ((MAP->map[(int)(PLAYER->x + PLAYER->dirx * 0.050)]
					[(int)(PLAYER->y)] != '1')
				&& (MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y +
						PLAYER->diry * 0.050)] != '1'))
		{
			PLAYER->x += PLAYER->dirx * 0.050;
			PLAYER->y += PLAYER->diry * 0.050;
		}
	}
	if (KEY->down)
	{
		if ((MAP->map[(int)(PLAYER->x - PLAYER->dirx * 0.050)]
					[(int)(PLAYER->y)] != '1') &&
				(MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y -
				PLAYER->diry * 0.050)] != '1'))
		{
			PLAYER->x -= PLAYER->dirx * 0.050;
			PLAYER->y -= PLAYER->diry * 0.050;
		}
	}
	ft_move2(F);
}
