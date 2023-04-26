#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int d[101];
        for(int j=0;j<101;j++)
        {
            d[j]=0;
        }
        int t=0;
        d[0]=1;
        for(int j=0;j<b;j++)
        {
        	for(int k=0;k<101;k++)
        	{
        		d[k]=d[k]*a;
			}
			for(int k=1;k<101;k++)
			{
				d[k]=d[k]+d[k-1]/10;
				d[k-1]=d[k-1]%10;
			}
        }
        printf("case #%d:\n",i);
        for(int j=100;j>0;j--)
        {
            if(d[j]==0)
            {
            	t++;
			}
			else
			{
				break;
			}
        }
        for(int j=100-t;j>0;j--)
        {
        	printf("%d",d[j]);
		}
        printf("%d\n",d[0]);
    }
    return 0;
}