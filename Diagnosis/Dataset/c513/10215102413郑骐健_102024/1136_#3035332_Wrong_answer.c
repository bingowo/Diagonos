#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int n;
    scanf("%d",&n);
    int bit[20005];
    int next[20005];
    int nextzero=0,nextone=0;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&bit[i]);
        if(bit[i]==0)cnt++;
    }
    int next3 =0;
    for(int k=1;k<=n;k++)
    {
        if(!bit[k])
        {
            next[++nextzero] = k;
            if(next3==0)next3 = k;
        }
    }
    nextone = nextzero;
     for(int k1=1;k1<=n;k1++)
    {
        if(bit[k1])next[++nextone] = k1;
    }
    int next2 = next3;
    for(int k2 =1;k2<=n;k2++)
    {
        if(!bit[next2])cnt--;
        next2 = next[next2];
    }
    if(cnt)printf("-1");
    else
    {
        for(int g=1;g<=n;g++){
            printf("%d%c",bit[next3],(g<n)?' ':0);
        next3 =next[next3];
        }

    }



    return 0;
}
