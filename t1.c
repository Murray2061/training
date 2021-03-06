/*
 * t1.c
 *
 *		Demonstrate how to use fopen()/fread()/fwrite() functions.
 *
 *		This program reads in "fread.man" and shows it on display.
 *
 */

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>


int main()
{
	FILE	*infile;
	int		count;
	char	s[80];
	struct stat	fs;

	if (stat("fread.man", &fs) < 0)	{
		system("man fread > fread.man");
	}
	
	infile = fopen("fread.man", "r");
	if (infile == NULL)	{
		perror("fopen");
		exit(1);
	}

	while (1)	{
		count = fread(s, 1, 80, infile);
		fwrite(s, 1, count, stdout);
		if (count < 80)	{
			break;
		}

	}

	return 0;
}
