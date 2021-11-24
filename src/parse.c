/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:01:52 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/21 17:01:54 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse_info(char *argv[], t_data *info)
{
	info->dead_flag = 0;
	info->start = 0;
	info->forks = NULL;
	info->fil = NULL;
	info->num = ft_atoi(argv[1]);
	info->well_fed_flag = info->num;
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
	{
		info->times_of_eat = ft_atoi(argv[5]);
		if (info->times_of_eat == 0)
			return (disp_error(ALL_WELL_FED));
	}
	else
		info->times_of_eat = 0;
	if (info->num > 200 || info->die_time < 60
		|| info->sleep_time < 60 || info->eat_time < 60)
		return (disp_error(VAL_ARG));
	else
		return (0);
}
