/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:16:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/04 20:18:09 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_process_message(t_message **head, t_message **curr, siginfo_t *siginfo)
{
    if (!(*curr)->active)
        return ;
    if ((*curr)->index == (*curr)->buffer_size - 1)
    {
        (*curr)->message = ft_expand_message_space((*curr)->message, 
                            (*curr)->buffer_size + BUFFER_SIZE, (curr)->buffer_size);
        if(!(*curr)->message)
        {
            free((*curr)->message);
            free(curr);
            return;
        }
    }    
}

void    ft_receive_message(int signal, siginfo_t *siginfo, void *context)
{
    static t_message    *head;
    t_message           *curr;

    (void)context;
    if (head == NULL)
        head = ft_init(siginfo->si_pid);
    curr = ft_search_or_create(&head, siginfo->si_pid);
    if (!curr || curr->active)
        return ;
    if (signal == SIGUSR1)
        curr->buff |= 1;
    curr->bit_count++;
    if (curr->bit_count == 8)
    {
        ft_process_message(&haed, &curr, siginfo);
    }
}

void    ft_server_sig_handler()
{
    struct sigaction    sa;
    
    sa.sa_sigaction = &ft_receive_message;
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