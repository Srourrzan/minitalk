/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:57:28 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/02 19:12:03 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int     ft_pid_is_numeric(char *src)
{
    size_t  iter;

    iter = 0;
    while(src[iter])
    {
        if (!ft_isdigit(src[iter]))
            return (0);
        iter++;
    }
    return (1);
}

t_data  *ft_parse_args(char **argv, int argc)
{
    t_data      *new;
    size_t      pid_value;

    if (argc != 3 || !argv || !ft_pid_is_numeric(argv[1]))
        return (NULL);
    new = malloc(sizeof(t_data));
    if(!new)
        return (NULL);
    pid_value = ft_atoi(argv[1]);
    new->pid = pid_value;
    new->message = argv[2];
    return(new);
}