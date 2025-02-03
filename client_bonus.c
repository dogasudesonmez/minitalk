#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <unistd.h>

void send_char(int server_pid, char c)
{
	int i;

	i = 0;
    while (i < 8) {
        if (c & (1 << i))
			kill(server_pid, SIGUSR1);
        else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
    }
}

void message_put(int server_pid,char *str)
{
    int i ;

    i = 0;
    while(str[i] != '\0')
    {
        send_char(server_pid,str[i]);
        i++;
    }
	send_char(server_pid, '\0');
}

int main(int ac, char **av)
{
	if((ac != 3))
		return(1);
		
	int server_pid = ft_atoi(av[1]);
	char *message = av[2];
	
    message_put(server_pid,message);
}