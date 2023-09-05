#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
int sumofDivisors(int NUM);
void amicableNumbers(int NUM1, int NUM2, int SUM1, int SUM2);

void main()
{
  int NUM1,NUM2,SUM1,SUM2;
  printf("TWO INTERGER AMICABLE NUMBERS CHECKER \n");
  printf("ENTER NUMBER1 :\n");
  scanf("%d",&NUM1);
  printf("ENTER NUMBER2 :\n");
  scanf("%d",&NUM2);
  SUM1=sumofDivisors(NUM1);
  SUM2=sumofDivisors(NUM2);
  amicableNumbers(NUM1, NUM2, SUM1, SUM2);
}

int sumofDivisors(int NUM){
	int SUM=0,i ;
	for(i=1;i<NUM;i++)
  {
  
	if(NUM%i==0)
    {
      SUM=SUM+i;
    }
     
}
 return SUM;
}
void amicableNumbers(int NUM1, int NUM2, int SUM1, int SUM2){
	if(NUM1==SUM2 && NUM2==SUM1)
  {
    printf("\n%d AND %d ARE AMICABLE NUMBERS",NUM1,NUM2);
  }
  else
  {
    printf("\n%d AND %d ARE NOT AMICABLE NUMBERS",NUM1,NUM2);
  }
	
}


