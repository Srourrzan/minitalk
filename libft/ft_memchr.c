/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:09:02 by rsrour            #+#    #+#             */
/*   Updated: 2024/09/01 19:09:04 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;

	mem = (unsigned char *)s;
	while (n--)
	{
		if (*mem == (unsigned char)c)
			return (mem);
		mem++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *str = "tutorialspoint.com";
	const char ch = '.';
	char *ret;
	char *ret2;

	ret = memchr(str, ch, strlen(str));
	ret2 = ft_memchr(str, ch, strlen(str));
	printf("Starting after |%c| is - |%s|\n", ch, ret);
	printf("Starting after |%c| is - |%s|\n", ch, ret2);
	return (0);
}*/
