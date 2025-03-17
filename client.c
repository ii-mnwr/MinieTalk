/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:20:28 by mthodi            #+#    #+#             */
/*   Updated: 2024/02/18 18:06:46 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	killuser(char *mess, int pid)
{
	int		i;
	int		shift;
	int		check;
	char	x;
	char	bit;

	i = 0;
	while (mess[i])
	{
		x = mess[i];
		shift = 7;
		while (shift >= 0)
		{
			bit = (x >> shift) & 1;
			if (bit)
				check = kill(pid, SIGUSR1);
			else
				check = kill (pid, SIGUSR2);
			shift--;
			usleep(300);
		}
		i++;
	}
	if (check == -1)
		ft_putstr("Wrong PID");
}

int	checker(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3 || ac > 3)
	{
		ft_putstr("Error: Enter three arguments only");
		return (0);
	}
	while (av[1][i])
	{
		if (ft_isalpha(av[1][i]))
		{
			ft_putstr("Error: Enter only numbers");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*mess;

	if (!checker(ac, av))
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr("Wrong PID");
		return (0);
	}
	mess = av[2];
	killuser(mess, pid);
	return (0);
}
