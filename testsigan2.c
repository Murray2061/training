#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sighup(); /* routines child will call upon sigtrap */
void sigint();
void sigquit();

main() { 
 int pid;
 pid = 1;
 /* get child process */

 if ((pid = fork()) < 0) {
    perror("fork");
    exit(1);
 }

if (pid == 0) { /* child */
   printf("\nI am the new child!\n\n");
       signal(SIGHUP,sighup); /* set function calls */
       signal(SIGINT,sigint);
       signal(SIGQUIT, sigquit);
       printf("\nChild going to loop...\n\n");
      for(;;); /* loop for ever */
 }
else /* parent */
 {  /* pid hold id of child */
   printf("\nPARENT: sending SIGHUP\n\n");
   kill(pid,SIGHUP);
   sleep(3); /* pause for 3 secs */
   printf("\nPARENT: sending SIGINT\n\n");
   kill(pid,SIGINT);
   sleep(3); /* pause for 3 secs */
   printf("\nPARENT: sending SIGQUIT\n\n");
   kill(pid,SIGQUIT);
   sleep(3);
 }
}

void sighup() {
   signal(SIGHUP,sighup); /* reset signal */
   printf("CHILD: I have received a SIGHUP\n");
}

void sigint() {
    signal(SIGINT,sigint); /* reset signal */
    printf("CHILD: I have received a SIGINT\n");
}

void sigquit() {
  printf("My DADDY has Killed me!!!\n");
  exit(0);
}
