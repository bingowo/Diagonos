#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,k=0;
        scanf("%d",&n);
        int s[100];
        for(int j=0;j<100;j++) s[j]=-1;
        int m=n;
        int num=1;
        while(m/2)
        {
            s[k++]=m%2;
            m=m/2;
            num++;
        }
        s[k]=m;
        int max=1;
        int ans=max;
        for(int i=0;i<num-1;i++)
        {
            if(s[i]!=s[i+1]) max++;
            else
            {
                max=1;
                continue;
            }
            if(ans<max) ans=max;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
}
