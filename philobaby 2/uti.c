/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:38:40 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/21 15:25:57 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if(char **all_this, int argc)
{
	int		index;

	index = 1;
	while (all_this[index])
	{
		if (loop_on_all(all_this[index], argc) == -1)
			return (-1);
		index++;
	}
	return (0);
}

int	*return_to_array(char **argv)
{
	int		index;
	int		*this_array;
	int		increment;

	increment = 0;
	this_array = malloc(sizeof(int) * 5);
	if (!this_array)
		return (NULL);
	index = 1;
	while (argv[index])
	{
		if (number_converter(argv[index]) == -1)
			return (printf("Invalid argument !\n"), NULL);
		this_array[increment] = check_valid(argv[index]);
		increment++;
		index++;
	}
	return (this_array);
}

void	function_print(char *string, t_ini *waa, long long pass)
{
	pthread_mutex_lock(waa->print_not);
	if (pass > -1)
		printf("%lld ", pass);
	if (string)
		printf("%s", string);
	pthread_mutex_unlock(waa->print_not);
}

void	f_p(char *string, int id, long long pass, t_ini *waa)
{
	pthread_mutex_lock(waa->print_not);
	printf("%lld %d %s", pass, id, string);
	pthread_mutex_unlock(waa->print_not);
}

void	function_t(t_ini *waa)
{
	pthread_mutex_lock(waa->stop);
	waa->lock_time = 1;
	waa->time = -1;
	pthread_mutex_unlock(waa->stop);
}
