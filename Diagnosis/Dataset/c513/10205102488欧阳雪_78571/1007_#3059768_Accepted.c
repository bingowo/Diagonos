#include<stdio.h>
int TenToR(int b[100],long long num,int r)//十进制转R进制（不包括十六进制，不包括负数） 
{
    long long c;
    int a[100];
    int i=0,j=0;
    while (num>0)
    {
        c = (num % r);
        a[i] = c;
        num = num / r;
        i++;
    }
    for (i--,j=0;i >= 0; i--,j++) //返回的b[]存储答案
	{
		b[j]=a[i];
	//	printf("%d",b[j]);
	}
//	printf("\n");       
	return j;//答案的位数
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long n;
		scanf("%lld",&n);
		int b[100]={0};
		int j=0;
		for(int j=0;j<100;j++)
		{
			b[j]=-1;
		}
		int a[100]={0};
		j=TenToR(b,n,2);
		int cnt=0,k=0;
		for(int t=0;t<j;t++)
		{
			cnt=1;
			while(b[t]!=b[t+1]&&t+1<j)
			{
				cnt++;
				t++;
			}
			a[k++]=cnt;
		}
		int M=0;
		for(j=0;j<k;j++)
		{
			if(a[j]>M)
			{
				M=a[j];
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",M);
	}
}