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
    for(int i=0;i<n;i++)
    {
        int flag=i;
        for(int j=i+1;j<n;j++)
        {
            if(h[j]==h[i])
                flag = j;
            else
                break;
        }
        
        int temp=(h[flag+1]-h[i])*(flag-i+1);
        if(sum>=temp)
        {
            sum -= temp;
            ans = flag+1;
        }

        else
        {
            if(sum>=(flag-i+1))
            {
                ans+=sum/(flag-i);
                sum = sum%(flag-i);
            }
            x = temp/gcd(sum,temp);
            y = sum/gcd(sum,temp);
            break;
            
        }
    }
    if(ans == 0)
    {
        printf("%d/%d",x,y);
    }
    else
    {
        if(x==0)
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