#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>


void main()
{
	
	
	int num1, sum, divisors[20], sizeDiv=20;
	float std;
	printf("Please enter the number:");
	scanf("%d", &num1);
	
	int i,j;
	float mean, Differ, Varsum=0, Variance;
    for(i=1,j=0;i<=num1,j<sizeDiv;i++,j++)
    {
        if(num1%i==0)
        {
            divisors[j]=i;
        }
    }
    
    sizeDiv=j;
    
    for(i=0; i<sizeDiv; i++)
   {
     sum = sum + divisors[i];
   }
	mean = sum /(float)sizeDiv;
	for(i=0; i<num1; i++)
   {
     Differ = divisors[i] - mean;
     Varsum = Varsum + pow(Differ,2);
   }
  
  	Variance = Varsum / (float)sizeDiv;
  	std = sqrt(Variance);
	
	if (sum==num1){
	printf("\n Number is a perfect number and the sum of it is divisors excluding itself:%d ", sum);
	}
	else {
	printf("\n Number is NOT a perfect number and the sum of it is divisors excluding itself:%d ", sum);
	} 
	printf("Standart deviation of its divisors excluding itself: %f", std);
	printf("Divisors of the number the excluding itself: \n");
	for(i=0;i<sizeDiv;i++){
		printf("%d, " ,divisors[i]);
	}
}
  
