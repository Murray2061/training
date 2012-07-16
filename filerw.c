#include <stdio.h>
int main()
{
    char	str[80];
    int	bn;
    FILE	*rptr;

//FILE *wptr;
//wptr=fopen("phil2.txt","w");
    if ((rptr = fopen("fread.man", "r")) == NULL) {
        printf("File could not be opened");
    }else {
        while (!feof(rptr)) {
            bn = fread(str, sizeof (str), 1, rptr);
            fwrite(str, bn, 1, stdout);
//fwrite(str,sizeof(str),1,wptr);
        }
    }
    fclose(rptr);
}


