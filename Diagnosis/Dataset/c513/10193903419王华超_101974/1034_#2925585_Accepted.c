#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1000
typedef struct{
	char c;
	double f;
}ch;
int cmp(const void*p1,const void*p2){
	ch c1=*((ch*)p1),c2=*((ch*)p2);
	if(c1.f-c2.f==0){
		if(c1.c==c2.c+32||c1.c==c2.c-32){
			return c2.c-c1.c;
		}
		else{
			return toupper(c1.c)-toupper(c2.c);
		}
	}
	else{
		if(c1.f-c2.f>0)return -1;
		else return 1;
	}
	
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=0;cas<t;cas++)
	{
		double l[95];
	   	for(int i=65;i<=90;i++){
	   		scanf("%lf",&l[i]);
		}
		ch ll[110];
		char s[110];
		getchar();
		gets(s);
		for(int i=0;i<strlen(s);i++){
			ll[i].c=s[i];
			ll[i].f=s[i]>90?l[s[i]-32]:l[s[i]];
		}
		qsort(ll,strlen(s),sizeof(ll[0]),cmp);
		printf("case #%d:\n",cas);
		for(int i=0;i<strlen(s);i++){
			printf("%c",ll[i].c);
		}
		printf("\n");
	}
}