/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:45:31 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/02 19:07:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int     main(int argc, char **argv)
{
    t_data      *t_args;
    
    t_args = ft_parse_args(argv, argc);
    if (!t_args)
    {
        ft_putendl_fd("Invalid client arguments", 2);
        exit(1);
    }
    printf("pid = %d, message = %s\n", t_args->pid, t_args->message);
    return (0);
}