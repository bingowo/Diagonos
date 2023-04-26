#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define lim 1000100
char buffer[lim];

int cmp(const void* a,const void* b){
    char *s1=*((char**)a),*s2=*((char**)b);
	char ip1[100],ip2[100],p=0;
	int index=0;
	for(;s1[index]!=0;index++);
	for(index=index+1,p=0;s1[index]!='\n';index++,p++)
		ip1[p]=s1[index];
	ip1[p]=0;
	for(index=0;s2[index]!=0;index++);
	for(index=index+1,p=0;s2[index]!='\n';index++,p++)
		ip2[p]=s2[index];
	ip2[p]=0;
	
    long long out=strcmp(ip1,ip2);

	if(out!=0)
        return out>0?1:-1;
	else{
	}
        return strcmp(s1,s2)<0?1:-1;
}
int main()
{
	long long n;scanf("%lld",&n);getchar();
	char** table=(char**)malloc(sizeof(char*)*n);
	int _p[n];
	for(int i=0;i<n;i++){
        fgets(buffer,lim,stdin);
        table[i]=(char*)malloc(sizeof(char)*strlen(buffer));
        strcpy(table[i],buffer);
        int p;
		for(p=0;table[i][p]!='@';p++);
		table[i][p]=0;
	}
	qsort(table,n,sizeof(char*),cmp);
	for(int i=0;i<n;i++){int j=0;
		for(;table[i][j]!=0;j++);
		table[i][j]='@';
	}
	for(int i=0;i<n;i++){
        printf("%s",table[i]);
        free(table[i]);
	}
	free(table);
	return 0;
}