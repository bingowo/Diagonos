#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a,int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        int s[N];
        int count =0;
        int flag[1001];
        memset(flag,0,sizeof (int)*1001);
        for(int j=0;j<N;j++)
        {
            int m;
            scanf("%d",&m);
            if(flag[m]==0)
            {
                s[count ++]=m;
                flag[m]=1;
            }
        }
        int ans=0;
        for(int j=0;j<count;j++)
        {
            for (int l = j + 1; l <count; l++) {
                if (gcd(s[j],s[l])==1)
                    ans++;
                }
            }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}