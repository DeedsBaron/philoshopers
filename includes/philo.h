/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:31:23 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/16 17:31:26 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "errors.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# define THINKING 1
# define EATING 2
# define SLEEPING 3
# define FORK 4
# define DEAD 5
# define DROP_FORK 6

typedef struct s_philo
{
	int			pos;
	int			is_eating;
	int			num_of_eats;
	int			left;
	int			right;
	uint64_t	last_eat;
	uint64_t	death;
	pthread_t	thread;
}t_philo;

typedef struct s_data
{
	int				num;
	int				dead_flag;
	int				well_fed_flag;
	int				times_of_eat;
	uint64_t		start;
	uint64_t		die_time;
	uint64_t		sleep_time;
	uint64_t		eat_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	write_data;
	pthread_mutex_t	c_eats;
	t_philo			*fil;
}t_data;
//display_message
void		display_message(t_philo *fil, int type);
//error
int			disp_error(char *str);
int			free_all(t_data *info);
//ft_atoi
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
//ft_putnbr
void		ft_putnbr(int nb);
//main
t_data		*get_data_struct(void);
//parse
int			parse_info(char *argv[], t_data *info);
//routine
int			food_on_table(t_philo *fil);
void		*monitor(void *arg);
void		*thug_philo_life(void *arg);
//thug_life
void		grab_forks(t_philo *fil);
void		eat(t_philo *fil);
void		sleepy(t_philo *fil);
void		put_down_forks(t_philo *fil);
void		think(t_philo *fil);
//time
void		accurate_usleep(uint64_t time);
uint64_t	get_time(void);
#endif
