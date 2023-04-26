#include<stdio.h> 
#include<string.h> 
int main()
{
	int A,B;
	char p[40];
	scanf("%d %s %d",&A,&p,&B);
	int s[40];
	int i=0;
	for(i;i<strlen(p);i++)
	{
		if(p[i]<65) s[i]=p[i]-48;
		else if(p[i]<97) s[i]=p[i]-55;
		else s[i]=p[i]-87;
	}
	int n=0,a=i;
	i=0;
	for(i;i<a;i++)
	{
		n=n*A+s[i];
	}
	int x=n,b=0;
	char m[40];
	while(1)
	{
		int y=x%B;
		if(y<10) m[b]=y+48;
		else m[b]=y+55;
		b++;
		x=x/B;
		if(x==0) break;
	}
	int v=b-1;
	for(v;v>=0;v--)
	{
		if(v!=0) printf("%c",m[v]);
		else printf("%c\n",m[v]);
	}
	
	return 0;
}