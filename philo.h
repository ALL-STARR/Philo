/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:04:19 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/14 19:09:05 by thomvan-         ###   ########.fr       */
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
	pthread_mutex_t		fork;
	pthread_t			thread;
	int					*dead;
	int					n_meals;
	size_t				t_to_eat;
	size_t				t_to_sleep;
	size_t				t_to_die;
	int					meals_to_eat;
	size_t				start;
}	t_philo;

typedef struct s_life
{
	t_philo	*philo;
	size_t	n_philos;
}	t_life;

int	ft_atoi(const char *str);

#endif