/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:08 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/21 15:50:44 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	not_valid(char string, int num)
{
	if (num <= 4)
		return (-1);
	if (string >= '0' && string <= '9')
		return (0);
	if (string == '+' || string == ' ' || string == '\t')
		return (0);
	return (-1);
}

int	le_count(char *string)
{
	int	index;

	index = 0;
	while (string[index])
		index++ ;
	return (index);
}

int	not_number(char string)
{
	if ((string >= '0' && string <= '9') || string == '+')
		return (0);
	return (-1);
}

int	there_is_nothing(char *string)
{
	int		index;
	int		flag;

	flag = 0;
	index = 0;
	while (string[index])
	{
		if (string[index] >= '0' || string[index] == '9')
			flag++ ;
		index++ ;
	}
	return (flag);
}

int	loop_on_all(char *string, int num)
{
	int	index;

	index = 0;
	if ((le_count(string) == 1 && string[0] == '+') || le_count(string) == 0)
	{
		printf("Invalid argument !\n");
		return (-1);
	}
	while (string[index])
	{
		if (not_valid(string[index], num) == -1)
		{
			printf("Invalid argument !\n");
			return (-1);
		}
		if (string[index] == '+' && \
		not_number(string[index + 1]) == -1)
		{
			printf("Invalid argument !\n");
			return (-1);
		}
		index++ ;
	}
	return (0);
}
