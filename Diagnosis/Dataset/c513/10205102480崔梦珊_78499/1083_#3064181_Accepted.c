#include<stdio.h>
int f(int n)
{
    int ans=0;
    if(n==0) return 0;
    for(int i=1;i<=n;i++)
    {
        int temp=i;
        while(temp%5==0)
        {
            ans++;
            temp=temp/5;
        }
    }
    return ans;

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%d\n",f(n));
    }
}
