#include <stdio.h> 
int main() { 
int arr[5] = { 3, 2, 4, 11, 7 }; int c, d, e; 
for (d = 0; d < 4; d++) { 
if (arr[d] > arr[d + 1]) { 
e = arr[d]; arr[d] = arr[d + 1]; arr[d + 1] = e; }}
printf("%d", arr[2]); 
return 0; 
}
