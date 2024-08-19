/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:04:19 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/19 19:53:03 by thomvan-         ###   ########.fr       */
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
	size_t				last_m;
	size_t				start_time;
	pthread_mutex_t		*table;
	pthread_mutex_t		*die;
	pthread_mutex_t		*write
}	t_philo;

typedef struct s_life
{
	t_philo	*philo;
	pthread_mutex_t	*table;
	pthread_mutex_t	*die;
	pthread_mutex_t	*write;
	size_t	n_philos;
	int		index;
}	t_life;

int		ft_atoi(const char *str);
int		ft_init(t_life life, char **arv, int *ded);
void	ft_philo_init(t_philo phil, char **ar, int *ded_add, int id);
size_t	get_time(void);
int		waiter(size_t mtime);
void	destroyer(t_life life);
void	eat(t_life lif, int i);
void	rest(t_philo phil);
void	think(t_philo p);
void	living(t_life *life);
void	routine(t_life lif);
void	printer(t_philo p, char *str);
size_t	timer(t_philo p);

#endif