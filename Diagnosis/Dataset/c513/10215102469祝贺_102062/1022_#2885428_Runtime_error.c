#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define lim 2000000
char buffer[lim];

int cmp(const void* a,const void* b){
    char *s1=*((char**)a),*s2=*((char**)b);
	int len1=strlen(s1),len2=strlen(s2);
	char *ip1=s1,*ip2=s2;
	for(;*ip1!='@';ip1++);
	for(;*ip2!='@';ip2++);
    long long out=strcmp(ip1+1,ip2+1);
	if(out!=0)
        return out>0?1:-1;
	else
        return strcmp(s1,s2)<0?1:-1;
}
int main()
{
	long long n;scanf("%lld",&n);getchar();
	char** table=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++){
        fgets(buffer,lim,stdin);
        table[i]=(char*)malloc(sizeof(char)*strlen(buffer));
        strcpy(table[i],buffer);
	}
	qsort(table,n,sizeof(char*),cmp);
	for(int i=0;i<n;i++){
        printf("%s",table[i]);
        free(table[i]);
	}
	free(table);
	return 0;
}