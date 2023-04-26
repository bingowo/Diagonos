#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	char* c = (char *)a;
    char* d = (char *)b;
    int x=strcmp(c,d);
	if(x>0) return 1;
	if(x<0) return  -1;
	else return 0;
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
        if(isalpha(c[i]))	{str[j][k]=c[i]; k++;continue;}
        else {str[j][k]='\0';j++;k=0;}	}
		qsort(str,j,sizeof(str[0]),cmp);
		for(int f=0;f<j;f++){
		if(strcmp(str[f],str[f+1])==0) {printf("%s ",str[f]);f++;continue;}
		else printf("%s ",str[f]);
		}
		printf("\n");
		 
	}
	return 0;
}