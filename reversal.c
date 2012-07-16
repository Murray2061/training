#include <stdio.h>


int main()
{

	char	temp;
	char	str[80] = "Hello world";
	char	*p1, *p2;

	p1 = str;
	p2 = str;
	while (*p2++) {
	}
	p2 -= 2;


	while (p2 - p1 > 0) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2--;
	}


	printf("%s\n", str);

	return 0;
}
