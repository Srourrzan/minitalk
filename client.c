/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:42 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/20 20:33:53 by rsrour           ###   ########.fr       */
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

int     main(int argc, char **argv)
{
    t_data      *args;

    args = ft_parse_argc(argc, argv);
    if (!args)
    {
        ft_putendl_fd("Invalid arguments", 2);
        exit(1);
    }
    ft_send_message(args);
    free(args);
    return (0);
}