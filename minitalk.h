/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:57:59 by mthodi            #+#    #+#             */
/*   Updated: 2024/02/18 20:31:58 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <signal.h>

void	ft_putnbr(int c);
void	ft_putchar(int c);
void	ft_putstr(const char *str);
int		ft_atoi(const char *str);
void	killuser(char *mess, int pid);
void	sigreceive(int sig);
int		ft_isalpha(int c);

#endif