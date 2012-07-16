#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char	str[1024], temp;
    char	*p1, *p2, *pend, *pnow;
    FILE	*rptr;

    if ((rptr = fopen("fread.man", "r")) == NULL) {
        printf("File could not be opened");
        exit(1);
    }else {
        while (!feof(rptr)) {
            fgets(str, sizeof (str), rptr);
            pnow = str;
            pend = str;
            p1 = str;
            p2 = str;
            while (*pend++) {
            }
            pend -= 2;
            if (*pend == '\n') {
                pend--;
            }
            while (pend - p1 >= 0) {
                if (isspace(*pnow)) {
                    while (isspace(*pnow++)) {
                    }
                    pnow--;
                    if (*pnow == '\0') {
                        pnow--;
                    }
                    if (*pnow == '\n') {
                        pnow--;
                    }
                    if (isspace(*pnow)) {
                        pnow++;
                    }
                    p2 = pnow;
                    p1 = p2;
                }
                if (*pnow == '\n') {
                    break;
                }
                while (!isspace(*p2++)) {
                }
                p2--;
                if (*p2 == '\n') {
                    p2--;
                }
                pnow = p2 + 1;
                while (p2 - p1 > 0) {
                    temp = *p1;
                    *p1 = *p2;
                    *p2 = temp;
                    p2--;
                    p1++;
                }
                if (*pnow == '\0' || *pnow == '\n') {
                    break;
                }
                p1 = pnow;
                p2 = pnow;
            }
            fprintf(stdout, "%s", str);
        }
    }


    fclose(rptr);
    return 0;
}


