/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:04:19 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/17 16:55:00 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		*fork;
	pthread_t			thd;
	int					*dead;
	int					n_meals;
	size_t				t_to_die;
	size_t				t_to_eat;
	size_t				t_to_sleep;
	int					meals_to_eat;
	size_t				start;
}	t_philo;

typedef struct s_life
{
	t_philo	*philo;
	size_t	n_philos;
}	t_life;

int		ft_atoi(const char *str);
int		ft_init(t_life life, char **arv, int *ded);
void	ft_philo_init(t_philo phil, char **ar, int *ded_add, int id);

#endif