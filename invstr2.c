# include <stdio.h>

int main()
{
    char s[80] = "123 456 789 0";
    char *p1, *p2, p3, *ind;

        printf("s = %s\n", s);

        p1 = s, p2 = s;
	while (*p1 != '\0')	{
		while (*p2 != '\0' && *p2 != ' ')	{
			p2++;
		}
		ind = p2 + 1;
		p2--;
        	while (*p1 != ' ')     {
			if (p2 - p1 > 0){
		  		 p3 = *p2;
				*p2 = *p1;
				*p1 =  p3;
			}
	       		p1++, p2--;
		}
		p1 = ind, p2 = ind;
        }
        printf("s = %s\n", s);
    return 0;
}
