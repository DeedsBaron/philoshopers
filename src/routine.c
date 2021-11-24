/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:00:42 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/21 17:01:09 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	food_on_table(t_philo *fil)
{
	if (get_data_struct()->times_of_eat == 0)
		return (1);
	else if (fil->num_of_eats == get_data_struct()->times_of_eat)
		return (0);
	return (1);
}

void	*monitor(void *arg)
{
	t_philo	*fil;

	fil = (t_philo *)arg;
	while (food_on_table(fil))
	{
		pthread_mutex_lock(&(get_data_struct()->death));
		if (!fil->is_eating && get_time() > fil->death)
		{
			display_message(fil, DEAD);
			get_data_struct()->dead_flag = 1;
			pthread_mutex_lock(&(get_data_struct()->write_data));
			pthread_mutex_unlock(&(get_data_struct()->death));
			return (NULL);
		}
		pthread_mutex_unlock(&(get_data_struct()->death));
	}
	pthread_mutex_unlock(&(get_data_struct()->death));
	return (NULL);
}

void	*thug_philo_life(void *arg)
{
	t_philo		*fil;
	pthread_t	mon;

	fil = (t_philo *)arg;
	fil->last_eat = get_time();
	fil->death = fil->last_eat + get_data_struct()->die_time;
	if (pthread_create(&mon, NULL, &monitor, arg) != 0)
		return (NULL);
	pthread_detach(mon);
	while (food_on_table(fil))
	{
		grab_forks(fil);
		eat(fil);
		put_down_forks(fil);
		sleepy(fil);
		think(fil);
	}
	pthread_mutex_lock(&(get_data_struct()->c_eats));
	get_data_struct()->well_fed_flag -= 1;
	pthread_mutex_unlock(&(get_data_struct()->c_eats));
	return (NULL);
}
