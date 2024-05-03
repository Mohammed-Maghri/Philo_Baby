 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:16:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/04/25 16:55:18 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>


typedef struct this_str
{
	int			index;
	int			minis;
	long long	store;
}	t_this;

typedef struct initailize_philo
{
	long long		last_meal_time;
	int				id;
	int				left_one;
	int				right_one;
	int				whole_philos;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				if_dead;
	int				nmp;
	pthread_mutex_t	*sec_var;
	pthread_mutex_t	*monitor;
	pthread_mutex_t	*lock_var;
	pthread_mutex_t	*print_not;
	pthread_mutex_t	*onlyone;
	pthread_mutex_t	*stop;
	pthread_mutex_t	*lock_each_time;
	pthread_mutex_t	*thisthread;
	pthread_mutex_t	*lock_it_up;
	pthread_mutex_t	*lock_him;
	pthread_mutex_t	*this;
	int				time;
	int				lock_time;
	long long		start_time;
	long long		each_time;
	int				nf_t_each_philo;
	int				flag;
}	t_ini;

typedef struct in_stru
{
	int				nf_t_each_philo;
	int				nmp;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_ini			*philo;
	pthread_mutex_t	stop;
	pthread_mutex_t	print_not;
	pthread_mutex_t	monitor;
	pthread_mutex_t	lock_var[200];
	pthread_mutex_t	only_one;
	pthread_mutex_t	lock_each_time;
	pthread_mutex_t	thisthread;
	pthread_mutex_t	lock_it_up;
	pthread_mutex_t	lock_him;
	pthread_mutex_t	this;
}	t_in_str;

typedef struct in_tial
{
	int		index;
	int		increment ;
	int		flag;
}	t_initial;

void		increment_this(t_ini *point, int *flag, int *increment);
t_ini		*start_dining(t_in_str *this);
void		*start_philos(void *args);
int			function_add(t_ini *point, int index, int flag, int increment);
void		*start_philos(void *args);
int			function_create_many_philos(t_ini *point, t_in_str *more);
void		function_sleep(long long in_milisecond);
long long	fu(void);
int			this_end(t_in_str *this, int *array, int argc);
int			fill_shit(t_in_str *this, int *array, int argc);
int			*return_to_array(char **argv);
int			check_if(char **all_this, int argc);
void		f_p(char *string, int id, long long pass, t_ini *waa);
void		function_t(t_ini *waa);
int			le_count(char *string);
int			number_converter(char *string);
void		*thread_function(void	*arg);
int			not_valid(char string, int num);
int			loop_on_all(char *string, int num);
int			check_valid(char *string);
void		function_sleep(long long in_milisecond);

#endif