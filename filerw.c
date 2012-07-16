#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[80];

    int		bn, i;
    FILE	*rptr;

    if ((rptr = fopen("fread.man", "r")) == NULL) {
        printf("File could not be opened");
    }else {
        while (!feof(rptr)) {
            bn = fread(str, 1, sizeof (str), rptr);
            for (i = 0; i < bn; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] = str[i] - 32;
                }
            }
            fwrite(str, 1, bn, stdout);
        }

    }

    fclose(rptr);

    return 0;
}


