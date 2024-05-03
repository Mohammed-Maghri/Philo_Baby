/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:35:57 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/03 11:36:19 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

t_not	*return_number_philo(t_not *check)
{
	int		index;
	t_not	*this ;

	this = malloc(sizeof(t_not) * check->number_philos);
	index = 0;
	this->index = 0;
	while (index < check->number_philos)
	{
		this[index].number_philos = check->number_philos ;
		this[index].each_philo = check->each_philo ;
		this[index].time_die = check->time_die ;
		this[index].time_eat = check->time_eat ;
		this[index].time_sleep = check->time_sleep ;
		this[index].how_many_time = check->how_many_time ;
		this[index].last_meal_time = 0;
		this[index].id = index ;
		this[index].outside = 0;
		index++ ;
	}
	return (this);
}

void	function_sleep(long long in_milisecond)
{
	long long		start;

	(void)in_milisecond;
	start = fu();
	while (fu() - start < in_milisecond)
		usleep(50);
}

void	function_initial(t_not *copy)
{
	sem_unlink("protec");
	sem_unlink("print");
	copy->var = sem_open("protec", O_CREAT | O_EXCL, 644, copy->number_philos);
	copy->print = sem_open("print", O_CREAT, 644, 1);
	copy->start_time = fu();
	copy->last_meal_time = fu();
}

void	for_function_set(int id, long long res, sem_t *lock, int time_sleep)
{
	f_p("is sleeping\n", id, \
	res, lock);
	function_sleep(time_sleep);
	f_p("is thinking\n", id, \
	res, lock);
}

void	function_set(t_not *copy, int index, pid_t pid)
{
	pid = fork();
	copy->porcess[index] = pid;
	if (pid == 0)
	{
		pthread_create(&copy->initial, NULL, &start_philos, copy);
		pthread_detach(copy->initial);
		while (1)
		{
			sem_wait(copy->var);
			f_p("has taken a fork\n", copy[index].id, \
			(fu() - copy->start_time), copy->print);
			copy[index].last_meal_time = fu();
			sem_wait(copy->var);
			copy[index].how_many_time++ ;
			f_p("has taken a fork\n", copy[index].id, \
			(fu() - copy->start_time), copy->print);
			f_p("is eating\n", copy[index].id, \
			(fu() - copy->start_time), copy->print);
			function_sleep(copy->time_eat);
			sem_post(copy->var);
			sem_post(copy->var);
			for_function_set(copy[index].id, \
			(fu() - copy->start_time), copy->print, copy->time_sleep);
		}
	}
}

int	make_bonus(t_not *check)
{
	int		index;
	pid_t	pid;
	t_not	*copy;

	pid = -1;
	index = 0;
	index = 0;
	copy = return_number_philo(check);
	function_initial(copy);
	while (index < check->number_philos)
	{
		function_set(copy, index, pid);
		index++;
	}
	waitpid(-1, NULL, 0);
	index = 0;
	while (index < check->number_philos)
	{
		kill(copy->porcess[index], SIGILL);
		index++ ;
	}
	return (-1);
}