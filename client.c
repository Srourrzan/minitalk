/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:42 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/24 04:14:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int g_status;
g_status = 0;

void    light_on(int sig)
{
    if(sig == SIGUSR1)
        g_status = 1;
}

// ./client PID "message"
/*
 * CLient Checklist:
 * - Wrtie a program (main) in which the client takes two parameters/arguments
 *      - The PID of the server to which it wants to send the message
 *      - A message
 * - Encrypt the message (I did the encryption via bits)
 * - Send the message to the server (via its PID)
 * - Create a stop condition so that the server knows when it has finished 
 *      receiving the message
*/

// int     ft_encrypt_string(char *msg)
// {
//     unsigned int     iter;
    
// } 

int     main(int argc, char **argv)
{
    struct sigaction sa;
    // sa.sa_flags = 0;
    // sa.sa_handler = light_on;
    // sigemptyset(&sa.sa_mask);
    // sigaction(SIGUSR1, &sa, NULL);
    // sigaction(SIGUSR2, &sa, NULL);
    t_data      *args;
    int bit_count;

    args = ft_parse_argc(argc, argv);
    if (!args)
    {
        ft_putendl_fd("Invalid arguments", 2);
        exit(1);
    }
    int i = 0;
    printf("%d", args->s_pid);
    while(args->message[i])
    {
        bit_count = 8;
        unsigned char temp = args->message[i];
        while(bit_count--)
        {
            g_status = 0;
            temp = args->message[i] >> bit_count;
            if(temp % 2 == 0)
            {
                printf("%d", args->s_pid);
                kill(args->s_pid, SIGUSR2);
            }
            else
            {
                printf("%d", args->s_pid);
                kill(args->s_pid, SIGUSR1);
            }
            while (!g_status);
        }
        i++;
    }
    bit_count = 8;
    while(bit_count--)
    {
        kill(args->s_pid, SIGUSR2);
    }
    
    free(args);
    return (0);
}