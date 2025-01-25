/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:01:14 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/25 09:46:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_data
{
	int		s_pid;
	char	*message;
}			t_data;

int     ft_validate_pid(const char *str);
t_data     *ft_parse_argc(int argc, char **argv);
void    ft_send_message(t_data *args);
void    send_char(int pid, char character);

#endif