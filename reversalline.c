#include <stdio.h>
#include <stdlib.h>

int main()
{
    char	str[1024], temp;
    char	*p1, *p2;
    int		bn, i;
    FILE	*rptr;

    if ((rptr = fopen("fread.man", "r")) == NULL) {
        printf("File could not be opened");
        exit(1);
    }else {
        while (!feof(rptr)) {
            fgets(str, sizeof (str), rptr);
            p1 = str;
            p2 = str;
            while (*p2++) {
            }
            p2 -= 2;
            if (*p2 == '\n') {
                p2--;
            }
            while (p2 - p1 > 0) {
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
                p2--;
                p1++;
            }

            fprintf(stdout, "%s", str);
        }
    }


    fclose(rptr);
    return 0;
}


