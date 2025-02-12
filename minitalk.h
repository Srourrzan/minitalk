/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:17:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/09 21:06:02 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_data
{
	int		pid;
	char	*message;
}			t_data;

typedef struct s_message
{
    int             pid;
    int             active;
    size_t          index;
    int             bit_count;
    char            *message;
    size_t          buffer_size;
    unsigned char   buff;
    struct s_message    *next;
}               t_message;

int			ft_pid_is_numeric(char *src);
t_data		*ft_parse_args(char **argv, int argc);
void		ft_client_sig_handler(void);
void		ft_g_set(int signal);
void        ft_server_sig_handler();
t_message       *ft_init(int pid);
t_message       *ft_search_or_create(t_message  **head, int pid);
void        ft_process_message(t_message **head, t_message **curr, siginfo_t *siginfo);
void        ft_receive_message(int signal, siginfo_t *siginfo, void *context);
void    *ft_expand_message_space(void *message, size_t size, size_t old_size);//, size_t old_size);
void        *ft_remove_message(t_message **head, int pid);
void        ft_send_message(int pid, char *str);
void	    ft_send_bit(int pid, char bit);

#endif