#include<stdio.h>
int main()
{
	int n, a, b, c=0;
	
	a = 0;
	b = 1;
	for (;;)
	{
		printf("enter 4 digit number \n");
		scanf_s("%d", &n);
		if (n < 1000)
			printf("It is not 4 digit number \n");
		else break;

	}
	
	while (c < n)
	{

		
		c = a + b;
		a = b;
		b = c;
		
	}
	
	if (n == c) {
		printf("it is fibonacci %d ", n);
	}
	else printf("it is NOT fibonaci Closest number is %d", c);

	return 0;
}