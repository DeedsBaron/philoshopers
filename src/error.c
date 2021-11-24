/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:58:58 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/21 16:59:00 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int 	free_all(t_data *info)
{
	int	i;

	i = 0;
	if (info->forks)
	{
		while (i < info->num)
		{
			pthread_mutex_destroy(&(info->forks[i]));
			i++;
		}
		free(info->forks);
	}
	pthread_mutex_destroy(&(info->death));
	pthread_mutex_destroy(&(info->write_data));
	pthread_mutex_destroy(&(info->c_eats));
	if (info->fil)
	{
		free(info->fil);
	}
	return (0);
}

int 	disp_error(char *str)
{
	free_all(get_data_struct());
	write(1, "\033[0;31m", 7);
	write(1, str, ft_strlen(str));
	return (1);
}
