/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:25:58 by thomvan-          #+#    #+#             */
/*   Updated: 2024/10/28 16:55:58 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	living(t_life *life)
{
	int			i;
	pthread_t	obs;

	i = 0;
	if (pthread_create(&obs, NULL, &observer, (void *)life) != 0)
		return (printf("pthread_create error\n"), destroyer(*life), 1);
	while (i < life->n_philos)
	{
		if (pthread_create(&life->philo[i].thd, NULL,
				&routine, (void *)life) != 0)
			return (printf("pthread_create error\n"), destroyer(*life), 1);
		i++;
		pthread_mutex_lock(&life->table);
		life->index = i;
		pthread_mutex_unlock(&life->table);
	}
	life->go = 0;
	i = 0;
	if (pthread_join(obs, NULL) != 0)
		return (printf("pthread_join error\n"), destroyer(*life), 1);
	while (i < life->n_philos)
		if (pthread_join(life->philo[i++].thd, NULL) != 0)
			return (printf("pthread_join error\n"), destroyer(*life), 1);
	return (0);
}

void	*routine(void *life)
{
	int		i;
	t_life	*lif;

	lif = (t_life *)life;
	pthread_mutex_lock(&lif->table);
	i = lif->index;
	pthread_mutex_unlock(&lif->table);
	while (lif->go)
		waiter(10);
	pthread_mutex_lock(&lif->table);
	lif->philo[i].start_time = get_time();
	lif->philo[i].last_m = get_time();
	pthread_mutex_unlock(&lif->table);
	if (lif->philo[i].id % 2 == 0)
		waiter(50);
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
	if (!is_he_dead(p))
		printf("%zu %d %s", timer(p), p.id, str);
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
