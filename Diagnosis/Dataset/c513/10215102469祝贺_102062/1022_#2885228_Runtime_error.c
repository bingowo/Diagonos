#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define lim 1000100
char buffer[lim];

int cmp(const void* a,const void* b){
    char *s1=*((char**)a),*s2=*((char**)b);
	int len1=strlen(s1),len2=strlen(s2);

	char name1[len1],ip1[len1],
	name2[len2],ip2[len2];
	int i,p;
	for(i=0;s1[i]!='@';i++)
        name1[i]=s1[i];
    name1[i]=0;
	for(i=i+1,p=0;s1[i]!='\n';i++,p++)
        ip1[p]=s1[i];
	ip1[p]=0;
	for(i=0;s2[i]!='@';i++)
        name2[i]=s2[i];
	name2[i]=0;
	for(i=i+1,p=0;s2[i]!='\n';i++,p++)
        ip2[p]=s2[i];
	ip2[p]=0;
    long long out=strcmp(ip1,ip2);

	if(out!=0)
        return out>0?1:-1;
	else{
	}
        return strcmp(name1,name2)<0?1:-1;
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