/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thug_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:51:32 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/21 15:51:33 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	grab_forks(t_philo *fil)
{
	pthread_mutex_lock(&(get_data_struct()->forks[fil->left]));
	display_message(fil, FORK);
	pthread_mutex_lock(&(get_data_struct()->forks[fil->right]));
	display_message(fil, FORK);
}

void	eat(t_philo *fil)
{
	fil->is_eating = 1;
	fil->last_eat = get_time();
	fil->death = fil->last_eat + get_data_struct()->die_time;
	display_message(fil, EATING);
	accurate_usleep(get_data_struct()->eat_time);
	fil->num_of_eats++;
	fil->is_eating = 0;
}

void	sleepy(t_philo *fil)
{
	display_message(fil, SLEEPING);
	accurate_usleep(get_data_struct()->sleep_time);
}

void	put_down_forks(t_philo *fil)
{
	pthread_mutex_unlock(&(get_data_struct()->forks[fil->left]));
	pthread_mutex_unlock(&(get_data_struct()->forks[fil->right]));
}

void	think(t_philo *fil)
{
	display_message(fil, THINKING);
}
