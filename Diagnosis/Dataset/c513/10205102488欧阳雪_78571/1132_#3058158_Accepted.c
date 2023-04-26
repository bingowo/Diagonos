#include<stdio.h>
int TenToR(int b[100],long long num,int r)//十进制转R进制 
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
    for (i--,j=0;i >= 0; i--,j++) 
	{
		b[j]=a[i];
	}       
	return j;
}
int TenToSixteen(char b[100],long long num)
{
        char arr[] = "0123456789ABCDEF";
        char hex[16];
        int i = 0,j = 0;
        int a = 0;
        while (num)
        {
            hex[i++] = arr[num % 16];   
            num = num / 16;
        }
        int t=0;
        for (j = i - 1,t; j >= 0; --j,t++)
        {
        	b[t]=hex[j];
		}
		return t;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long int num;
		int r;
		scanf("%lld",&num);
		scanf("%d",&r);
		int j=0;
		printf("case #%d:\n",i);
		if(r==16)
		{
			char b[100]={0};
			int t=TenToSixteen(b,num);
			long long cnt=0;
			for(j=0;j<t;j++)
			{
				if(b[j]>='0'&&b[j]<='9')
				{
					cnt+=(b[j]-'0');
				}
				if(b[j]>='A'&&b[j]<='F')
				{
					cnt+=(b[j]-7-'0');
				}
			}
			char ans1[100]={0};
			TenToSixteen(ans1,cnt);
			printf("%s\n",ans1);
		}
		else
		{
			int a[100]={0};
			int k=TenToR(a,num,r);
			long long cnt=0;
			for(j=0;j<k;j++)
			{
				cnt+=a[j];
			}
			int ans2[100]={0};
			int z=TenToR(ans2,cnt,r);
			char s[]={'A','B','C','D','E','F'};
			for(j=0;j<z;j++)
			{
				if(ans2[j]>9)
				{
					printf("%c",s[ans2[j]-10]);
				}
				else
				{
					printf("%d",ans2[j]);
				}
			}
			printf("\n");
		}
	}
}


