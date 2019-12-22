/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <nepage-l@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 04:39:55 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:01:36 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void		ft_move(t_file *file)
{
    float olddirx;
	float oldplanex;
	float movespeed;
	float rotspeed;

	movespeed = 0.050;
	rotspeed = 0.025;
	if (KEY->up)
    {
    	if ((MAP->map[(int)(PLAYER->x + PLAYER->dirx * movespeed)][(int)(PLAYER->y)] != '1')
		&& (MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y + PLAYER->diry * movespeed)] != '1')) 
		{
			PLAYER->x += PLAYER->dirx * movespeed;
			PLAYER->y += PLAYER->diry * movespeed;
		}
    }
    if (KEY->down)
    {
    	if ((MAP->map[(int)(PLAYER->x - PLAYER->dirx * movespeed)][(int)(PLAYER->y)] != '1') &&
		(MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y - PLAYER->diry * movespeed)] != '1'))
		{
			PLAYER->x -= PLAYER->dirx * movespeed;
			PLAYER->y -= PLAYER->diry * movespeed;
		}
    }
	if (KEY->right)
    {
		if ((MAP->map[(int)(PLAYER->x + PLAYER->diry * movespeed)][(int)(PLAYER->y)] != '1') &&
		(MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y - PLAYER->dirx * movespeed)] != '1'))
		{
			PLAYER->x += PLAYER->diry * movespeed;
			PLAYER->y -= PLAYER->dirx * movespeed;
		}
    }
    if (KEY->left)
    {
		if ((MAP->map[(int)(PLAYER->x - PLAYER->diry * movespeed)][(int)(PLAYER->y)] != '1') &&
		(MAP->map[(int)(PLAYER->x)][(int)(PLAYER->y + PLAYER->dirx * movespeed)] != '1'))
		{
			PLAYER->x -= PLAYER->diry * movespeed;
			PLAYER->y += PLAYER->dirx * movespeed;
		}
    }
	olddirx = PLAYER->dirx;
	oldplanex = PLAYER->planx;
    if (KEY->mvright)
    {
      PLAYER->dirx = PLAYER->dirx * cos(-rotspeed) - PLAYER->diry * sin(-rotspeed);
      PLAYER->diry = olddirx * sin(-rotspeed) + PLAYER->diry * cos(-rotspeed);
      PLAYER->planx = PLAYER->planx * cos(-rotspeed) - PLAYER->plany * sin(-rotspeed);
      PLAYER->plany = oldplanex * sin(-rotspeed) + PLAYER->plany * cos(-rotspeed);
    }
	olddirx = PLAYER->dirx;
	oldplanex = PLAYER->planx;
    if (KEY->mvleft)
    {
      PLAYER->dirx = PLAYER->dirx * cos(rotspeed) - PLAYER->diry * sin(rotspeed);
      PLAYER->diry = olddirx * sin(rotspeed) + PLAYER->diry * cos(rotspeed);
      PLAYER->planx = PLAYER->planx * cos(rotspeed) - PLAYER->plany * sin(rotspeed);
      PLAYER->plany = oldplanex * sin(rotspeed) + PLAYER->plany * cos(rotspeed);
    }
}
