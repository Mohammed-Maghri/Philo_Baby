#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct this_str {
    int index;
    int minis;
    long long store;
} t_this ;

typedef struct initailize_philo {
    int last_meal_time; // update_with_the function Get_time_of_Day ;
    int id;
    pthread_mutex_t lock_var;
    
} t_ini ;

typedef struct in_stru {
    int nf_t_each_philo;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    t_ini   *philo;
} in_str ;

int     le_count(char *string);
int     number_converter(char *string);
void*   thread_function(void* arg);
int     not_valid(char string, int num);
int     loop_on_all(char *string, int num);
int     check_valid(char *string);

#endif