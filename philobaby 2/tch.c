/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tch.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:50:11 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/21 16:35:14 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_valid(char *string)
{
	return (number_converter(string));
}

int	function_add(t_ini *point, int index, int flag, int increment)
{
	while (1)
	{
		increment_this(&point[increment], &flag, &increment);
		if (increment == point[increment].nmp - 1 && point[increment].nmp != 1)
			return (pthread_mutex_lock(point->print_not), -1);
		usleep(50);
		if (index == point->nmp)
			index = 0;
		pthread_mutex_lock(point->lock_him);
		if ((fu() - point->last_meal_time) > \
		point[index].time_to_die)
		{
			function_t(point);
			f_p("died\n", point->id, (fu() - \
			point->start_time), point);
			pthread_mutex_lock(point->print_not);
			return (-1);
		}
		pthread_mutex_unlock(point->lock_him);
		index++ ;
	}
	return (0);
}
