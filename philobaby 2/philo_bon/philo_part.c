/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:12:21 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/03 11:36:31 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

long long	fu(void)
{
	struct timeval	this_time;

	gettimeofday(&this_time, NULL);
	return (this_time.tv_sec * 1000 + this_time.tv_usec / 1000);
}

void	phill_vars_nedded(t_not *phill, int *array)
{
	phill->number_philos = array[0];
	phill->time_die = array[1];
	phill->time_sleep = array[3];
	phill->time_eat = array[2];
	if (phill->time_eat < 60 || phill->time_die < 60 || phill->time_sleep < 60)
	{
		printf("Invalid Argument !\n");
		exit(1);
	}
	if (array[4] == 0)
		phill->each_philo = -1;
	else
		phill->each_philo = array[4];
}

void	f_p(char *string, int id, long long pass, sem_t *var)
{
	sem_wait(var);
	printf("%lld %d %s", pass, id, string);
	sem_post(var);
}

void	condition(int *index, int number_philos)
{
	if (*index == number_philos - 1)
		*index = 0;
	*index += 1;
}

void	*start_philos(void *args)
{
	t_not	*copy;
	int		index;

	copy = (t_not *)args ;
	index = 0;
	while (1)
	{
		if ((fu() - copy[index].last_meal_time) > \
		copy->time_die && copy[index].last_meal_time > 0)
		{
			sem_wait(copy->print);
			printf("%lld ", (fu() - copy->start_time));
			printf("%d ", copy[index].id);
			printf("died\n");
			exit(1);
		}
		if (copy[copy->number_philos - 1].how_many_time >= \
		copy[copy->number_philos -1].each_philo && copy->each_philo != -1)
		{
			sem_wait(copy->print);
			exit(1);
		}
		condition(&index, copy->number_philos);
	}
	return (NULL);
}