/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:43:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/18 10:23:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	*ft_init(int pid)
{
	t_message	*new;

	new = malloc(sizeof(t_message));
	if (!new)
		return (NULL);
	new->message = malloc(BUFFER_SIZE);
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

t_message	*ft_search_or_create(t_message **head, int pid)
{
	t_message	*current;
	t_message	*new;

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
			new = ft_init(pid);
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}

static void	*ftr_memcpy(void *dst, const void *src, size_t size,
		size_t old_size)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dst || !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (i < old_size && i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_expand_message_space(void *message, size_t size, size_t old_size)
		//, size_t old_size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_bzero(new_ptr, size);
	new_ptr = ftr_memcpy(new_ptr, message, size, old_size);
	free(message);
	return (new_ptr);
}

void	*ft_remove_message(t_message **head, int pid)
{
	t_message	*curr;
	t_message	*prev;

	if (!head || !*head)
		return (NULL);
	curr = *head;
	prev = NULL;
	while (curr)
	{
		if (curr->pid == pid)
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->message);
			free(curr);
			return (NULL);
		}
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}
