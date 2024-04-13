/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 03:38:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/13 15:17:18 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_if(char **all_this, int argc)
{
    int index;

    index = 1;
    while (all_this[index])
    {
        loop_on_all(all_this[index], argc);
        index++ ;
    }
}
int *return_to_array(char **argv)
{
    int     index;
    int    *this_array;
    int     increment;

    increment = 0;
    this_array = malloc(sizeof(int) * 5);
    if (!this_array)
        return (NULL);
    index = 1;
    while (argv[index])
    {
        this_array[increment] = check_valid(argv[index]);
        increment++ ;
        index++ ;
    }
    return (this_array);
}

void fill_shit(in_str *this, int *array, int argc)
{
    (void)this;
    (void)array;

    if (argc - 1  == 4)
        this->nf_t_each_philo = -1;
    else if (argc -1 == 5)
        this->nf_t_each_philo = array[4];
    this->number_of_philosophers = array[0];
    this->time_to_die = array[1];
    this->time_to_eat = array[2];
    this->time_to_sleep = array[3];
    if (this->nf_t_each_philo == 0)
        {
            printf("Not Enough !\n");
            exit(1);
        }
}

int main(int argc, char **argv)
{
    if (argc > 6)
    {
        printf("Invalid Argument !\n");
        return (0);
    }
    int index ;
    int *all_of_it;

    index = 1;
    check_if(argv, argc);
    all_of_it = return_to_array(argv);
    in_str  *this_all;
    this_all = malloc(sizeof(in_str));
    fill_shit(this_all, all_of_it, argc);
    index = 0;
    while (all_of_it[index])
    {
        printf("-----> | %d |\n", all_of_it[index]);
        index++ ;
    }
    index = 0;
    printf("   [%d]   \n", this_all->number_of_philosophers);
    printf("   [%d]   \n", this_all->time_to_die);
    printf("    [%d]  \n", this_all->time_to_eat);
    printf("   [%d]  \n", this_all->time_to_sleep);
    printf("    [%d]\n", this_all->nf_t_each_philo);
    return 0;
}
