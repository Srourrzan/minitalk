/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:12:02 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/16 20:16:34 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * SIGUSR1 or SIGUSR2 from goku
 *  establish a handler
 *  for these signals
 *  if SIGUSR1 -> bit 1
 *  if SIGUSR2 -> bit 0
 *  ALLOWED func: write, ft_printf, signal, sigemptyset, sigaddset
 *  kill, getpid, malloc, free, pause, sleep, usleep, exit
 */

// the server will have signal handler that will work when it recieves a signal
// from the client, so it should handle the text recieved from the client.

/*
 * By setting a signal handler for the SIGINT and SIGTERM signals, 
 * we can ensure that the program will exit cleanly when it is terminated, 
 * rather than leaving resources in an undefined state.
*/

void    handler(int signo, siginfo_t *info, void *more_info)
{
    (void)more_info;
    
}

int     main()
{
    printf("server PID=%d\n", getpid());

    ft_signal(SIGUSR1, handler, 1);
    ft_signal(SIGUSR2, handler, 1);
    
    while(1)
        pause();
    return (0);
}