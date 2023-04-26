#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    int data[1005]={0};
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(h[j] == i)
                data[i]++;
        }
    }
    int mark = 0;
    for(int i=1004;i>-1;i--)
    {
        if(data[i]!=0)
        {
            mark = i;
            break;
        }
    }
    int ans=0,x=0,y=0;
    for(int i=0;i<mark+1;i++)
    {
        if(data[i]==0)
            continue;
        int flag;
        for(int j=i+1;data[j];j++)
            flag = j;
        int temp=data[i]*(flag-i);
        if(sum>=temp)
        {
            sum -= temp;
            ans = flag;
        }

        else
        {
            if(sum>=(flag-i))
            {
                ans+=sum/(flag-i);
                sum = sum%(flag-i);
            }
            else
            {
                x = temp/gcd(sum,temp);
            	y = sum/gcd(sum,temp);
            	break;
            }
            
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
