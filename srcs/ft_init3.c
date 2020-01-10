/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init3.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 16:50:12 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:52:08 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_init_hubdraw(t_file *file)
{
	if (!(F->HD = malloc(sizeof(t_hubdr))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc hub draw\n");
		return (0);
	}
	return (1);
}
