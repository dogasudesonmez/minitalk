#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signalnum)
{
    static int bit_index = 0;
    static int current_char = 0;

    if(signalnum == SIGUSR1)
        current_char |= (1 << bit_index);
    bit_index++;

    if(bit_index == 8)
    {
        if(current_char == '\0')
            write(1,"\n",1);
        else
            write(1, &current_char,1);
        bit_index = 0;
        current_char = 0;
    }
}
#include <stdio.h>
int main()
{
    int server_pid;
    server_pid = getpid();

    printf("Server PID: %d\n", server_pid);

    signal(SIGUSR1,signal_handler);
    signal(SIGUSR2,signal_handler);

    while (1)
    {
        pause();
    }
        
   return(0);
}