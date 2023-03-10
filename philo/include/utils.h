/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:44:47 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 14:56:15 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_mutex_int
{
	pthread_mutex_t	mutex;
	int				val;
}	t_mutex_int;

void	ft_putstr_fd(char *s, int fd);
int		ft_issize_t(char *str);
size_t	ft_atost(const char *str);
int		ft_isspace(char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);

int		read_mutex_int(t_mutex_int *mutex_int);
void	write_mutex_int(t_mutex_int *mutex_int, int val);
int		read_write_mutex_int(t_mutex_int *mutex_int, int new_val);
void	exit_error(char *msg);

#endif