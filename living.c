/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:25:58 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/17 16:59:32 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	living(t_life life)
{	
	int	i;

	i = 0;
	while (i < life.n_philos)
	{
		pthread_create(&life.philo[i].thd, NULL, &routine, &life.philo[i]);
		i++;
	}
}

void	routine(t_philo phil)
{
	while (!phil.dead)
	{
		eat(phil);
		rest(phil);
		think(phil);
	}
}