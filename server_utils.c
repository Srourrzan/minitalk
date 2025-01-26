/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:46:22 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/26 20:07:08 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message       *init_message(int pid)
{
    t_message       *new;
    
    new = malloc(sizeof(t_message));
    if (!new)
        return (NULL);
    new->message = malloc(sizeof(char *) * BUFFER_SIZE);
    if (!new->message)
    {
        free(new);
        return (NULL);
    }
    ft_bzero(new->message, BUFFER_SIZE);
    new->index = 0;
    new->buffer_size = BUFFER_SIZE;
    new->pid = pid;
    new->buff = 0;
    new->next = NULL;
    new->bit_count = 0;
    new->active = 1;
    return (new);
}