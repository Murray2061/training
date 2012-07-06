/* fgets example */
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *infile;
    char s[100];
    char *p1, *p2, p3, *ind;

    infile = fopen ("./123" , "r");
    if (infile == NULL) {
	perror("Error");
    }
    while (fgets(s, 100, infile) != NULL) {
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
	    p1 =ind, p2 =ind;
	}
	fprintf(stdout, "%s", s);
    }
    fclose (infile);

   return 0;
}