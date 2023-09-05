#include <stdio.h>

void ReverseFirstWord(char* arr, int *number_of_word, float *avarage);


void main()
{
  	char arr[100];
  	int number_of_word;
	float avarage;
   	printf("Enter a string to reverse:");
   	gets(arr);
   	printf("Entered a string to reverse: %s \n", arr);
   	
	ReverseFirstWord(arr, &number_of_word, &avarage);
	
	printf("Reverse of first word of the string: %s \n", arr);
	printf("Number of words in string: %d \n", number_of_word);
	printf("Avarage letter number: %f \n", avarage);
	

}

void ReverseFirstWord(char* arr, int *number_of_word, float *avarage)
{
	char rev[100];
	int i,letter=0,k,j,word=0;
	*number_of_word=0;
	*avarage=0;
	
	// count letters
    for (i=0;arr[i] != '\0'; i++){
    	if (arr[i] != ' '){
    		letter++;
		}
	}
	//printf("%d \n", letter);
	
	
	//count words
	for (i = 0;arr[i] != '\0';i++)
    {
        if (arr[i] == ' ' && arr[i+1] != ' '){
            word++;    
        }
    }
    *number_of_word=word+1;
    //printf("%d \n", word+1);
    
    
   //calculate avarage
   *avarage=(float)letter/ *number_of_word;
	//printf("%f \n", *avarage);
	
	
	// reverse first word
	for(i = 0; arr[i] != ' ' ; i++);
    {
        k = i-1;
    }
    for(j = 0; j <= i-1; j++)
    {
        rev[j] = arr[k];
        k--;
    }
    for(i = 0; arr[i] != ' '; i++){
    	arr[i]=rev[i];
	}
    
}

