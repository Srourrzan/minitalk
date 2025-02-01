/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:12:02 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/01 16:53:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle(int signal, siginfo_t *sig_info, void *context)
{
    static t_message    *head;
    t_message           *curr;
    
    if(signal == SIGUSR1)
    {
        write(2, "1", 1);
        kill(sig_info->si_pid, SIGUSR1);
    }
    if(signal == SIGUSR2)
    {
        write(2, "0", 1);
        kill(sig_info->si_pid, SIGUSR2);

	// t_message           *current;
	(void)context;
	if (head == NULL)
		head = init_message(sig_info->si_pid);
	if (signal == SIGUSR1)
	{
		write(2, "1", 1);
		kill(sig_info->si_pid, SIGUSR1);
	}
	if (signal == SIGUSR2)
	{
		write(2, "0", 1);
		kill(sig_info->si_pid, SIGUSR1);
	}
	free(head);
}
}

void	sig_handler()
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error\n");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("server PID=%d\n", pid);
	sig_handler();
	while (1)
		pause();
	return (0);
}
