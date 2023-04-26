#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        long long temp=x^y;
        int ans=0;
        while(temp>0)
        {
            temp=temp&(temp-1);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

