/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:28:51 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/20 15:23:05 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*observer(void *life)
{
	int	i;
	t_life	*l;
	
	l = (t_life *)life;
	while (1)
	{
		i = 0;
		while (i < l->n_philos)
		{
			if (undertaker(l->philo[i]) == 1
				|| (are_full(*l) == 1 && l->philo[0].meals_to_eat > -1))
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
	pthread_mutex_lock(p.die);
	if ((get_time() - p.last_m) >= p.t_to_die)
	{
		*p.dead = 1;
		printer(p, "died\n");
		return (pthread_mutex_unlock(p.die), 1);
	}
	return (pthread_mutex_unlock(p.die), 0);
}

int	are_full(t_life life)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	while (i < life.n_philos)
	{
		pthread_mutex_lock(life.table);
		if (life.philo[i].n_meals == life.philo[i].meals_to_eat)
			finished++;
		pthread_mutex_unlock(life.table);
		i++;
	}
	if (finished == life.n_philos)
	{
		pthread_mutex_lock(life.die);
		*life.philo[0].dead = 1;
		return (pthread_mutex_unlock(life.die), 1);
	}
	return (0);
}
