#include<stdio.h>
void mul(int* A,int a)
{
	int carry=0,tmp,i;
	for(i=199;i>-1;--i)
	{
		tmp=A[i]*a+carry;
		A[i]=tmp%10;
		carry=tmp/10;
	}
}
int main()
{
	int T,i,j,a,n;scanf("%d",&T);
	for(int cas=0;cas<T;++cas)
	{
		scanf("%d %d",&a,&n);
		int A[200];for(i=0;i<200;++i)A[i]=0; A[199]=1;
		for(i=0;i<n;++i)mul(A,a);
		for(i=0;i<200;++i)if(A[i])break;
		printf("case #%d:\n",cas);
		for(i;i<200;++i)printf("%d",A[i]);
		printf("\n");
	}
	return 0;
}