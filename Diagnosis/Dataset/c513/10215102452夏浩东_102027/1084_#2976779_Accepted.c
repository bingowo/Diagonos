#include <stdio.h>
void mul(int *L,int a,int len)
{
	int left=0;
	for(int i=len-1;i>0;i--)
	{
		int d = (L[i]*a+left)%10;
		left = (L[i]*a+left)/10;
		L[i] = d;
	}
	if(left!=0) L[0]=left;
}
int main()
{
    int cnt=0;scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        int n=0;
        scanf("%d",&n);
        int L[150];
        for(int i=0;i<150;i++) L[i]=0;
        L[149]=2;
        for(int i=0;i<n-1;i++) mul(L,2,150);
        int zero=0;
        while(L[zero]==0) zero++;
        printf("case #%d:\n",k);
        if(n==0) printf("1");
        else for(int i=zero;i<150;i++) printf("%d",L[i]);
        printf("\n");
    }
    return 0;
}