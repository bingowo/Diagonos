#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void er(int x,char*s){
	int k=0,i,t;
	while(x!=0){
		s[k]=x%2+'0';
		x=x/2;
		k++;
	}
	s[k]='\0';
	for(i=0,k=k-1;i<k;i++,k--){
		t=s[i];s[i]=s[k];s[k]=t;
	}
}
 int maxleng(char*s){
	char*p;
	char*r;
	p=s;
	int l=1,i;
	while(*p){r=p;
		for(i=1;*r&&(*r!=*(r+1));r++,i++);
		if(i>l) l=i;
		p=r+1;
 }
 return l-1;
 }
int main()
{ int i,T,j,x;
 char s[200];
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%d",&x);
		printf("case #%d:\n",i);
		er(x,s);
		printf("%d\n",maxleng(s));
	}
 return 0;
}