#include <stdio.h>
int main()
{
    int A=0,B=0;
    int L[30]={0};
    int flag=0;
    scanf("%d %d",&A,&B);
    if(A<0){flag=1;A=-A;}
    int z = A/B;
    int x = A%B;
    int num=0,i=0;
    while(z>0)
    {
        num=z%3;
        z=z/3;
        L[i]=num;
        i++;
    }
    for(int k=0;k<i/2;k++)
    {
        num=L[k];
        L[k]=L[i-1-k];
        L[i-1-k]=num;
    }
    int j=i;
    while(x>0)
    {
        num=x%3;
        x=x/3;
        L[j]=num;
        j++;
    }
    for(int k=i;k<(j+i)/2;k++)
    {
        num=L[k];
        L[k]=L[j-k+i-1];
        L[j-k+i-1]=num;
    }
    //
    int left=0;
    for(int k=j-1;k>=0;k--)
    {
    	L[k]=L[k]+1+left;
    	if(L[k]==3){L[k]=0;left=1;}
    	else if(L[k]==4){L[k]=1;left=1;}
    	else left=0;
	}
	//
	for(int k=0;k<j;k++)
	{
		L[k]-=1;
		if(L[k]==-1) L[k]=2;
	}
	//
	for(int k=j-1;L[k]==0;k--) j--;
	//
	if(flag==1)
	{
		for(int k=0;k<j;k++)
		{
			if(L[k]==1) L[k]=2;
			else if(L[k]==2) L[k]=1;
		}
    }
	if(left == 2)
	{
		printf("1");
		for(int k=0;k<j;k++)
		{
			if(k==i) printf(".");
			printf("%d",L[k]);
		}
	}
	else
	{
		for(int k=0;k<j;k++)
		{
			if(k==i) printf(".");
			printf("%d",L[k]);
		}
	}
    return 0;
}