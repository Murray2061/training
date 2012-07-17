#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void set_alarm(int sig)
{
    printf("get alarm signal");
 }

int main()
{
    pid_t pid;

    pid = fork();

    switch (pid) {
    case -1:
      perror("fork error");
      exit(1);
    case 0:
      sleep(5);
      kill(getppid(), SIGALRM);
       exit(0);
}

    printf("Waitting alarm message....\n");
     signal(SIGALRM, set_alarm);
    pause();

   
  return 0;
}
