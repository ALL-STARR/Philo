/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:25:58 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/19 20:27:00 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	living(t_life *life)
{	
	int	i;

	i = 0;
	while (i < life->n_philos)
	{
		if (pthread_create(&life->philo[i].thd, NULL, &routine, life) != 0)
			destroyer(*life);
		i++;
		life->index = i;
	}
	i = 0;
	while (i < life->n_philos)
	{
		if (pthread_join(&life->philo[i].thd, NULL) != 0)
			destroyer(*life);
		i++;
	}
}

void	routine(t_life lif)
{
	int	i;

	i = lif.index;
	while (!*lif.philo[0].dead)
	{
		eat(lif, i);
		rest(lif.philo[i]);
		think(lif.philo[i]);
	}
}

void	printer(t_philo p, char *str)
{
	pthread_mutex_lock(p.write);
	printf("%d %d %s", (int)timer, p.id, str);
	pthread_mutex_unlock(p.write);
}

size_t	timer(t_philo p)
{
	return (get_time() - p.start_time);
}