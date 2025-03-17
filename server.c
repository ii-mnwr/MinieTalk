/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:40:13 by mthodi            #+#    #+#             */
/*   Updated: 2024/02/18 20:30:46 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigreceive(int sig)
{
	static char	current_c;
	static int	bit = 0;

	if (sig == SIGUSR1)
		current_c = (current_c << 1) | 1;
	if (sig == SIGUSR2)
		current_c = (current_c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		ft_putchar(current_c);
		current_c = 0;
	}
}

int	main(void)
{
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, sigreceive);
	signal(SIGUSR2, sigreceive);
	while (1)
		;
}
