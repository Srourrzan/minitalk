/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:42 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/30 16:58:56 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_status = 0;

void    light_on(int sig)
{
    if(sig == SIGUSR1)
        g_status = 1;
}

void    cli_sig_handler()
{
    struct sigaction    sa;
    
    sa.sa_handler = &light_on;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        write(1, "Error\n", 6);
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        write(1, "Error\n", 6);
}

int     main(int argc, char **argv)
{
    t_data      *args;
    // int bit_count;

    args = ft_parse_argc(argc, argv);
    if (!args)
    {
        ft_putendl_fd("Invalid arguments", 2);
        exit(1);
    }
    cli_sig_handler();
    // int i = 0;
    // printf("%d", args->s_pid);
    // while(args->message[i])
    // {
    //     bit_count = 8;
    //     unsigned char temp = args->message[i];
    //     while(bit_count--)
    //     {
    //         g_status = 0;
    //         temp = args->message[i] >> bit_count;
    //         if(temp % 2 == 0)
    //         {
    //             printf("%d", args->s_pid);
    //             kill(args->s_pid, SIGUSR2);
    //         }
    //         else
    //         {
    //             printf("%d", args->s_pid);
    //             kill(args->s_pid, SIGUSR1);
    //         }
    //         while (!g_status);
    //     }
    //     i++;
    // }
    // bit_count = 8;
    // while(bit_count--)
    // {
    //     kill(args->s_pid, SIGUSR2);
    // }
    
    // free(args);
    return (0);
}