/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:13:37 by rsrour         #+#    #+#             */
/*   Updated: 2025/01/20 19:38:55 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * If the pid is written using digits, the function will return 1
 * otherwise it will return 0.
 */

int lamb = 0;

void    shandle(int signal)
{
    if(signal == SIGUSR1)
        lamb = 1;
    if(signal == SIGUSR2)
        lamb = 0;
}

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

void    send_char(int pid, char character)
{
    int     curr_bit;

    curr_bit = 0;
    printf("char :%c\n", character);
    while (curr_bit < 8)
    {
        lamb = 0;
        printf("current bit = %d\n", curr_bit);
        kill(pid, SIGUSR1);
        while(!lamb);
        curr_bit++;
    }
    
}

void    ft_send_message(t_data *args)
{
    size_t  iter;

    iter = 0;
    while(args->message[iter])
    {
        send_char(args->s_pid, args->message[iter]);
        iter++;
    }    
}
