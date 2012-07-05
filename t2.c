#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int main()
{    
    char s[50];
    int infile;
    int outfile;
    int count;
    

    infile = open("./123", O_RDONLY);
    outfile = open("./cp3", O_WRONLY|O_CREAT|O_TRUNC,0644);
    if (infile < 0)    {	
	perror("open");
	exit(1);
    }
   
    while (1)	{
	char *s1;

        count = read(infile, s, sizeof s);
        if (count <= 0) {
	    break;
    	}

	for (s1 = s; s1 - s < count; s1++)	{
		if (*s1 == ' ')
			*s1 = '-';
	}

	write(outfile, s, count);
    }
    close(outfile);
    return 0;
}
    
