/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:23:34 by tvanbael          #+#    #+#             */
/*   Updated: 2022/04/27 20:02:26 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	binary_converter(unsigned int letter, int pid)
{
	int	count;

	count = 8;
	while (count > 0)
	{
		if (letter % 2)
			kill(pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		letter = letter / 2;
		count--;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	count;

	count = 0;
	if (argc < 3)
	{
		write(1, "Please, do : ./client [PID] [message]", 37);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][count])
	{
		binary_converter(argv[2][count], pid);
		count ++;
	}
	binary_converter('\n', pid);
	return (0);
}
