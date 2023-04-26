#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double alphabet[58];//全局变量 
int cmp(const void* a, const void* b);
int main(){
	int T;
    scanf("%d",&T);
    int i;
    char s[101];
    for (i = 0; i < T; i++){
    	int j;
    	for (j = 0; j < 26; j++){
    		scanf("%f",&alphabet[j]);
    		alphabet[j+32] = alphabet[j];
		}
		scanf("%s",s);
		int length = strlen(s);
		qsort(s,length,sizeof(char),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",s);
	}
} 

int cmp(const void* a, const void* b){
	char a1 = *((char *)a);
	char b1 = *((char *)b);
	if (alphabet[a1 - 65] - alphabet[b1 - 65] != 0){
		return alphabet[a1 - 65] - alphabet[b1 - 65] > 0?-1:1;
	}else{
		return a1 > b1?-1:1;
	}
}