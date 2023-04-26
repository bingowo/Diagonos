#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

void f(int *s,int* w,int p,int q,int n)
{
	if(q>0) s[q]=1;
	if(p==n) return;
	f(s,w,p+1,q,n);
	f(s,w,p+1,q+w[p],n);
	f(s,w,p+1,q-w[p],n);
}
int main()
{
	int n;
	scanf("%d",&n);
	int w[20],s[2000]={0};
	int sum=0;
	for(int i=0;i<n;i++) scanf("%d",&w[i]),sum+=w[i],s[w[i]]=1;
	f(s,w,0,0,n);
	for(int k=1;k<=sum;k++) printf("%d",s[k]);
	
	return 0;
}