/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:17:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/02 19:09:06 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct  s_data
{
    int       pid;
    char    *message;
}               t_data;

int     ft_pid_is_numeric(char *src);
t_data  *ft_parse_args(char **argv, int argc);

#endif