#include <stdio.h>
int L[200][200]={0};
int k=0,m=0,n=0; 
long long int getNum(int x,int y,int fx,int fy)
{
    long long int num=0;
    int sum=L[x][y];
    for(int s=1;x+s*fx<m && x+s*fx>=0 && y+s*fy<n && y+s*fy>=0;s++)
    {
        for(int i=0;i<=s;i++)
        {
            sum+=L[x+fx*i][y+(s-i)*fy];
        }
        if(sum >= k) num++;
    }
    return num;
}
int main()
{
    scanf("%d %d %d",&m,&n,&k);
    for(int x=0;x<m;x++)
    {
        for(int y=0;y<n;y++)
        {
            scanf("%d",&L[x][y]);
        }
    }
    long long int num=0;
    for(int x=0;x<m;x++)
    {
        for(int y=0;y<n;y++)
        {
            int flagx=0,flagy=0;
            if(x+1<m)
            {
                if(y+1<n){flagx=1;flagy=1;num+=getNum(x,y,flagx,flagy);}
                if(y-1>=0){flagx=1;flagy=-1;num+=getNum(x,y,flagx,flagy);}
            }
            if(x-1>=0)
            {
                if(y+1<n){flagx=-1;flagy=1;num+=getNum(x,y,flagx,flagy);}
                if(y-1>=0){flagx=-1;flagy=-1;num+=getNum(x,y,flagx,flagy);}
            }
        }
    }
    printf("%lld",num);
    return 0;
}