/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:54:21 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/03 10:35:40 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	main(int argc, char **argv)
{
	int			index;
	int			*all_of_it;
	t_this		*var;
	t_not		*fill;

	fill = malloc(sizeof(t_not));
	var = NULL;
	if (argc > 6)
		return (printf("Invalid Argument !\n"), 0);
	index = 1;
	if (check_if(argv, argc) == -1)
		return (-1);
	all_of_it = return_to_array(argv);
	if (!all_of_it)
		return (0);
	index = 0;
	phill_vars_nedded(fill, all_of_it);
	if (make_bonus(fill) == -1)
		exit(1);
	return (0);
}
