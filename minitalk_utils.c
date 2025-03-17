/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:44:01 by mthodi            #+#    #+#             */
/*   Updated: 2024/02/17 19:24:57 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int c)
{
	if (c >= 10)
		ft_putnbr(c / 10);
	write(1, &(int){'0' + (c % 10)}, 1);
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_putstr(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
		write(1, &str[a++], 1);
}

int	ft_atoi(const char *str)
{
	unsigned int	a;
	int				neg;

	a = 0;
	neg = 1;
	while (*str && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && (*str >= 48 && *str <= 57))
	{
		a = a * 10 + (*str - '0');
		str++;
	}
	return (a * neg);
}
