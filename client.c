/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:42 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/20 12:28:39 by codespace        ###   ########.fr       */
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

// int     ft_encrypt_string(char *msg)
// {
//     unsigned int     iter;
    
// } 

int     main(int argc, char **argv)
{
    t_data      *args;

    args = ft_parse_argc(argc, argv);
    if (args)
        printf("valid input\n");
    else
        printf("invalid input\n");
    free(args);
    return (0);
}