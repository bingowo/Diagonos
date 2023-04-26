#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char str1[210] = {'\0'};
char str2[210] = {'\0'};
int cmp1(const void *a, const void *b){
    int i = 0; char *pa = (char *)a, *pb = (char *)b;//printf("%c %c\n", ca, cb);
    //if(*pa == *pb) *pb = 0;
	return strcmp(pa, pb);
}
int cmp2(const void *a, const void *b){
    int i = 0; int *pa = (int *)a, *pb = (int *)b;
    //if(*pa == *pb) *pb = 0;
	return *pb-*pa;
}

int main(){
	int t, i = 0, len1 = 0, len2 = 0, j, k = 0;
	scanf("%d", &t);gets(str1);
	for(i = 0; i < t; i++){
		gets(str1);
		len1 = strlen(str1);
		for(j = 0; j < len1; j++){
			if(isalpha(str1[j]))str2[k++] = str1[j];
		}
		str2[k] = '\0';len2 = strlen(str2);
		qsort(str2, len2, sizeof(char), cmp1);
		k = 0;
		for(j = 0; j < len1; j++){
			if(isalpha(str1[j]))str1[j] = str2[k++];
		}
		printf("case #%d:\n", i);
		for(j = 0; j < len1; j++){
			printf("%c", str1[j]);
			if(j == len1 - 1)printf("\n");
		}
		k = 0; len1 = 0; len2 = 0;
	}
	
	 
	//if(A[j].t != 1)printf("%d", A[j].real);
}