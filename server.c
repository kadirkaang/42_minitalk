/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:14:10 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/11 15:49:21 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sig_handler(int signal)
{
	static int	a;
	static int	bit;

	a = a << 1;
	if (signal == SIGUSR1)
		a |= 1;
	else
		a |= 0;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", a);
		a = 0;
		bit = 0;
	}	
}

int	main(int ac, char **av)
{
	int	pid;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
