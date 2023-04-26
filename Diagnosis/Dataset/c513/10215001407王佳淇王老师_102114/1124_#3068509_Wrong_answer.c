#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int gcd(int x, int y)
{
    while(y^=x^=y^=x%=y);
    return x;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int n,i,t;
		int a[1001]={0};
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			a[t]=1;		}
			printf("case #%d:\n",v);
		int b[1000],m=0,cnt=0,j;
		for(i=1;i<=1000;i++){
			if(a[i]) b[m++]=i;
		}	
		for(i=0;i<m-1;i++){
			for(j=i+1;j<m;j++)
			if(gcd(b[i],b[j])==1) cnt++;
		}	
	printf("%d",cnt);
	}
	return 0;
}
/*
1
5
1 2 30 2 3*/