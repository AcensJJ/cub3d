/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 19:07:47 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_ray(t_file *file)
{
	if (RAY->raydirx < 0)
    {
    	RAY->stepx = -1;
        RAY->sidex = (PLAYER->x - RAY->mapx) * RAY->deltdistx;
    }
    else
    {
        RAY->stepx = 1;
        RAY->sidex = (RAY->mapx + 1.0 - PLAYER->x) * RAY->deltdistx;
    }
    if (RAY->raydiry < 0)
    {
    	RAY->stepy = -1;
        RAY->sidey = (PLAYER->y - RAY->mapy) * RAY->deltdisty;
    }
    else
    {
        RAY->stepy = 1;
        RAY->sidey = (RAY->mapy + 1.0 - PLAYER->y) * RAY->deltdisty;
    }
	while (RAY->hit == 0)
    {
   		if (RAY->sidex < RAY->sidey)
        {
          RAY->sidex += RAY->deltdistx;
          RAY->mapx += RAY->stepx;
          RAY->side = 0;
        }
        else
        {
          RAY->sidey += RAY->deltdisty;
          RAY->mapy += RAY->stepy;
          RAY->side = 1;
        }
        (MAP->map[RAY->mapy][RAY->mapx] > 0) ? RAY->hit = 1 : 0;
      } 

}

void	raycast(t_file *file)
{
	int i;
	float angle;

	i = 0;
	while (i < F->axe_x)
	{
		RAY->hit = 0;
		PLAYER->camx = 2 * i / F->axe_x - 1;
		RAY->raydirx = PLAYER->dirx + PLAYER->planx * PLAYER->camx;
		RAY->raydiry = PLAYER->diry + PLAYER->plany * PLAYER->camx;
		RAY->deltdistx = abs(1 / RAY->raydirx);
		RAY->deltdisty = abs(1 / RAY->raydiry);
		RAY->mapx = (int)PLAYER->x;
		RAY->mapy = (int)PLAYER->y;
		ft_ray(file);
		i++;
	}
}

int		ft_snakeoil(t_file *file)
{
	raycast(F);
	return (1);
}