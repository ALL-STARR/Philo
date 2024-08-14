/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:41:25 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/14 19:12:26 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_life life, char **arv)
{
		life.n_philos = ft_atoi(arv[1]);
		life.philo = malloc(sizeof(t_philo) * (life.n_philos + 1));
		while (--life.n_philos >= 0)
			ft_philo_init(life.philo[life.n_philos], arv);
			
		
}

void	ft_philo_init(t_philo lif, char **ar)
{
	
}