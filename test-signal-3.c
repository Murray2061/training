# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>


void mysighand(int);	/* routines child will call upon sigtrap */


int main()
{
    sigset_t	sigset;
    int		pid;

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

	printf("DEBUG! pid = %d\n", pid);
	
	if (pid)	{	//	parent
		sigprocmask(SIG_UNBLOCK, &sigset, NULL);

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
		signal(SIGHUP, mysighand); /* set function calls */
		signal(SIGINT, mysighand);
		signal(SIGQUIT, mysighand);
		sigprocmask(SIG_UNBLOCK, &sigset, NULL);

		while (1)	{
			puts("Child is awakened.");
			pause();
		}
	}

    return 0;
}


void mysighand(int sig)	{
    switch (sig)	{
	case SIGINT:
		printf("CHILD: I have received a SIGINT\n");
	break;

	case SIGHUP:
		printf("CHILD: I have received a SIGHUP\n");
	break;

	case SIGQUIT:
		printf("My DADDY has Killed me!!!\n");
		exit(0);
	break;
    }
}
