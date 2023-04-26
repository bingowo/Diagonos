#include<stdio.h>
int main()
{
     int a,n,m,x,y;
     int all,up,down,up0,up00;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int i,j,flg=0;
    all=a;
    up00=a;
    if(x==1||x==2)
    {
        printf("%d",a);
        flg=1;
    }
    if(flg==0)
    {
        for(y=0;y<m;y++)
        {
            up0=y;
            for(i=3;i<n;i++)
            {  
                up=up0+up00;
                down=up0;              
                all+=up-down;
                up00=up0;
                up0=up;
            }
            if(all==m)
            break;
            all=a;
            up00=a;
        }
        up0=y;
        up00=a;
        all=a;
        for(i=3;i<n;i++)
        {
            up=up0+up00;
            down=up0;
            all+=up-down;
            if(i==x)
            {
                printf("%d",all);
                break;
            }
            up00=up0;
            up0=up;
        }
    }
    return 0;
}