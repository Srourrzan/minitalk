/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:45:31 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/02 20:17:35 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal;

void	ft_g_set(int signal)
{
	if (signal == SIGUSR1)
		g_signal = 1;
}

void	ft_client_sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_g_set;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(write(2, "Error\n", 6));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(write(2, "Error\n", 6));
}

int	main(int argc, char **argv)
{
	t_data	*t_args;

	t_args = ft_parse_args(argv, argc);
	if (!t_args)
	{
		ft_putendl_fd("Invalid client arguments", 2);
		exit(1);
	}
	printf("pid = %d, message = %s\n", t_args->pid, t_args->message);
	ft_client_sig_handler();
	return (0);
}
