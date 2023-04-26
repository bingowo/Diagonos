#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int m,int n)
{
    int max,min;
    if(m<n){min=m,max=n;}
    else{min=n,max=m;}
    int res;
    res=max%min,max=min,min=res;
    int out=1;
    out=(res==0)?max:GCD(min,max);
    return out;
}
int main()
{
	int N,i;
	scanf("%d",&N);
	int num,res,j,k;
	for(i=0;i<N;i++)
	{
		char a[121];
		num=0,res=0,j=0;
		while(getchar()=='\n');
		while((a[j]=getchar())!='\n')j++;
		printf("(a=%s)\n",a);
		for(j=0;j<strlen(a);j++)
		{
			while(a[j]>0)
			{
				if(a[j]%2==1)num++;
				a[j]/=2; 
			}
			printf("(%d)\n",num);
			res=res+8;
			printf("(%d)\n",res);
		}
		k=GCD(res,num);
		num/=k;
		res/=k;
		printf("%d/%d\n",num,res);
	}
	return 0;
}