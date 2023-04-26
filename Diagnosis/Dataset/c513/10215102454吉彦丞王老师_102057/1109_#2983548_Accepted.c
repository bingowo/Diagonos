#include<stdio.h>
#include<math.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a[9];
        int t=0;
        for(int j=0;j<9;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]!=0)
            {
                t++;
            }
        }
        printf("case #%d:\n",i);
        if(t==0)
        {
            printf("0\n");
        }
        else
        {
            int b[t];
            int m=0;
            for(int j=0;j<9;j++)
            {
                if(a[j]!=0)
                {
                    b[m]=8-j;
                    m++;
                }
            }
            if(a[8-b[0]]==1)
            {
            	if(b[0]==1)
            	{
					printf("x");
				}
				else if(b[0]==0)
				{
					printf("1");
				}
				else
				{
					printf("x^%d",b[0]);
				}
			}
			else if(a[8-b[0]]==-1)
			{
				if(b[0]==1)
				{
					printf("-x");
				}
				else if(b[0]==0)
				{
					printf("-1");
				}
				else
				{
					printf("-x^%d",b[0]);
				}
			}
			else
			{
				if(b[0]==1)
				{
					printf("%dx",a[8-b[0]]); 
				}
				else if(b[0]==0)
				{
					printf("%d",a[8-b[0]]);
				}
				else
				{
					printf("%dx^%d",a[8-b[0]],b[0]);
				}
			}
            for(int j=1;j<m;j++)
            {
                if(a[8-b[j]]>0)
				{
                    if(a[8-b[j]]==1)
                    {
                    	if(b[j]==1)
                    	{
                    		printf("+x");
						}
						else if(b[j]==0)
						{
							printf("+1");
						}
						else
						{
							printf("+x^%d",b[j]);
						}
					}
					else
					{
						if(b[j]==1)
						{
							printf("+%dx",a[8-b[j]]);
						}
						else if(b[j]==0)
						{
							printf("+%d",a[8-b[j]]);
						}
						else
						{
							printf("+%dx^%d",a[8-b[j]],b[j]);
						}
					}
                }
                else
                {
                    if(a[8-b[j]]==-1)
                    {
                    	if(b[j]==1)
                    	{
                    		printf("-x");
						}
						else if(b[j]==0)
						{
							printf("-1");
						}
						else
						{
							printf("-x^%d",b[j]);
						}
					}
					else
					{
						if(b[j]==1)
						{
							printf("%dx",a[8-b[j]]);
						}
						else if(b[j]==0)
						{
							printf("%d",a[8-b[j]]);
						}
						else
						{
							printf("%dx^%d",a[8-b[j]],b[j]);
						}
					}
                }
            }
            printf("\n");
        }
    }
    return 0;
}