/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:25:58 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/20 15:28:10 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	living(t_life *life)
{
	int			i;
	pthread_t	obs;

	i = 0;
	if (pthread_create(&obs, NULL, &observer, (void *)life) != 0)
		destroyer(*life);
	while (i < life->n_philos)
	{
		if (pthread_create(&life->philo[i].thd, NULL, &routine, (void *)life) != 0)
			destroyer(*life);
		i++;
		life->index = i;
	}
	i = 0;
	if (pthread_join(obs, NULL) != 0)
		destroyer(*life);
	while (i < life->n_philos)
	{
		if (pthread_join(life->philo[i].thd, NULL) != 0)
			destroyer(*life);
		i++;
	}
}

void	*routine(void *life)
{
	int	i;
	t_life	*lif;

	lif = (t_life *)life;
	i = lif->index;
	while (!is_he_dead(lif->philo[i]))
	{
		eat(*lif, i);
		rest(lif->philo[i]);
		think(lif->philo[i]);
	}
	return (NULL);
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

int	is_he_dead(t_philo p)
{
	pthread_mutex_lock(p.die);
	if (*p.dead == 1)
		return (pthread_mutex_unlock(p.die), 1);
	return (pthread_mutex_unlock(p.die), 0);
}
