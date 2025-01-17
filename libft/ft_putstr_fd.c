/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:22:09 by rsrour            #+#    #+#             */
/*   Updated: 2024/09/16 17:58:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	iter;

	iter = 0;
	if (!s || !fd)
		return ;
	while (s[iter] != '\0')
	{
		write(fd, &s[iter], 1);
		iter++;
	}
}
/*
int	main(void)
{
	char	*name = "Razan Srour";

	ft_putstr_fd(name, 1);

	return (0);
}*/
