#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int s,int num)
{
    int c = 0;
    while(1)
    {
        c = s%num;
        while(c)
        {
            num = s;
            s = c;
            c = s%num;
        }
        return c;
    }
}

int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    int a[2000];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans[100][100]={0};
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<a[j];k++)
        {
            ans[k][j]=1;
        }
    }
    int m=0;
    while(1)
    {
        int num=0;
        for(int q=0;q<n;q++)
        {
            if(ans[m][q]==0) num++;
        }
        if(num<s)
        {
            s=s-num;
            m++;
        }
        else
        {
            if(num==s) printf("%d",m+1);
            else
            {
                printf("%d+%d/%d",m,s/gcd(s,num),num/gcd(s,num));
            }
            break;
        }
    }
}
