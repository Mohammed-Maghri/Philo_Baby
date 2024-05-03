/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 03:38:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/28 12:01:16 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

void	this_init(t_in_str *this, t_ini	*copy)
{
	copy->nmp = this->nmp;
	copy->start_time = fu();
	copy->each_time = 0;
	copy->nf_t_each_philo = this->nf_t_each_philo ;
	copy->lock_each_time = &this->lock_each_time;
	copy->monitor = &this->monitor;
	copy->thisthread = &this->thisthread;
	copy->lock_it_up = &this->lock_it_up;
	copy->lock_him = &this->lock_him;
	copy->this = &this->this;
}

t_ini	*start_dining(t_in_str *this)
{
	t_this	wee;
	t_ini	*copy;

	wee.index = 0;
	copy = malloc(sizeof(t_ini) * this->nmp);
	while (wee.index < this->nmp)
	{
		copy[wee.index].id = wee.index + 1;
		copy[wee.index].whole_philos = this->nmp;
		copy[wee.index].left_one = (wee.index + 1) % this->nmp;
		copy[wee.index].right_one = wee.index;
		copy[wee.index].lock_var = &this->lock_var[copy[wee.index].left_one];
		copy[wee.index].sec_var = &this->lock_var[copy[wee.index].right_one];
		copy[wee.index].time_to_sleep = this->time_to_sleep;
		copy[wee.index].print_not = &this->print_not;
		copy[wee.index].print_not = &this->print_not;
		copy[wee.index].time_to_eat = this->time_to_eat;
		copy[wee.index].time_to_die = this->time_to_die;
		copy[wee.index].onlyone = &this->only_one;
		copy[wee.index].stop = &this->stop;
		this_init(this, &copy[wee.index]);
		wee.index++;
	}
	wee.index = 0;
	return (copy);
}

void	mute_it(t_ini *waa)
{
	pthread_mutex_lock(waa->lock_each_time);
	waa->each_time++;
	pthread_mutex_unlock(waa->lock_each_time);
}

void	*start_philos(void *args)
{
	t_ini	*waa;

	waa = (t_ini *)args;
	if (waa->id % 2 == 0)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(waa->lock_var);
		f_p("has taken a fork\n", waa->id, (fu() - waa->start_time), waa);
		if (waa->nmp == 1)
			pthread_mutex_lock(waa->lock_var);
		pthread_mutex_lock(waa->sec_var);
		f_p("has taken a fork\n", waa->id, (fu() - waa->start_time), waa);
		pthread_mutex_lock(waa->lock_him);
		waa->last_meal_time = fu();
		pthread_mutex_unlock(waa->lock_him);
		mute_it(waa);
		f_p("is eating\n", waa->id, (fu() - waa->start_time), waa);
		function_sleep(waa->time_to_eat);
		pthread_mutex_unlock(waa->lock_var);
		pthread_mutex_unlock(waa->sec_var);
		f_p("is sleeping\n", waa->id, (fu() - waa->start_time), waa);
		function_sleep(waa->time_to_sleep);
		f_p("is thinking\n", waa->id, (fu() - waa->start_time), waa);
		pthread_mutex_lock(waa->stop);
		pthread_mutex_unlock(waa->stop);
	}
	return (NULL);
}

void	increment_this(t_ini *point, int *flag, int *increment)
{
	pthread_mutex_lock(point->lock_each_time);
	if (point->each_time == point->nf_t_each_philo)
	{
		*flag += 1 ;
		*increment += 1;
	}
	pthread_mutex_unlock(point->lock_each_time);
}
