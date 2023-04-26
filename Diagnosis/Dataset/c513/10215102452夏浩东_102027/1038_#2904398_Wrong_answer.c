#include <stdio.h>
int L[200][200]={0};
int k=0;
long long int getNum(int x,int y,int fx,int fy)
{
    
}
int main()
{
    int m=0,n=0;
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