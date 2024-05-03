/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:58:34 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/03 11:38:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <signal.h>

typedef struct this_str
{
	int			index;
	int			minis;
	long long	store;
	int			*array;
}	t_this;

typedef struct not_this
{
	int			porcess[200];
	int			outside;
	int			id;
	int			index;
	int			each_philo;
	int			time_die;
	int			number_philos;
	int			how_many_time;
	int			time_sleep;
	int			time_eat;
	int			flag;
	long long	last_meal_time;
	long long	start_time;
	long long	start_copy;
	pthread_t	initial;
	sem_t		*protec;
	sem_t		*var;
	sem_t		*print;
	sem_t		*app_it;
	sem_t		*check;
	pthread_t	*monitor;

}	t_not;

void		*start_philos(void *args);
void		f_p(char *string, int id, long long pass, sem_t *var);
long long	fu(void);
void		function_sleep(long long in_milisecond);
void		phill_vars_nedded(t_not *phill, int *array);
int			make_bonus(t_not *check);
int			check_if(char **all_this, int argc);
int			*return_to_array(char **argv);
int			not_valid(char string, int num);
int			le_count(char *string);
int			not_number(char string);
int			there_is_nothing(char *string);
int			loop_on_all(char *string, int num);
int			check_if_this_valid(char *string);
int			number_converter(char *string);
int			check_over_flow(long long number, int minis);
int			not_valid(char string, int num);
int			check_valid(char *string);
int			number_converter(char *string);
int			check_over_flow(long long number, int minis);
int			check_if_this_valid(char *string);
#endif