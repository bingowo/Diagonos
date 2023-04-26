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
		for(j=0,m=0;j<k;j++){
			if(a[j]==a[j+1])count[m]++;
			else m++;
		}
		M=m;
		for(m=0,ans=0;m<M;m++){
			if(count[m]>ans)ans=count[m];	
		}
	printf("case #%d:\n",i+1);
	printf("%d\n",ans);
	}
	return 0;
}