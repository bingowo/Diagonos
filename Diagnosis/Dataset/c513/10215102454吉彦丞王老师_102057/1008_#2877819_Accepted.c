#include<stdio.h>
int length(int a)
{
    int l=1;
    while(a>0)
    {
        a=a/2;
        l++;
    }
    return l;
}
int main()
{
    int number;
    scanf("%d",&number);
    int a[number][2];
    int result[number];
    for(int i=0;i<number;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        int s1[length(a[i][0])];
        int s2[length(a[i][1])];
        int a1=a[i][0];
        int a2=a[i][1];
        for(int k=0;k<length(a[i][0]);k++)
        {
            s1[k]=a1%2;
            a1=a1/2;
        }
        for(int q=0;q<length(a[i][1]);q++)
        {
            s2[q]=a2%2;
            a2=a2/2;
        }
        int d=0;
        if(a[i][0]>=a[i][1])
        {
            for(int j=0;j<length(a[i][0]);j++)
            {
            	if(j<length(a[i][1]))
                {
					if(s1[j]!=s2[j])
                	{
                   		d++;
                	}
				}
				else
				{
					if(s1[j]==1)
					{
						d++;
					}
				 } 
            }
        }
        else
        {
            for(int t=0;t<length(a[i][1]);t++)
            {
            	if(t<length(a[i][0]))
                {
					if(s1[t]!=s2[t])
                	{
                    	d++;
                	}
                }
                else
                {
                	if(s2[t]==1)
                	{
                		d++;
					}
				}
            }
        }
        result[i]=d;
    }
    for(int i=0;i<number;i++)
    {
        printf("%d\n",result[i]);
    }
    return 0;
}