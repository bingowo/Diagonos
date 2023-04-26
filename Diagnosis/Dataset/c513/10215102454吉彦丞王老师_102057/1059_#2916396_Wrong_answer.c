#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void change(int a,int b)
{
    for(int i=2;i<=min(a,b);i++)
    {
        if(a%i==0&&b%i==0)
        {
            a=a/i;
            b=b/i;
        }
    }
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[n];
    int x=2,y=4;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int t=1;
    int width=1;
    int q=1;
    qsort(a,n,sizeof(int),cmp);
    int height=a[0];
    for(int i=0;i<n-1;i++)
    {
        if(s>width*(a[i+1]-a[i]))
        {
            if(a[i+1]==a[i])
            {
            	width++;
            	q++;
                continue;
            }
            else
            {
                s=s-width*(a[i+1]-a[i]);
                height+=a[i+1]-a[i];
                width++;
            }
        }
        else
        {
            if(s>=width)
            {
                height+=s/width;
                s=s-(s/width)*width;
                break;
            }
            else
            {
                change(s,width);
                break;
            }
        }
        if(width==n)
        {
        	while(s>width)
        	{
        		s=s-width;
        		height+=1;
			}
		}
        
    }
    if(s==0)
    {
        printf("%d",height);
    }
    else
    {
    	if(q==n)
    	{
    		if(s%n==0)
    		{
				height+=s/n;
				printf("%d",height);
			}
			else
			{
				if(s>n)
				{
					s=s-n;
					height+=1;
				}
				change(s,n);
				printf("%d+%d/%d",height,s,n);
			} 
		}
		else
        {
        	if(height==0)
        	{
        		change(s,width);
        		printf("%d/%d",s,width);
			}
        	else
        	{
				change(s,width);
        		printf("%d",height);
        		printf("+");
        		printf("%d/%d",s,width);
        	}
        }
    }
    return 0;
}
