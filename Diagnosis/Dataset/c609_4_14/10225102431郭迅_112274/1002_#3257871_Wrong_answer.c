#include<stdio.h>
int j;
void f(int n,char s[])
{
	if(n/2){f(n/2,s);
	}
	s[j++]=n%2+'0';
	s[j]='\0';
}
int main()
{
	int t;scanf("%d",&t);
	int a[t];char s[t][32];
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a[i]);}
	for(int i=0;i<t;i++){
		f(a[i],s[i]);
		printf("%s\n",s[i]);
		int ret=1,m=1;
		for(int k=0;k<j-1;){
			if(s[i][k]!=s[i][++k])m++;
			else if (m>ret){ret=m;m=1;
			}
			else {m=1;}
		}
		printf("case #%d:\n%d\n",i,ret>m?ret:m);
	}
}