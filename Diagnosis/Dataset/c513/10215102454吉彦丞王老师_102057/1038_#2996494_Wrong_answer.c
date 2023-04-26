#include<stdio.h>
#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int k;
    scanf("%d",&k);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            long long s=a[i][j];
            for(int r=1;i-r>=0&&j-r>=0;r++)
            {
                int lb=r;
                int rb=i;
                int rt=j;
                for(int q=lb;q<=rb;q++)
                {
                	s+=a[q][j-r];
                }
	            if(s>=k)
    	        {
        	        ans++;
            	}
            }

        }
    }
    for(int y=1;y<n;y++)
    {
        for(int x=m-2;x>=0;x--)
        {
            long long s=a[y][x];
            for(int r=1;y-r>=0&&x+r<=m-1;r++)
            {
                int lb=r;
                int rb=y;
                for(int q=lb;q<=rb;q++)
                {
                    s+=a[q][x+r];
                }
				if(s>=k)
            	{
                	ans++;
           	 	}
            }
            
        }
    }
    for(int y=n-2;y>=0;y--)
    {
        for(int x=1;x<m;x++)
        {
            long long s=a[y][x];
            for(int r=1;x-r>=0&&y+r<=n-1;r++)
            {
                int lb=n-1-r;
                int rb=y;
                for(int q=lb;q>=rb;q--)
                {
                    s+=a[q][x-r];
                }
				if(s>=k)
            	{
                	ans++;
            	}
            }
            
        }
    }
    for(int y=n-2;y>=0;y--)
    {
        for(int x=m-2;x>=0;x--)
        {
            long long s=a[y][x];
            for(int r=1;x+r<=m-1&&y+r<=n-1;r++)
            {
                int lb=r;
                int rb=y;
                for(int q=n-1-r;q>=rb;q--)
                {
                    s+=a[q][x+r];
                }
				if(s>=k)
            	{
               		ans++;
            	}
            }
        }
    }
    printf("%d",ans);
    return 0;
}