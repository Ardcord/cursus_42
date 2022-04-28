/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:33:44 by tvanbael          #+#    #+#             */
/*   Updated: 2022/04/27 19:32:36 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <time.h>

t_strc	g_s;

void	afficher0(int signum)
{
	(void)signum;
	g_s.letter = g_s.letter >> 1;
	g_s.coctet++;
	if (g_s.coctet == 8)
	{
		ft_putchar_fd(g_s.letter, 1);
		g_s.coctet = 0;
	}
}

void	afficher1(int signum)
{
	(void)signum;
	g_s.letter = g_s.letter >> 1 | 10000000;
	g_s.coctet++;
	if (g_s.coctet == 8)
	{
		write(1, &g_s.letter, 1);
		g_s.coctet = 0;
	}
}

int	main(void)
{
	ft_printf("PID = %d\n", getpid());
	signal (SIGUSR1, &afficher0);
	signal (SIGUSR2, &afficher1);
	g_s.letter = 0;
	while (1)
		pause();
	return (0);
}
