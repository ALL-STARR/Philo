/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:28:51 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/23 22:10:20 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*observer(void *life)
{
	int		i;
	t_life	*l;

	l = (t_life *)life;
	while (1)
	{
		i = 0;
		while (i < l->n_philos)
		{
			if (undertaker(l->philo[i]) == 1 || are_full(*l) == 1)
				break ;
			i++;
		}
		if (*l->philo[0].dead == 1)
			break ;
	}
	return (NULL);
}

int	undertaker(t_philo p)
{
	if (check_pulse(p))
	{
		printer(p, "died\n");
		pthread_mutex_lock(p.die);
		*p.dead = 1;
		pthread_mutex_unlock(p.die);
		return (1);
	}
	return (0);
}

int	are_full(t_life life)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	if (life.philo[0].meals_to_eat == -1)
		return (0);
	while (i < life.n_philos)
	{
		pthread_mutex_lock(life.philo[i].table);
		if (life.philo[i].n_meals == life.philo[i].meals_to_eat)
			finished++;
		pthread_mutex_unlock(life.philo[i].table);
		i++;
	}
	if (finished == life.n_philos)
	{
		pthread_mutex_lock(life.philo[0].die);
		*life.philo[0].dead = 1;
		return (pthread_mutex_unlock(life.philo[0].die), 1);
	}
	return (0);
}

int	check_pulse(t_philo p)
{
	size_t	wait;

	pthread_mutex_lock(p.table);
	wait = get_time() - p.last_m;
	if (p.is_eating == 0 && wait >= p.t_to_die)
		return (pthread_mutex_unlock(p.table), 1);
	return (pthread_mutex_unlock(p.table), 0);
}
