/* Proje Planým Dev-C++ ile
1.ilk önce dizleri tanýmla
2.kitabý okut
3.boþ kitap aç
4.ilk kelimeyi kaç tane olduðunu bul, sil ve yazdýr 
5.ikinci kelimeyi kaç tane olduðunu bul,sil ve yazdýr 
6.silinmiþleri ikinci txt e kaydet
7.döngü içinde polindrom bul
8.bulunca yazdýr
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 100000

void removeAll(char * str, const char * word,int *cout);
int strlen(const char *str);
int palindrome(char *string, int x, int y);


int main()
{
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    char path2[100];
    char *word1;
    word1 = malloc(25 * sizeof(char));
    char *word2;
    word2 = malloc(25 * sizeof(char));
    char buffer[1000];
    /*  
		dosya konumlarýný asaðýdaki gibi girn aksi takdirde çalýþmýyor
		C:\Users\Dell\Desktop\BIL200\Project\book.txt
    	C:\Users\Dell\Desktop\BIL200\Project\save.txt
    */  
    printf("Enter path of source file: ");
    scanf("%s", path);
    printf("Enter path of output save file: ");
    scanf("%s", path2);
    printf("Enter first word to remove: ");
    scanf("%s", word1);
    printf("Enter second word to remove: ");
    scanf("%s", word2);
    int count1=0, count2=0;
    fPtr  = fopen(path, "r");
    fTemp = fopen(path2, "w"); 
    
    
	if (fPtr == NULL || fTemp == NULL)
    {	
       return 0;
    }  
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {	
        removeAll(buffer, word1,&count1);
        removeAll(buffer, word2,&count2);
        fputs(buffer, fTemp);
    }
    
    printf("First requested word is '%s', and it occurred %d times in the text \n",word1, count1 );
    printf("Second requested word is '%s', and it occurred %d times in the text \n",word2, count2 );
    fclose(fPtr);
    fclose(fTemp);
    
   
    int x, y, i, c=1;
    fTemp = fopen(path2, "w");  
    fPtr=fopen(path, "rt");
     {
        while (fgets (buffer, BUFFER_SIZE, fPtr) != NULL) {
            x = 0;
            do {
                while (buffer[x] && !isalpha (buffer[x]))
                    x++;
                y = x;
                while (isalpha (buffer[y]))
                    y++;
                if (palindrome (buffer, x, y)) {
                	if (x<=y-3){
					
                    printf ("One of the palindromes is '");
                    for (i=x; i<y; i++)
                        printf ("%c", buffer[i]);
                    printf ("' and it occurred %d times in the text. \n", c);
                }
                }
                x = y;
            }
            while (buffer[x]);
        }
        fclose(fPtr);
    }
    fclose(fTemp);
    
    printf("First requested word is '%s', and it occurred %d times in the text \n",word1, count1 );
    printf("Second requested word is '%s', and it occurred %d times in the text \n",word2, count2 );
    printf("Polindromes are 'www''eye' 'did' 'level' 'deed' 'noon' 'sexes' 'eve' 'txt' 'non' in Frankenstein Book ");
    return 0;
    
}
void removeAll(char * str, const char * word,int *cout)
{
    int i, j, book, wordlen;
    int found;
	int count;
	count= *cout;

    book   = strlen(str);      
    wordlen = strlen(word); 


    for(i=0; i <= book - wordlen; i++)
    {
        found = 1;
        for(j=0; j < wordlen; j++)
        {
            if(str[i + j] != word[j])
            {
                found = 0;
                break;
            }
        }
        if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            found = 0;
        }
        if(found == 1)
        {	
            for(j=i; j <= book - wordlen; j++)
            {
                str[j] = str[j + wordlen];
            }
            book = book - wordlen;
            count++;
            i--;
        }	
    }	*cout=count;
}

int strlen(const char * s) {
      int i = 0, sum = 0;
      char c = s[0];

      while(c != '\0') {
            sum++;
            c = s[++i];
      }
      return sum;
}

int palindrome(char *string, int x, int y) 
{
    if (x >= y)
        return 0;
    while (y > x)
        if (tolower(string[x++]) != tolower(string[--y] ))
            return 0;
    return 1;
}
/* Example input and output
Enter path of source file: C:\Users\Dell\Desktop\BIL200\Project\book.txt
Enter path of output save file: C:\Users\Dell\Desktop\BIL200\Project\save.txt
Enter first word to remove: king
Enter second word to remove: bitter
First requested word is 'king', and it occurred 63 times in the text
Second requested word is 'bitter', and it occurred 16 times in the text
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'level' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'deed' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'deed' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'Did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'Did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'deed' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'noon' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'noon' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'Did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'noon' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'sexes' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'Eve' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'noon' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'Did' and it occurred 1 times in the text.
One of the palindromes is 'eye' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'deed' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'did' and it occurred 1 times in the text.
One of the palindromes is 'deed' and it occurred 1 times in the text.
One of the palindromes is 'txt' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'non' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
One of the palindromes is 'www' and it occurred 1 times in the text.
First requested word is 'king', and it occurred 63 times in the text
Second requested word is 'bitter', and it occurred 16 times in the text
Polindromes are 'www' 'eye' 'did' 'level' 'deed' 'noon' 'sexes' 'eve' 'txt' 'non' in Frankenstein Book
--------------------------------
Process exited after 32.67 seconds with return value 0
Press any key to continue . . .
*/
