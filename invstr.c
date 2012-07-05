# include <stdio.h>

int main()
{
    char s[80] = "1234567890";
    char *p1, *p2, p3;

        printf("s = %s\n", s);

        p1 = s, p2 = s;
	while (*p2 != '\0')	{
		p2++;
	}
	p2--;
        while (*p1 != '\0')     {
		if (p2 - p1 > 0){
		  	 p3 = *p2;
			*p2 = *p1;
			*p1 =  p3;
		}
	        p1++, p2--;
        }
        printf("s = %s\n", s);

    return 0;
}
