/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:13:37 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 16:24:53 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_validate_pid(const char *str)
{
	size_t	iter;
	int		valid;

	iter = 0;
	valid = 0;
	while (str[iter])
	{
		if (ft_isdigit(str[iter]))
			valid = 1;
		else
			return (0);
		iter++;
	}
	return (valid);
}

t_data	*ft_parse_argc(int argc, char **argv)
{
	t_data	*args;
	int		numeric_pid;

	args = malloc(sizeof(t_data));
	if (!args)
		return (NULL);
	if (argc != 3 || !ft_validate_pid(argv[1]))
	{
		free(args);
		return (NULL);
	}
	numeric_pid = ft_atoi(argv[1]);
	if (numeric_pid < 0)
	{
		free(args);
		return (NULL);
	}
	args->s_pid = numeric_pid;
	args->message = argv[2];
	return (args);
}
