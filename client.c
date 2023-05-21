/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:14:07 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/11 15:54:55 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_byte(int *arr, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (arr[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	free(arr);
}

int	*ft_dec_to_byte(unsigned int c)
{
	int	i;
	int	*byte_arr;

	byte_arr = (int *)malloc(8 * sizeof(int));
	i = 7;
	while (i > -1)
	{
		byte_arr[i] = (c % 2);
		c /= 2;
		i--;
	}
	return (byte_arr);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 3)
	{
		i = 0;
		while (av[2][i] != '\0')
		{
			ft_send_byte(ft_dec_to_byte(av[2][i]), ft_atoi(av[1]));
			i++;
		}
		ft_send_byte(ft_dec_to_byte(10), ft_atoi(av[1]));
	}
	else
	{
		ft_printf("Error : Wrong format !!!\n");
		return (1);
	}
	return (0);
}
