/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:06:47 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 15:56:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

void	ft_sound(char *sound)
{
	int pid;
	int i;

	pid = fork();
	if (pid == 0)
	{
		i = system(sound);
		exit(0);
	}
	(void)i;    
}
