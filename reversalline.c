#include <stdio.h>
#include <stdlib.h>

int main()
{
    char	str[1024], temp;
    char	*p1, *p2,*pend,*pnow;
    int  n, i;
    FILE	*rptr;

    if ((rptr = fopen("fread.man", "r")) == NULL) {
        printf("File could not be opened");
        exit(1);
    }else {
        while (!feof(rptr)) {
            fgets(str, sizeof (str), rptr);
            pnow = str;
            pend = str;
			p1=str;
			p2=str;
			while (*pend++){}
			pend -=2;
			if(*pend=='\n'){pend--;}
			while(pend-p1>=0){
			if(isspace(*p2)){
			while(isspace(*p2++)){}
			p2--;
			if(*p2=='\0'){p2--;}
			if(*p2=='\n'){p2--;}
			if(isspace(*p2)){p2++;}
			p1=p2;
			}
			
			while (!isspace(*p2++)) {}
            p2 --;
            if (*p2 == '\n') {
                p2--;
            }
			pnow=p2;
            while (p2 - p1 > 0) {
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
                p2--;
                p1++;
            }
			
			p1=pnow;
            p2=pnow;
             }
            fprintf(stdout, "%s", str);
        }
    }


    fclose(rptr);
    return 0;
}


