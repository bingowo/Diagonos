#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
            for(int i=l-1;i>0;i--)
            {
                n = n+pow(k,p)*data[*(s+i)];
                p++;
            }

            printf("case #%d:\n",j);
            printf("%lld\n",n);
        }
        else{printf("case #%d\n",j);printf("1\n");}
    }


    return 0;
}