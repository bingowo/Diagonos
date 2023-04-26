#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int t;
  int i=0;
  scanf("%d",&t);
  for(;i<t;i++){
  	char s[61];
  	scanf("%s",s);
  	int a[128];
	int j=0,dight=0,N=1;
	for(;j<128;j++)a[i]=-1;
	char *p=s;
	a[*p]=1;
	while(*++p){
		if(a[*p]==-1){
			a[*p]=dight;
			dight=dight?dight+1:2;N++;
		}
	} 
	if(N<2)N=2;
	long long message=0;
	p=s;
	while(*p)
	{
		message=message*N+a[*p++];
	}
  	printf("case #%d:\n",i);
  	printf("%lld\n",message);
  }
  return 0;	
}
