#include <stdio.h>
# include <stdlib.h>

int main()
{
    char	str[80];
    int		bn;
    FILE	*rptr;

    if ((rptr = fopen("fread.man", "r")) == NULL) {
        perror("fopen");
		exit(1);
    }

	while (!feof(rptr)) {
           bn = fread(str, 1, sizeof (str), rptr);
//		   printf("bn = %d\n", bn);
           fwrite(str, 1, bn, stdout);
	}

    fclose(rptr);

	return 0;
}


