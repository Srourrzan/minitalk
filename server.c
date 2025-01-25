/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:12:02 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/23 16:13:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * Server Checklist
 * Display its PID
 * Create an endless loop so that the server can receive signals at any time.
 * Receive signals
 * Decrypt signals
 *   For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action
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
void handle(int signal, siginfo_t* info, void *ucontext)
{
    if(signal == SIGUSR1)
    {
        write(2, "1", 1);
        kill(info->si_pid, SIGUSR1);
    }
    if(signal == SIGUSR2)
    {
        write(2, "0", 1);
        kill(info->si_pid, SIGUSR1);

    }
}

int     main()
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_printf("server PID=%d\n", getpid());
    
    while(1)
        pause();
    return (0);
}