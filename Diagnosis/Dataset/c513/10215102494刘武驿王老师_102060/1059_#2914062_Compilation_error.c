#include<stdio.h>
#include<string.h>
int GCD(int m,int n)
{
    int a,b;
    if (m>n)
    {
        a=m;
        m=n;
        n=a;
    }

    if (n%m==0) return m;
    if (n%m!=0) return GCD(n-m,m);
}
int main()
{
    int mot[1005][1005];
    for(int j=0;j<1005;j++)
    {
        for(int i=0;i<1005;i++) mot[j][i]=0;
    }
    int height[2000];
    int wid,s,min=10000,max=0;
    scanf("%d %d\n",&wid,&s);
    for(int j=0;j<wid;j++)
    {
        scanf("%d",&height[j]);
        if(height[j]>max) max=height[j]-1;
        if(height[j]<min) min=height[j];
    }
    for(int j=0;j<wid;j++) for(int i=0;i<height[j];i++) mot[i][j]=1;
    int j,sum;
    double tmp;
    for(j=min;j<=max;j++)
    {
        sum=0;
        for(int i=0;i<wid;i++)
        {
            if(mot[j][i]==0) sum++;
        }
        if(sum<s) s-=sum;
        else break;
    }
    if(j<=max)
    {

        if(s%sum!=0)
        {
            int w=GCD(sum,s);
            sum/=w;
            s/=w;
            if(j!=0);
            printf("%d+%d/%d",j,s,sum);
            else printf("%d/%d",s,sum);
            return 0;
        }
        else
        {
            printf("%d",j+1);
            return 0;
        }
    }
    if(j>=max)
    {
        j+=s/wid;
        s=s%wid;
        if(s==0)
        {
            printf("%d",j);
            return 0;
        }
        else
        {
            int w=GCD(wid,s);
            wid/=w;
            s/=w;
            if(j!=0)
            printf("%d+%d/%d",j,s,wid);
            else printf("%d/%d",s,wid);
        }
    }
}
