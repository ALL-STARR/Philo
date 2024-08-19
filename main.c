/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:02:28 by thomvan-          #+#    #+#             */
/*   Updated: 2024/08/19 20:24:32 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	arg_checker(int	arc, char **array)
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
				return (printf("Error : please only write numbers\n"), 1);
		}
		i++;
	}
	i = 1;
	while (i < 6)
	{
		if (ft_atoi(array[i++]) < 1)
			return (printf("Error : first 4 args have to be >0\n"), 1);
	}
	if (arc == 6 && ft_atoi(array[i]) < 0)
		return (printf("Error : numbers of meals to eat has to be >=0\n"), 1);
	return (0);
}

int	main(int arc, char **arv)
{
	t_life	life;
	int		ded;
	
	ded = 0;
	if (arc < 5 || arc > 6)
		return (printf("Error : wrong number of arguments\n"), 0);
	if (arg_checker(arc, arv))
		return (1);
	if (!ft_init(life, arv, &ded))
		return (1);
	living(&life);
	destroyer(life);
}