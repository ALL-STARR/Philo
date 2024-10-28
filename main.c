/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:02:28 by thomvan-          #+#    #+#             */
/*   Updated: 2024/10/28 16:27:27 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	arg_checker(int arc, char **array)
{
	int	i;
	int	j;

	i = 1;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] < '0' || array[i][j++] > '9')
				return (printf("please only write unsigned numbers\n"), 1);
		}
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (ft_atoi(array[i]) < 1)
			return (printf("Error : first 4 args have to be >0\n"), 1);
		i++;
	}
	if (arc == 6 && ft_atoi(array[5]) < 0)
		return (printf("numbers of meals to eat has to be >= 0\n"), 1);
	return (0);
}

int	main(int arc, char **arv)
{
	t_life	life;
	int		ded;

	life.n_philos = ft_atoi(arv[1]);
	life.go = 0;
	life.philo = malloc(sizeof(t_philo) * (life.n_philos));
	if (!life.philo)
		return (printf("malloc fail\n"), 0);
	ded = 0;
	if (arc < 5 || arc > 6)
		return (printf("Error : wrong number of arguments\n"), 0);
	if (arg_checker(arc, arv))
		return (1);
	ft_init(&life, arv, &ded, arc);
	if (living(&life))
		return (1);
	destroyer(life);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}
