/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:20:07 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/19 19:08:58 by thomvan-         ###   ########.fr       */
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

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() fail\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	waiter(size_t mtime)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < mtime)
		usleep(500);
	return (0);
}

void	destroyer(t_life life)
{
	int	i;

	i = life.n_philos;
	pthread_mutex_destroy(life.dead);
	pthread_mutex_destroy(life.table);
	while (--i >= 0)
		pthread_mutex_destroy(life.philo[i].fork);
	free(life.philo);
}