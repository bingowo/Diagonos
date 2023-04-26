#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int gc(int x,int y)
{
	int n=0;
	for(int i=1;i<=x;i++) if(x%i==0&&y%i==0) return i;
}
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	int*p=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	int max=0;
	for(int i=0;i<n;i++) {if(p[i]>max) max=p[i];}
	int*ans=(int*)malloc(max*sizeof(int));
	for(int i=0;i<max;i++) ans[i]=0;
	int k=0,num=0;
	for(int j=1;j<max+1;j++)
	{
		for(int i=0;i<n;i++){
			if(p[i]<=j)
			{
				ans[k]+=j-p[i];
				
			}
		}
		if(ans[k]>0) num=1;//printf("%d %d\n",k,ans[k]);
		k++;
	}
	if(num==0) 
	{
		if(s%n==0) printf("%d",s/n+p[0]);
		else if(s<n)
		{
			int ok=gc(s,n);
			printf("%d+%d/%d",p[0],s/ok,n/ok);
		}
	}
	for(int i=0;i<k;i++)
	{
		if(s==ans[i]) printf("%d",i+1);
		else if(i<k-1&&s>ans[i]&&s<ans[i+1])
		{
			int m=i+1;
			int y=ans[i+1]-ans[i];
			int x=s-ans[i];
			if(x>=y) m+=x/y,x%=y; 
			int z=gc(x,y);
			x=x/z;y=y/z;
			printf("%d+",m);
			if(x>0) printf("%d/%d\n",x,y);
		}
	}
	
	
	
	free(p);
	free(ans);
	return 0;
}