/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:00:08 by thomvan-          #+#    #+#             */
/*   Updated: 2024/10/28 16:58:24 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_life lif, int i)
{
	pthread_mutex_lock(&lif.philo[lif.philo[i].id - 1].fork);
	printer(lif.philo[i], "has taken a fork\n");
	if (lif.n_philos == 1)
	{
		waiter(lif.philo[0].t_to_die);
		pthread_mutex_unlock(&lif.philo[lif.philo[i].id - 1].fork);
		return ;
	}
	pthread_mutex_lock(&lif.philo[lif.philo[i].id % lif.n_philos].fork);
	printer(lif.philo[i], "has taken a fork\n");
	lif.philo[i].is_eating = 1;
	pthread_mutex_lock(lif.philo[i].table);
	lif.philo[i].last_m = get_time();
	pthread_mutex_unlock(lif.philo[i].table);
	printer(lif.philo[i], "is eating\n");
	waiter(lif.philo[0].t_to_eat);
	pthread_mutex_lock(lif.philo[i].table);
	lif.philo[i].n_meals++;
	pthread_mutex_unlock(lif.philo[i].table);
	lif.philo[i].is_eating = 0;
	pthread_mutex_unlock(&lif.philo[lif.philo[i].id - 1].fork);
	pthread_mutex_unlock(&lif.philo[lif.philo[i].id % lif.n_philos].fork);
	return ;
}

void	rest(t_philo phil)
{
	printer(phil, "is sleeping\n");
	waiter(phil.t_to_sleep);
	return ;
}

void	think(t_philo p)
{
	printer(p, "is thinking\n");
	return ;
}

void	tab_value_changer(int to_change, int val, t_life l)
{
	pthread_mutex_lock(&l.table);
	to_change = val;
	pthread_mutex_unlock(&l.table);
}
