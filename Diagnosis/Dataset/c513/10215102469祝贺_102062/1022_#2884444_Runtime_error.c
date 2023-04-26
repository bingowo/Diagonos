#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define lim 1000005
char buffer[60];
int cmp(const void* a,const void* b){
	long long len1=strlen(*((char**)a)),len2=strlen(*((char**)b));
	char s1[len1+2],s2[len2+2];
	strcpy(s1,*((char**)a));strcpy(s2,*((char**)b));
	char *name1=strtok(s1,"@"),
	*ip1=strtok(NULL,"\n"),
        *name2=strtok(s2,"@"),*ip2=strtok(NULL,"\n");
    long long out=strcmp(ip1,ip2);
	if(out!=0)
        return out>0?1:-1;
	else
        return strcmp(name1,name2)>0?-1:1;
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
        printf("%s\n",table[i]);
        free(table[i]);
	}
	free(table);
	return 0;
}