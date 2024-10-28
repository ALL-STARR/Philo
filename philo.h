/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:04:19 by thomvan-          #+#    #+#             */
/*   Updated: 2024/10/28 16:27:33 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		fork;
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
	pthread_mutex_t		*write;
	int					is_eating;
}	t_philo;

typedef struct s_life
{
	t_philo			*philo;
	pthread_mutex_t	table;
	pthread_mutex_t	die;
	pthread_mutex_t	write;
	int				go;
	int				n_philos;
	int				ac;
	int				index;
}	t_life;

size_t	ft_atoi(const char *str);
void	ft_init(t_life *life, char **arv, int *ded, int ac);
void	ft_philo_init(t_life life, char **ar, int *ded_add, int id);
size_t	get_time(void);
int		waiter(size_t mtime);
void	destroyer(t_life life);
void	eat(t_life lif, int i);
void	rest(t_philo phil);
void	think(t_philo p);
int		living(t_life *life);
void	*routine(void *life);
void	printer(t_philo p, char *str);
size_t	timer(t_philo p);
int		is_he_dead(t_philo p);
void	*observer(void *life);
int		undertaker(t_philo p);
int		are_full(t_life life);
int		ft_isdigit(int c);
int		check_pulse(t_philo p);
void	tab_value_changer(int to_change, int val, t_life l);

#endif