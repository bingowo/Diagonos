#include <stdio.h>
#include <stdlib.h>
int pow(int a,int n,int *ans)
{
    int cnt=0;
    if(n==0)    ans[cnt++]=1;
    else          ans[cnt++]=a;
    for(int i=1;i<n;i++)
    {
        int carry=0;
        for(int j=0;j<cnt;j++)
        {
            int x = ans[j] * a + carry;
            carry = x/10,ans[j]=x%10;
        }
        if(ans[cnt]==0 && carry!=0 )
            ans[cnt++]=carry;
    }
    return cnt;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a,n;
        scanf("%d %d",&a,&n);
        int ans[200]={0};
        int len = pow(a,n,ans);
        printf("case #%d:\n",i);
        for(int i=len-1;i>=0;i--)
            printf("%d",ans[i]);
        putchar('\n');
    }

    return 0;
}
