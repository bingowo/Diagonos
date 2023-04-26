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

int change(int a,int b)
{
	int t=1;
    for(int i=2;i<=min(a,b);i++)
    {
        if(a%i==0&&b%i==0)
        {
        	if(t<i)
        	{
        		t=i;
			}
        }
    }
    return t;
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
            	q++;
            	width++;
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
    }
    if(width==n)
    {
        while(s>width)
        {
    		s=s-width;
       		height+=1;
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
				int x=change(s,n);
				s=s/x;
				n=n/x;
				printf("%d+%d/%d",height,s,n);
			} 
		}
		else
        {
        	int y=change(s,width);
        	if(height==0)
        	{
        		s=s/y;
        		width=width/y;
        		printf("%d/%d",s,width);
			}
        	else
        	{
				s=s/y;
				width=width/y;
        		printf("%d",height);
        		printf("+");
        		printf("%d/%d",s,width);
        	}
        }
    }
    return 0;
}
