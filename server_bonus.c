/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:12:04 by dsonmez           #+#    #+#             */
/*   Updated: 2025/02/09 01:29:54 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "./printf/ft_printf.h"

void	signal_handler(int signalnum, siginfo_t *info, void *context)
{
	static int	bit_index = 0;
	static int	current_char = 0;

	(void)context;
	if (signalnum == SIGUSR1)
		current_char |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	write(1, "Server PID: \n", 13);
	ft_printf("%d", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
