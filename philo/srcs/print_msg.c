/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:07:24 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:52:47 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(t_philosopher *philo, char *format)
{
	pthread_mutex_lock(&philo->simulation->print_mutex);
	if (read_mutex_int(&philo->simulation->over))
	{
		pthread_mutex_unlock(&philo->simulation->print_mutex);
		return (STOP);
	}
	printf(format, ms_since_program_start(), philo->id + 1);
	pthread_mutex_unlock(&philo->simulation->print_mutex);
	return (CONTINUE);
}

void	print_last_msg(t_philosopher *philo, char *format)
{
	pthread_mutex_lock(&philo->simulation->print_mutex);
	if (read_write_mutex_int(&philo->simulation->over, 1))
	{
		pthread_mutex_unlock(&philo->simulation->print_mutex);
		return ;
	}
	printf(format, ms_since_program_start(), philo->id + 1);
	pthread_mutex_unlock(&philo->simulation->print_mutex);
}
