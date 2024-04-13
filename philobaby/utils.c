/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:08 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/13 13:59:17 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int not_valid(char string, int num)
{
    if (num <= 4)
        return (-1);
    if (string >= '0' && string <= '9')
        return (0);
    if (string == '+' || string == ' ' || string == '\t')
        return(0);
    return (-1);
}

int le_count(char *string)
{
    int index;

    index = 0;
    while (string[index])
        index++ ;
    return (index);
}

int not_number(char string)
{
    if (string >= '0' && string <= '9')
        return (0);
    return (-1);
}
int loop_on_all(char *string, int num)
{
    int index;

    index = 0;
    if (le_count(string) == 1 && string[0] == '+')
         {
            printf("Invalid argument !\n");
            exit(1);
        }
    while (string[index])
    {
        if (not_valid(string[index], num) == -1)
        {
            printf("Invalid argument !\n");
            exit (1);
        }
        if (string[index] == '+' && not_number(string[index + 1]) == -1)
        {
            printf("Invalid argument !\n");
            exit (1);
        }
        index++ ;
    }
    return (0);
}

int check_valid(char *string)
{
    if (number_converter(string) == -1)
        {
            printf("Invalid argument !\n");
            exit(1);
        }
    return (number_converter(string));
}