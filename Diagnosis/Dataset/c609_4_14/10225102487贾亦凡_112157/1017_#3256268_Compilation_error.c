#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a, const void *b){return *(int*)a-*(int*)b;} //升序
int cmp2(const void *a, const void *b){return *(int*)b-*(int*)a; }//降序
int main(){
char c;
scanf("%c"，&c);
int num[100], length=0;while(scanf("%d"，&num[length])!=EOF)(length++ror(int i=9; i<length-1; i++)if(num[length-1]==num[i])length--;
if(C=='A')
qsort(num, length, sizeof(num[o])， cmp1);
else
sizeof(num[0])， cmp2);qsort(num,length,printf("%d", num[o]);for(int i=1; i<length; i++) printf(”%d", num[i]);return ;}