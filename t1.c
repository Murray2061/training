/*
 * t3.c
 *
 *  Created on: 2012/6/5
 *      Author: Murray
 */

# include <stdio.h>
# include <stdlib.h>


int main()
{
	FILE	*infile;
	int		count;
	char	s[80];

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
