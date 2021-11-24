/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:58 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/21 16:53:59 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static char	*get_message(int type)
{
	if (type == EATING)
		return (" is eating\n");
	else if (type == SLEEPING)
		return (" is sleeping\n");
	else if (type == FORK)
		return (" has taken a fork\n");
	else if (type == THINKING)
		return (" is thinking\n");
	else if (type == DEAD)
		return (" died\n");
	return (NULL);
}

void	display_message(t_philo *fil, int type)
{
	pthread_mutex_lock(&(get_data_struct()->write_data));
	ft_putnbr(get_time() - get_data_struct()->start);
	write(1, "\t", 1);
	ft_putnbr(fil->pos + 1);
	if (type == DEAD)
		write(1, "\033[0;31m", 7);
	if (type == EATING)
		write(1, "\033[0;32m", 7);
	if (type == THINKING)
		write(1, "\033[0;35m", 7);
	if (type == FORK)
		write(1, "\033[0;34m", 7);
	if (type == SLEEPING)
		write(1, "\033[0;36m", 7);
	write(1, get_message(type), ft_strlen(get_message(type)));
	write(1, "\033[0;37m", 7);
	pthread_mutex_unlock(&(get_data_struct()->write_data));
}
