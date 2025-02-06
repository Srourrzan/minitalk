/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:45:31 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/06 20:13:17 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal;

void	ft_g_set(int signal)
{
	if (signal == SIGUSR1)
		g_signal = 1;
}

void	ft_send_bit(int pid, char bit)
{
	unsigned char	temp;
	int				i_bit;

	i_bit = 8;
	temp = (unsigned char)bit;
	while (i_bit--)
	{
		g_signal = 0;
		temp = (bit >> i_bit);
		if (temp % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(write(2, "Error\n", 6));
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(write(2, "Error\n", 6));
		}
		while (!g_signal)
			;
	}
}

void	ft_send_message(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_send_bit(pid, str[i]);
		i++;
	}
	ft_send_bit(pid, '\0');
}

void	ft_client_sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_g_set;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(2, "Error\n", 6);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(2, "Error\n", 6);
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
	if (argv[2][0] == '\0')
		ft_send_message(t_args->pid, "\0");
	ft_send_message(t_args->pid, t_args->message);
	return (0);
}
