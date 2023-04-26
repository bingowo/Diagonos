#include <stdio.h>
#include <stdlib.h>

int a[210][210];
long long he[210][210];
long long ans;

/*int xiao(int x,int y)
{
    if(x>=y) return x;
    else return y;
}*/

void zuoshang(int zhi,int hangshu,int lieshu)
{
    int i,j,l,k;
    long long sum;
    for(i=0;i<hangshu;i++)
    {
        for(j=0;j<lieshu;j++)
        {
            sum=a[i][j];
            for(l=1;(i-l>=0)&&(j-l>=0);l++)
            {
                int lb=j-l;
                int rb=j;
                sum+=he[i-l][rb]-he[i-l][lb-1];
                //printf("zuoshang sum=%lld\n",sum);
                if(sum>=zhi) ans++;
            }
        }
    }
    //printf("zuoshang ans=%lld\n",ans);
}

void zuoxia(int zhi,int hangshu,int lieshu)
{
    int i,j,l,k;
    long long sum;
    for(i=0;i<hangshu;i++)
    {
        for(j=0;j<lieshu;j++)
        {
            sum=a[i][j];
            for(l=1;(i+l<hangshu)&&(j-l>=0);l++)
            {
                int lb=j-l;
                int rb=j;
                sum+=he[i+l][rb]-he[i+l][lb-1];
                //printf("zuoxia sum=%lld\n",sum);
                if(sum>=zhi) ans++;
            }
        }
    }
    //printf("zuoxia ans=%lld\n",ans);
}

void youshang(int zhi,int hangshu,int lieshu)
{
    int i,j,l,k;
    long long sum;
    for(i=0;i<hangshu;i++)
    {
        for(j=0;j<lieshu;j++)
        {
            sum=a[i][j];
            for(l=1;(i-l>=0)&&(j+l<lieshu);l++)
            {
                int lb=j+l;
                int rb=j;
                sum+=he[i-l][lb]-he[i-l][rb-1];
                //printf("youshang sum=%lld\n",sum);
                if(sum>=zhi) ans++;
            }
        }
    }
    //printf("youshang ans=%lld\n",ans);
}

void youxia(int zhi,int hangshu,int lieshu)
{
    int i,j,l,k;
    long long sum;
    for(i=0;i<hangshu;i++)
    {
        for(j=0;j<lieshu;j++)
        {
            sum=a[i][j];
            for(l=1;(i+l<hangshu)&&(j+l<lieshu);l++)
            {
                int lb=j+l;
                int rb=j;
                sum+=he[i+l][lb]-he[i+l][rb-1];
                //printf("youxia sum=%lld\n",sum);
                if(sum>=zhi) ans++;
            }
        }
    }
    //printf("youxia ans=%lld\n",ans);
}

int main()
{
    int hangshu,lieshu,zhi,i,j;
    ans=0;
    scanf("%d%d%d",&hangshu,&lieshu,&zhi);
    memset(a,0,sizeof(int)*210*210);
    for(i=0;i<hangshu;i++)
    {
        for(j=0;j<lieshu;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<hangshu;i++)
    {
        for(j=0;j<lieshu;j++)
        {
            if(j-1<0) he[i][j]=a[i][j];
            he[i][j]=(long long)a[i][j]+he[i][j-1];
        }
    }
    zuoshang(zhi,hangshu,lieshu);
    zuoxia(zhi,hangshu,lieshu);
    youshang(zhi,hangshu,lieshu);
    youxia(zhi,hangshu,lieshu);

    printf("%lld\n",ans);

    return 0;

}
