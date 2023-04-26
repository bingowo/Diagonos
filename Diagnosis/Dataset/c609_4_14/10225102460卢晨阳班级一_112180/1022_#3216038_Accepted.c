#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void*b){
	char *p1,*p2,*main1,*main2;
	int i=0;
	p1=*((char**)a);
	p2=*((char**)b);
	while(*(p1+i)!='@')
		i++;
		main1=p1+i+1;
	i=0;
	while(*(p2+i)!='@')
		i++;
		main2=p2+i+1;
	if(strcmp(main1,main2)==0)
		return strcmp(p2,p1);
	else
		return strcmp(main1,main2);
}


int main()
{
	long long n;
	scanf("%lld",&n);
	char **email;
	email=(char**)malloc(n*sizeof(char*));
	char s[1000001],*p;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int len=strlen(s);
		p=(char*)malloc(len+1);
		strcpy(p,s);
		*(email+i)=p;
	}
	qsort(email,n,sizeof(char*),cmp);
	for(int i=0;i<n;i++)
		printf("%s\n",email[i]);
	return 0;
 } 