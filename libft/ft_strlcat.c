/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:13:10 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:41:46 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	iter;

	destlen = ft_strlen(dst);
	if (size <= destlen)
		return (size + ft_strlen(src));
	iter = 0;
	while (src[iter] != '\0' && destlen + iter < size - 1)
	{
		dst[destlen + iter] = src[iter];
		iter++;
	}
	dst[destlen + iter] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[iter]));
}
/*
int	main(void)
{
	const char	*src = "Srour";
	char	dest[11];
		//dest[0] = '\0';
		dest[11] = 'a';
	size_t	cat_size = 15;

	printf("concatinating %s with %s\n", dest, src);
	printf("%ld", ft_strlcat(dest, "lorem ipsum", cat_size));
	printf("\n dest:%s\n", dest);

	return (0);
}*/
