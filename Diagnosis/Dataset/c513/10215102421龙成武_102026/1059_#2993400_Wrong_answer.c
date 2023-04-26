#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void*a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int n,s,i,j,*a,h,x,y;
    scanf("%d %d",&n,&s);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compar);
    h=1;
    x=0;y=0;    //分数的分子分母
    while(s>0)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]>=h)     //有比当前高度高的就退出循环，此i以前的都是低的
                break;
        }
        if(i==0);
        else
        {
            if(s>=i)        //每个都能分到一格水
            {
                for(j=0;j<i;j++)
                    a[j]++;
                s-=i;
            }
            else
            {
                x=s;
                y=i;        //x<y
                s=0;
                if(gcd(y,x)!=1)
                {
                    x/=gcd(y,x);
                    y/=gcd(y,x);
                }
            }
        }
        h++;
    }
    printf("%d",a[0]);
    if(x!=0)
    {
        printf("+%d/%d",x,y);
    }
    return 0;
}
//