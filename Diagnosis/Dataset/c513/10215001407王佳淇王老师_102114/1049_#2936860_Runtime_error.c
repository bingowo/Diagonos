#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	char* c = *(char **)a;
    char* d = *(char **)b;
    return strcmp(c,d);
	
}
int main(){
	int T;
	scanf("%d",&T);
	char str[500][500];
	char c[500];
	for(int v=0;v<T;v++){
	   gets(c);
	   printf("case #%d:\n",v);
        int len=strlen(c);
		int i=0,j=0,k=0;
        for(;i<len;i++){
        if(isalpha(c[i]))	{str[j][k]=c[i]; k++;}
        else {str[j][k]='\0';j++;k=0;}	
		}
		qsort(str,j,sizeof(char*),cmp);
		for(int f=0;f<j;f++) printf("%s ",str[f]);
	}
	return 0;
}