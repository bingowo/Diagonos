#include<stdio.h>

int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    int a[205][205]={0};
    for(int i = 0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int degree;
    degree = d%360;
    if(c=='R')//顺时针
    {
        if(degree==0)
        {
            printf("%d %d\n",w,h);
            
            for(int i = 0;i<h;i++)
    		{
                    for(int j=0;j<w-1;j++)
        			{
            			printf("%d ",a[i][j]);
        			}
                	printf("%d\n",a[i][w-1]);
        		
    		}
        }
        
        if(degree==90)
        {
            printf("%d %d\n",h,w);
            for(int i = 0;i<w;i++)
    		{
                    for(int j=h-1;j>0;j++)
        			{
            			printf("%d ",a[j][i]);
        			}
                	printf("%d\n",a[0][i]);
        		
    		}
        }
        if(degree==180)
        {
            printf("%d %d\n",w,h);
            for(int i = h-1;i>-1;i++)
    		{
                    for(int j=w-1;j>0;j++)
        			{
            			printf("%d ",a[i][j]);
        			}
                	printf("%d\n",a[i][0]);
        		
    		}
        }
        if(degree==270)
        {
            printf("%d %d\n",h,w);
            for(int i = w-1;i>-1;i++)
    		{
                    for(int j=0;j<h-1;j++)
        			{
            			printf("%d ",a[j][i]);
        			}
                	printf("%d\n",a[h-1][i]);
        		
    		}
        }
        
        
    }
    else//逆时针
    {
        if(degree==0)
        {
            printf("%d %d\n",w,h);
            
            for(int i = 0;i<h;i++)
    		{
                    for(int j=0;j<w-1;j++)
        			{
            			printf("%d ",a[i][j]);
        			}
                	printf("%d\n",a[i][w-1]);
        		
    		}
        }
        if(degree==90)
        {
            printf("%d %d\n",h,w);
            for(int i = w-1;i>-1;i++)
    		{
                    for(int j=0;j<h-1;j++)
        			{
            			printf("%d ",a[j][i]);
        			}
                	printf("%d\n",a[h-1][i]);
    		}
        }
        if(degree==180)
        {
            printf("%d %d\n",w,h);
            
            for(int i = h-1;i>-1;i++)
    		{
                    for(int j=w-1;j>0;j++)
        			{
            			printf("%d ",a[i][j]);
        			}
                	printf("%d\n",a[i][0]);
        		
    		}
            
            
        }
        if(degree==270)
        {
            printf("%d %d\n",h,w);
            for(int i = 0;i<w;i++)
    		{
                    for(int j=h-1;j>0;j++)
        			{
            			printf("%d ",a[j][i]);
        			}
                	printf("%d\n",a[0][i]);
    		}
        }
        
    }
    return 0;
    
}

