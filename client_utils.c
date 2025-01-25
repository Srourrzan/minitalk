/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:13:37 by codespace         #+#    #+#             */
/*   Updated: 2025/01/25 09:45:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * If the pid is written using digits, the function will return 1
 * otherwise it will return 0.
 */

static int  signal_acknowledged = 0;

int     ft_validate_pid(const char *str)
{
    size_t  iter;
    int     valid;

    iter = 0;
    valid = 0;
    while(str[iter])
    {
        if (ft_isdigit(str[iter]))
            valid = 1;
        else
            return (0);
        iter++;
    }
    return (valid);
}

t_data     *ft_parse_argc(int argc, char **argv)
{
    t_data  *args;
    int     numeric_pid;

    args = malloc(sizeof(t_data));
    if (!args)
        return(NULL);
    if(argc != 3 || !ft_validate_pid(argv[1]))
    {
        free(args);
        return (NULL);
    }
    numeric_pid = ft_atoi(argv[1]);
    args->s_pid = numeric_pid;
    args->message = argv[2];
    return (args);
}

int     ft_send_message(t_data args)
{
    while (!signal_acknowledged)
    {
        
    }
    
}