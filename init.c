/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:41:25 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/17 16:56:54 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(t_life life, char **arv, int *ded)
{
	life.n_philos = ft_atoi(arv[1]);
	life.philo = malloc(sizeof(t_philo) * (life.n_philos));
	if (!life.philo)
		return (printf("malloc fail\n"), 0);
	while (--life.n_philos >= 0)
		ft_philo_init(life.philo[life.n_philos], arv, ded, life.n_philos + 1);
	return (1);
}

void	ft_philo_init(t_philo phil, char **ar, int *ded_add, int id)
{
	phil.id = id;
	pthread_mutex_init(phil.fork, NULL);
	phil.dead = ded_add;
	phil.n_meals = 0;
	phil.t_to_die = ft_atoi(ar[2]);
	phil.t_to_eat = ft_atoi(ar[3]);
	phil.t_to_sleep = ft_atoi(ar[4]);
	if (ar[5])
		phil.meals_to_eat = ft_atoi(ar[5]);
	return ;
}