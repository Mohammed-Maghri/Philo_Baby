/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:08:13 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/23 17:17:25 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			index;
	int			*all_of_it;
	t_ini		*waa;
	t_in_str	*this_all;

	if (argc > 6)
		return (printf("Invalid Argument !\n"), 0);
	index = 1;
	if (check_if(argv, argc) == -1)
		return (-1);
	all_of_it = return_to_array(argv);
	if (!all_of_it)
		return (0);
	this_all = malloc(sizeof(t_in_str));
	if (fill_shit(this_all, all_of_it, argc) == -1)
		return (-1);
	waa = start_dining(this_all);
	if (function_create_many_philos(waa, this_all) == -1)
		return (1);
	return (0);
}
