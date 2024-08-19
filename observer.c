/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:28:51 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/19 20:56:59 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	observer(t_life	l)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < l.n_philos)
		{
			if (undertaker(l.philo[i]) == 1 || are_full == 1)/****/
				break;
			i++;	
		}
		if (*l.philo[0].dead == 1)
			break;
	}
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

void	are_full(t_life life)
{
	
}