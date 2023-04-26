#include<stdio.h>
int main()
{
	int t,n,i,j,k,m,M,ans;
	int a[1000000],count[100000];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		for(j=0;n!=0;j++){
			a[j]=n%2;
			n/=2;	
		}
		k=j;
		for(m=0;m<k;m++)count[m]=1;
		for(j=k,m=0;j>+0;j++){
			if(a[j]!=a[j-1])count[m]++;
			else m++;
		}
		M=m;
		for(m=0,ans=0;m<M;m++){
			if(count[m]>ans)ans=count[m];	
		}
	printf("case #%d:\n",i);
	printf("%d\n",ans);
	}
	return 0;
}