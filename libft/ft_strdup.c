/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:09:23 by rsrour            #+#    #+#             */
/*   Updated: 2025/01/19 18:41:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"


char	*ft_strdup(const char *s1)
{
	char	*dup_str;
	size_t	len;
	int		iter;

	iter = 0;
	len = ft_strlen(s1);
	dup_str = (char *)malloc((len + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	while (s1[iter] != '\0')
	{
		dup_str[iter] = s1[iter];
		iter++;
	}
	dup_str[iter] = '\0';
	return (dup_str);
}

/*
int	main(void)
{
	char	*name = "Razan Srour";

	printf("The duplicate of %s is %s\n", name, ft_strdup(name));
	return (0);
}*/
