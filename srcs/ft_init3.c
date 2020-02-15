/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:50:12 by jacens            #+#    #+#             */
/*   Updated: 2020/02/15 14:39:07 by jacens           ###   ########lyon.fr   */
/*                                                                            */
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

int			ft_init_audio(t_file *file)
{
	if (!(F->audio = malloc(sizeof(t_audio))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc hub draw\n");
		return (0);
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	F->audio->damaged = Mix_LoadWAV("./audio/damaged2.mp3");
	F->audio->heal = Mix_LoadWAV("./audio/heal.mp3");
	F->audio->heal2 = Mix_LoadWAV("./audio/heal2.mp3");
	F->audio->secret = Mix_LoadWAV("./audio/secret.mp3");
	F->audio->music = Mix_LoadMUS("./audio/bruh.mp3");
	F->audio->start = Mix_LoadWAV("./audio/start.mp3");
	F->audio->end = Mix_LoadWAV("./audio/end.mp3");
	F->audio->endwin = Mix_LoadWAV("./audio/endwin.mp3");
	Mix_PlayMusic(F->audio->music, -1);
	Mix_PlayChannel(3, file->audio->start, 0);
	return (1);
}
