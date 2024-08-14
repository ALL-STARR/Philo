/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:20:07 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/14 18:49:48 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	spacer(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	res;
	long long	minus;
	long long	previous;

	res = 0;
	minus = 1;
	i = spacer((char *)str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		previous = res;
		res = (res * 10) + (str[i] - 48);
		if (previous > res && minus == 1)
			return (-1);
		if (previous > res && minus == -1)
			return (0);
		i++;
	}
	return (res * minus);
}