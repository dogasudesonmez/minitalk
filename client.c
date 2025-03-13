/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:12:31 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/09 01:30:13 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"
#include <unistd.h>
#include "./printf/ft_printf.h"

static int	g_ack_received = 0;

void	ack_handler(int signo)
{
	(void)signo;
	g_ack_received = 1;
}

void	send_signal_to_server(int server_pid, int signal)
{
	kill(server_pid, signal);
}

void	send_char(int server_pid, char c)
{
	struct sigaction	sa;
	int					i;

	i = 0;
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (i < 8)
	{
		g_ack_received = 0;
		if (c & (1 << i))
			send_signal_to_server(server_pid, SIGUSR1);
		else
			send_signal_to_server(server_pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		i++;
	}
}

void	send_message(int server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(server_pid, message);
	return (0);
}
