/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 11:39:02 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 15:25:34 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_draw_sprite_it(t_file *file, int i)
{
	// //calculate width of the sprite
	// int spriteWidth = abs( int (h / (transformY))) / uDiv;
	// int drawStartX = -spriteWidth / 2 + spriteScreenX;
	// if(drawStartX < 0) drawStartX = 0;
	// int drawEndX = spriteWidth / 2 + spriteScreenX;
	// if(drawEndX >= w) drawEndX = w - 1;
	// //loop through every vertical stripe of the sprite on screen
	// for(int stripe = drawStartX; stripe < drawEndX; stripe++)
	// {
	// 	int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
	// 	//the conditions in the if are:
	// 	//1) it's in front of camera plane so you don't see things behind you
	// 	//2) it's on the screen (left)
	// 	//3) it's on the screen (right)
	// 	//4) ZBuffer, with perpendicular distance
	// 	if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
	// 	for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
	// 	{
	// 		int d = (y-vMoveScreen) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
	// 		int texY = ((d * texHeight) / spriteHeight) / 256;
	// 		Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
	// 		if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
	// 	}
	// }
	(void)F;
	(void)i;
}

static void	ft_draw_sprite_calc(t_file *file, int i, t_sprite *sprite)
{
	F->DP->inverse = 1 / (F->PL->planx * F->PL->diry - F->PL->dirx * F->PL->plany);
	// F->DP->x = F->DP->inverse * (F->PL->diry * SP->x - F->PL->dirx * SP->y);
	// F->DP->y = F->DP->inverse * (-F->PL->plany * SP->x + F->PL->planx * SP->y);
	// F->DP->screen = (int)((F->axe_y / 2) * (1 + F->DP->x / F->DP->y));
	// F->DP->height = abs((int)(F->axe_x / (F->DP->y)));
	// F->DP->start = -F->DP->height / 2 + F->axe_x / 2 + F->DP->screen;
	// F->DP->end = F->DP->height / 2 + F->axe_x / 2 + F->DP->screen;
	// F->DP->start < 0 ? F->DP->start = 0 : 0;
	// F->DP->end >= F->axe_x ? F->DP->end = F->axe_x - 1 : 0;
	ft_draw_sprite_it(F, i);
	(void)sprite;
}

void		ft_draw_sprite(t_file *file, int i)
{
	t_sprite	*beg_lst;
	t_sprite	*tmp;

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
