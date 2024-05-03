/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:04:02 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/24 11:06:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

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