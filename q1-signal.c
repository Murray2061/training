/*
 *
 *	This is a signal() demo.
 *
 */

# include <signal.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>


void mysigint(int);


int main()
{
    struct timeval tv0, tv1;


	signal(SIGINT, mysigint);
	signal(SIGQUIT, mysigint);

	while (1)	{
	    time_t	ds;
	    suseconds_t	dus;

		puts("I fall asleep.  Press ^C to wake me up.");
		gettimeofday(&tv0, NULL);
		pause();
		gettimeofday(&tv1, NULL);

		ds = tv1.tv_sec - tv0.tv_sec;
		dus = (tv1.tv_usec - tv0.tv_usec)/1000;
		if (dus < 0)	{
			ds--;
			dus += 1000;
		}

		printf("\nAwakened after %ld.%03ld seconds.\n",
			ds, dus);
	}

    return 0;
}


/*
 *
 *	This is an empty handler; however, it can do something as well.
 *
 */
void mysigint(int sig)
{}
