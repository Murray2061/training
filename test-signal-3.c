# define _POSIX_SOURCE

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>


void sighup(int);	/* routines child will call upon sigtrap */
void sigint(int);
void sigquit(int);


int main()
{
	sigset_t	sigset;
	int			pid;

		sigemptyset(&sigset);
		sigaddset(&sigset, SIGHUP);
		sigaddset(&sigset, SIGINT);
		sigaddset(&sigset, SIGQUIT);
		
		if (sigprocmask(SIG_BLOCK, &sigset, NULL) < 0)	{
			perror("sigprocmask");
			exit(1);
		}

		if ((pid = fork()) < 0)	{
			perror("fork");
			exit(1);
		}
		
		if (pid)	{	//	parent
			printf("\nPARENT: sending SIGHUP\n\n");
			kill(pid, SIGHUP);
			sleep(3); /* pause for 3 secs */

			printf("\nPARENT: sending SIGINT\n\n");
			kill(pid, SIGINT);
			sleep(3); /* pause for 3 secs */

			printf("\nPARENT: sending SIGQUIT\n\n");
			kill(pid, SIGQUIT);
		} else	{		//	child
			puts("I'm the new child!");
			signal(SIGHUP, sighup); /* set function calls */
			signal(SIGINT, sigint);
			signal(SIGQUIT, sigquit);
			sigprocmask(SIG_UNBLOCK, &sigset, NULL);

			while (1)	{
				puts("Child is awakened.");
				pause();
			}
		}

	return 0;
}


void sighup(int unused) {
	printf("CHILD: I have received a SIGHUP\n");
}


void sigint(int unused) {
	printf("CHILD: I have received a SIGINT\n");
}


void sigquit(int unused) {
	printf("My DADDY has Killed me!!!\n");
	exit(0);
}
