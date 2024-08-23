/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:20:07 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/23 21:01:17 by thomvan-         ###   ########.fr       */
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

size_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	minus;
	size_t	previous;

	res = 0;
	minus = 1;
	i = spacer((char *)str);
	while (str[i] && ft_isdigit(str[i]))
	{
		previous = res;
		res = (res * 10) + (str[i] - 48);
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

	start = get_time();
	while ((get_time() - start) < mtime)
		usleep(50);
	return (0);
}

void	destroyer(t_life life)
{
	int	i;

	i = life.n_philos;
	pthread_mutex_destroy(&life.die);
	pthread_mutex_destroy(&life.table);
	pthread_mutex_destroy(&life.write);
	while (--i >= 0)
		pthread_mutex_destroy(&life.philo[i].fork);
	free(life.philo);
}
