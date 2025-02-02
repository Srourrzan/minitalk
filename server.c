/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:16:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/02 20:13:29 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_server_sig_handler()
{
    struct sigaction    sa;
    
    sa.sa_sigaction = &receive_message;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        ft_putendl_fd("Error", 2);
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        ft_putendl_fd("Error", 2);
}

int     main()
{
    pid_t   pid;

    pid = getpid();
    ft_printf("Server PID: %i\n", pid);
    
}