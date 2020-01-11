/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 19:57:59 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 21:00:41 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

void		ft_free_audio(t_file *file)
{
	Mix_FreeChunk(F->audio->damaged);
	Mix_FreeChunk(F->audio->heal);
	Mix_FreeChunk(F->audio->secret);
	Mix_FreeMusic(F->audio->music);
	Mix_FreeChunk(F->audio->start);
}