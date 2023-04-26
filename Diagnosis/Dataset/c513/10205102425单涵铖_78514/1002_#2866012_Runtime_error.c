#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);

    int l,p=0;
    for(int j=0;j<t;j++)
    {
        char s[61];
        int data[128],k=2;
        memset(data,128,-1);
        unsigned long long n=0;

        scanf("%s",s);
        l = strlen(s);

        printf("%d\n",l);
        data[*s]=1;

        for(int i=1;i<n;i++)
        {
            if(data[*(s+i)]==-1)
            {
                if(i==1)    data[*(s+i)]==0;
                else {data[*(s+i)]==k;k++;}
            }
        }

        if(k>=2)
        {
            p = l;
            for(int i=0;i<l;i++)
            {
                n = n+pow(k,p)*data[*s];
                p--;
            }

            printf("case #%d:\n",j);
            printf("%lld\n",n);
        }

        else{printf("case #%d:\n",j);printf("1\n");}
    }


    return 0;
}
