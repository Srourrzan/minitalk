/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:01:14 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/30 16:59:24 by rsrour           ###   ########.fr       */
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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

typedef struct s_data
{
	int		s_pid;
	char	*message;
}			t_data;

typedef	struct s_message
{
	int						pid;
	unsigned	char		buff;
	size_t					index;
	struct s_message		*next;
	int						active;
	char					*message;
	int						bit_count;
	size_t					buffer_size;
}							t_message;


int     		ft_validate_pid(const char *str);
t_data     		*ft_parse_argc(int argc, char **argv);
void    		ft_send_message(t_data *args);
void    		send_char(int pid, char character);
void		    sig_handler();
void    		cli_sig_handler();
t_message       *init_message(int pid);

#endif