/* fgets example */
#include <stdio.h>
#include <ctype.h>
# include <stdlib.h>

int main()
{
    FILE *infile;
    char s[100];
    char *p1, *p2, p3, *ind;

    infile = fopen("./123" , "r");

    /*
     *
     *	perror() itself merely prints the error message.
     *	We have to call exit() explicitly when something goes wrong.
     *						--Murray
     *
     */
    if (infile == NULL) {
	perror("fopen");
	exit(1);
    }

    while (fgets(s, sizeof s, infile) != NULL) {
	p1 = s, p2 = s;
	while (*p1) {
	    while(*p2 && !isspace(*p2)) {
		p2++;
	    }
	    if (*p2) {
	    	ind = p2 + 1;
	    }
	    p2--;
	    while (p2 - p1 > 0) {
		    p3 = *p2;
		    *p2 = *p1;
		    *p1 = p3;
  		    p1++, p2--;
	    }
	    p1 = ind, p2 = ind;
	}
	fprintf(stdout, "%s", s);
    }
    fclose(infile);

   return 0;
}
