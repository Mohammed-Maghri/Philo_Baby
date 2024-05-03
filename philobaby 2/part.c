/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:55:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/28 11:47:22 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	this_end(t_in_str *this, int *array, int argc)
{
	if (argc - 1 == 4)
		this->nf_t_each_philo = -1;
	else if (argc - 1 == 5)
		this->nf_t_each_philo = array[4];
	this->nmp = array[0];
	if (this->nmp == 0)
		return (-1);
	this->time_to_die = array[1];
	this->time_to_eat = array[2];
	this->time_to_sleep = array[3];
	if (this->time_to_die < 60 || \
	this->time_to_eat < 60 || \
	this->time_to_sleep < 60)
	{
		printf("Not a valid argument !\n");
		return (-1);
	}
	if (this->nf_t_each_philo == 0)
	{
		printf("Not Enough !\n");
		return (-1);
	}
	return (0);
}

int	fill_shit(t_in_str *this, int *array, int argc)
{
	int	index;
	int	flag;

	(void)this;
	(void)array;
	flag = 0;
	flag = this_end(this, array, argc);
	index = 0;
	while (index < this->nmp)
	{
		pthread_mutex_init(&this->lock_var[index], NULL);
		index++;
	}
	pthread_mutex_init(&this->print_not, NULL);
	pthread_mutex_init(&this->monitor, NULL);
	pthread_mutex_init(&this->only_one, NULL);
	pthread_mutex_init(&this->stop, NULL);
	pthread_mutex_init(&this->lock_each_time, NULL);
	pthread_mutex_init(&this->thisthread, NULL);
	pthread_mutex_init(&this->lock_it_up, NULL);
	pthread_mutex_init(&this->lock_him, NULL);
	pthread_mutex_init(&this->this, NULL);
	return (flag);
}

long long	fu(void)
{
	struct timeval	this_time;

	gettimeofday(&this_time, NULL);
	return (this_time.tv_sec * 1000 + this_time.tv_usec / 1000);
}

void	function_sleep(long long in_milisecond)
{
	long long		start;

	(void)in_milisecond;
	start = fu();
	while (fu() - start < in_milisecond)
		usleep(50);
}

int	function_create_many_philos(t_ini *point, t_in_str *more)
{
	pthread_t	this_thread;
	int			index;
	int			increment ;
	int			flag;

	flag = 0;
	index = 0;
	increment = 0;
	while (index < more->nmp)
	{
		point[index].last_meal_time = fu();
		pthread_create(&this_thread, NULL, &start_philos, &point[index]);
		pthread_detach(this_thread);
		index++;
	}
	index = function_add(point, index, flag, increment);
	if (index == -1)
		return (-1);
	return (0);
}
