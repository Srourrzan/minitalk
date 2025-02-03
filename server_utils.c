/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:43:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/03 21:01:35 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message       *ft_init(int pid)
{
    t_message   *new;
    
    new = malloc(sizeof(t_message));
    if (!new)
        return (NULL);
    new->message = malloc(BUFFER_SIZE);
    if (!new->message)
    {
        free(new);
        return (NULL);
    }
    new->index = 0;
    new->buffer_size = BUFFER_SIZE;
    new->pid = pid;
    new->buff = 0;
    new->next = NULL;
    new->bit_count = 0;
    new->active = 1;
    return (new);
}