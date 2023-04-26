#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&cnt);
    }
    int ans[100];
    ans[0]=a;
    for(i=0;i<cnt;i++)
    {
        for(j=0;j<100;j++)
            ans[j]=a*ans[j];
        for(j=0;j<100;j++)
            {
                ans[j+1]=ans[j+1]+ans[j]/10;
                ans[j]=ans[j]%10;
            }
    }
    if(cnt==0)
            printf("1");
    return 0;
}

