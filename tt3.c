# include <stdio.h>
# include <ctype.h>

int main()
{
    char s1[] = "hello, world!";
    char s2[80] = "hi, kitty";
    char *p1, *p2;

	printf("s1 = %s\ns2 = %s\n", s1, s2);

	p1 = s1, p2 = s2;
	while (*p1 != '\0')	{
		if (isalpha(*p1)){
			*p2 = *p1;
			p2++;
			*p2 = '-';
		} else
			*p2 = *p1;

		p1++, p2++;
	}

	printf("s1 = %s\ns2 = %s\n", s1, s2);

    return 0;
}
