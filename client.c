/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:42 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 20:27:31 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int     ft_encrypt_string(char *msg)
{
    unsigned int     iter;
    
} 

int     main(int argc, char **argv)
{
    printf("argc: %d, argv[0]: %s\n", argc, argv[0]);
    printf("%d\n", SIGUSR2);
    return (0);
}