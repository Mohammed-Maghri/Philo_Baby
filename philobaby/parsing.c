/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:20:06 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/13 13:14:44 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int check_over_flow(long long number, int minis)
{
    if (minis > 0 && number > 2147483647)
        return (-1);
    if (minis < 0 && number > 2147483648)
        return (-1);
    return (0);
}

int number_converter(char *string)
{
    t_this all;

    all.index = 0;
    all.minis = 1;
    all.store = 0;

    
    while(string[all.index] == ' ' || (string[all.index] >= 9 && string[all.index] <= 13))
        all.index++ ;
    while (string[all.index] == '-' || string[all.index] == '+')
    {
        if (string[all.index] == '-')
            all.minis *= -1;
        all.index++ ;
    }
    while (string[all.index] && string[all.index] >= '0' && string[all.index] <= '9')
    {
        all.store = (all.store * 10) + (string[all.index] - '0');
        if (check_over_flow(all.store, all.minis) == -1)
            return (-1);
        all.index++ ;
    }
    return (all.store * all.minis);
}
int check_if_this_valid(char *string)
{
    (void)string;
    return (0);
}