/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:43:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/03 21:34:27 by rsrour           ###   ########.fr       */
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

t_message       *ft_search_or_create(t_message  **head, int pid)
{
    t_message       *current;
    t_message       *new;

    if (!*head)
    {
        *head = ft_init(pid);
        return (*head);
    }
    current = *head;
    while (current)
    {
        if (current->pid == pid)
            return (current);
        if (!current->next)
        {
            new = init(pid);
            current->next = new;
            return (new);
        }
        current = current->next;
    }
    return (NULL);
}