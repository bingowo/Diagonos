#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)//高度升序
{
    return *(int*)a-*(int*)b;
}

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}


int main()
{
    int n,sum;
    scanf("%d %d",&n,&sum);
    int h[1005];
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    qsort(h,n,sizeof(int),cmp);
    int ans=0,x=0,y=0;
    
    while(sum>0)
    {
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(h[i]==h[i-1])//找最低点有几个
            {
                cnt++;
            }
            else
                break;
        }
        
        if(sum>=cnt)
        {
            sum-=cnt;
            for(int i=0;i<cnt;i++)
                h[i]++;
        }
        else
        {
            x = sum/gcd(sum,cnt);
            y = cnt/gcd(sum,cnt);
            sum = 0;
        }
        
    }
    
    ans = h[0];
    
    if(ans == 0)
    {
        printf("%d/%d",x,y);
    }
    else
    {
        if(x==0 || y==0)
        {
            printf("%d",ans);
        }
        else
        {
            printf("%d+%d/%d",ans,x,y);
        }
    }

    return 0;

}