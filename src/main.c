/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:20 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/21 16:53:21 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*get_data_struct(void)
{
	static t_data	info;

	return (&info);
}

void	init_data(t_data *info, int i)
{
	info->fil[i].pos = i;
	info->fil[i].last_eat = 0;
	info->fil[i].is_eating = 0;
	info->fil[i].death = 0;
	info->fil[i].num_of_eats = 0;
	if (i % 2 == 0)
	{
		info->fil[i].left = i;
		info->fil[i].right = (i + 1) % info->num;
	}
	else
	{
		info->fil[i].right = i;
		info->fil[i].left = (i + 1) % info->num;
	}
}

int	create_philos(t_data *info)
{
	int	i;

	i = 0;
	info->start = get_time();
	info->fil = (t_philo *)malloc(sizeof(t_philo) * info->num);
	if (info->fil == NULL)
		return (disp_error(MAL_OC));
	while (i < info->num)
	{
		init_data(info, i);
		if (pthread_create(&info->fil[i].thread, NULL, &thug_philo_life,
				   (void *)&(info->fil[i])) != 0)
			return (disp_error(P_CREATE));
		i++;
	}
	return (0);
}

int	create_mutexed_forks(t_data *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num);
	if (info->forks == NULL)
		return (disp_error(MAL_OC));
	while (i < info->num)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL) != 0)
			return (disp_error(MUT_IN));
		i++;
	}
	if (pthread_mutex_init(&(info->write_data), NULL) != 0)
		return (disp_error(MUT_IN));
	if (pthread_mutex_init(&(info->c_eats), NULL) != 0)
		return (disp_error(MUT_IN));
	if (pthread_mutex_init(&(info->death), NULL) != 0)
		return (disp_error(MUT_IN));
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (disp_error(N_ARG));
	if (parse_info(argv, get_data_struct()) == 1)
		return (1);
	if (create_mutexed_forks(get_data_struct()) == 1)
		return (1);
	if (create_philos(get_data_struct()) == 1)
		return (1);
	while (1)
	{
		if (get_data_struct()->well_fed_flag == 0
			|| get_data_struct()->dead_flag == 1)
			return (free_all(get_data_struct()));
	}
}
