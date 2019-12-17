/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:54:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 20:05:57 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

float	distance(float x1, float y1, float x2, float y2)
{
	float i;
	float j;
	float sum;

	i = (x2 - x1) * (x2 - x1);
	j = (y2 - y1) * (y2 - y1);
	sum = sqrt(i + j);
	return (sum);
}

void	checkwall(t_file *file, float inter[2], int i, char c)
{
	if (c == 'x')
	{
		if (i > 0)
		{
			if(FM->map[(int)(inter[0] + 0.5)][(int)(inter[1] + 0.5)] == '1')
			{
				F->hit = 1;
				printf("WALL AT : x = %f y = %f\n", inter[0], inter[1]);
			}
		}
		else
		{
			if(FM->map[(int)(inter[0])][(int)(inter[1] + 0.5)] == '1')
			{
				F->hit = 1;
				printf("WALL AT : x = %f y = %f\n", inter[0], inter[1]);
			}
		}
	}
	else
	{
		if (i > 0)
		{
			if(FM->map[(int)(inter[0] + 0.5)][(int)(inter[1] + 0.5)] == '1')
			{
				F->hit = 1;
				printf("WALL AT : x = %f y = %f\n", inter[0], inter[1]);
			}
		}
		else
		{
			if(FM->map[(int)(inter[0] + 0.5)][(int)(inter[1])] == '1')
			{
				F->hit = 1;
				printf("WALL AT : x = %f y = %f\n", inter[0], inter[1]);
			}
		}
	}
	
}

void	ft_ray(t_file *file, float x, float y)
{
	float interx[2];
	float intery[2];
	if (x < 0)
	{
		interx[0] = (int)FS->y + 0.5;
		if ((int)FS->y - FS->y > 0.5)
			interx[0] = (int)FS->y + 1.5;
	}
	else
	{
		interx[0] = (int)FS->y - 0.5;
		if ((int)FS->y - FS->y > 0.5)
			interx[0] = (int)FS->y + 0.5;
	}
	if (y < 0)
	{
		intery[1] = (int)FS->x + 0.5;
		if ((int)FS->x - FS->x > 0.5)
			intery[1] = (int)FS->x + 1.5;
	}
	else
	{
		intery[1] = (int)FS->x - 0.5;
		if ((int)FS->x - FS->x > 0.5)
			intery[1] = (int)FS->x + 0.5;
	}
	while (!F->hit)
	{
		interx[1] = FS->x + (fabs(interx[0] - FS->y) / x * y);	//HERE
		intery[0] = FS->y + (fabs(intery[1] - FS->x) / y * x);	//HERE
		if (fabs(y) < 0.001 || (fabs(x) > 0.001 && distance(FS->y, FS->x, interx[0], interx[1]) <
			distance(FS->y, FS->x, intery[0], intery[1])))
		{
			checkwall(file, interx, x, 'x');
			x < 0 ? interx[0]-- : interx[0]++; //HERE
		}
		else
		{
			checkwall(file, intery, y, 'y');
			y < 0 ? intery[1]-- : intery[1]++; //HERE
		}
	}
}

void	raycast(t_file *file)
{
	int i;
	float angle;
	float x;
	float y;

	i = 0;
	while (i < F->axe_x)
	{
		F->hit = 0;
		angle = FS->rotation - (60/2) + i * (60.0/(float)F->axe_x);
		angle *= M_PI / 180;
		x = sin(angle + M_PI);			//HERE
		y = cos(angle);	//HERE
		ft_ray(file, x, y);
		i % 150 == 0 ? sleep(1) : 0;
		i++;
	}
}

int		ft_snakeoil(t_file *file)
{
	raycast(F);
	return (1);
}