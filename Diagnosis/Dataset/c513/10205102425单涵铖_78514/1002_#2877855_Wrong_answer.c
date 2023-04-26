#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);

    int l,p=0;
    for(int j=0;j<t;j++)
    {
        char s[61];
        int data[128],k=0;

        for(int i=0;i<128;i++)
        {
            data[i] = -1;
        }

        long long res=0;

        scanf("%s",s);
        l = strlen(s);

        data[*s]=1;

        for(int i=0;i<l;i++)
        {
            if(data[*(s+i)]==-1)
            {
                data[*(s+i)]=k;
                k++;
                if(k==1)    k++;
            }
        }

        if(k>=2)
        {
            int p = l;
            for(int i=0;i<l;i++)
            {
                res = res + pow(k,p-1)*data[*(s+i)];
                printf("%lld\n",res);
                p--;
            }

            printf("case #%d:\n",j);
            printf("%lld\n",res);
        }
//bbabbbbaaaaababbabbababbaabbbabaabbbabbaabaaaaaaaaaaaaaaaaaa
        else
        {
            k = 2;
            int p = l;
            for(int i=0;i<l;i++)
            {
                res = res + pow(k,p-1)*data[*(s+i)];
                p--;
            }

            printf("case #%d:\n",j);
            printf("%lld\n",res);
        }
    }

    return 0;
}