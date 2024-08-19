/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:41:25 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/19 20:26:39 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(t_life life, char **arv, int *ded)
{
	int	i;
	
	life.n_philos = ft_atoi(arv[1]);
	i = life.n_philos;
	life.philo = malloc(sizeof(t_philo) * (i));
	if (!life.philo)
		return (printf("malloc fail\n"), 0);
	pthread_mutex_init(life.die, NULL);
	pthread_mutex_init(life.table, NULL);
	pthread_mutex_init(life.write, NULL);
	while (--i >= 0)
		ft_philo_init(life, arv, ded, i);
	return (1);
}

void	ft_philo_init(t_life life, char **ar, int *ded_add, int i)
{
	life.philo[i].id = i + 1;
	pthread_mutex_init(life.philo[i].fork, NULL);
	life.philo[i].dead = ded_add;
	life.philo[i].n_meals = 0;
	life.philo[i].start_time = get_time();
	life.philo[i].last_m = get_time();
	life.philo[i].t_to_die = ft_atoi(ar[2]);
	life.philo[i].t_to_eat = ft_atoi(ar[3]);
	life.philo[i].t_to_sleep = ft_atoi(ar[4]);
	life.philo[i].die = life.die;
	life.philo[i].table = life. table;
	life.philo[i].write = life.write;
	if (ar[5])
		life.philo[i].meals_to_eat = ft_atoi(ar[5]);
	return ;
}