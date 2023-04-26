#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    long long s[60];
    memset(s,0,sizeof(s));
    s[1] = 1;
    s[2]=2;
    s[3] =4;
    s[4]=8;
    for(int i=5;i<51;i++)
    {
        s[i]=s[i-1]+s[i-2]+s[i-3]+s[i-4];
    }
    int n;
    scanf("%d",&n);
    for(int k =0;k<n;k++)
        {
            printf("case #%d:\n",k);
            int m;
            scanf("%d",&m);
            printf("%lld\n",s[m]);

        }
    return 0;
}
