#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int deletDigits(int n, int p);

void main()
{
	int n, p, result;
	printf("enter 9 digit number: ");
	scanf("%d", &n);
	printf("\n enter number beetwen 1-9:");
	scanf("%d", &p);
	printf("\n Result: " );
	deletDigits(n,p);
	
  
}
int deletDigits(int n, int p){
	int digit, x;
	if  (n==0){
	return 0;
}
	digit= n%10;
	x=deletDigits(n/10, p);	
	if (digit>p){
		printf("%d", digit);
	}
	return 0;		
}
