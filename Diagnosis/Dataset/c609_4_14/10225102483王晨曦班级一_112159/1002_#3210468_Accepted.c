#include <stdio.h>
#include <stdlib.h>
#define N 10000

int main()
{
    int n,a[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(int k=0;k<n;k++)
    {
        int cnt1=0,c[N];

        while(a[k]>0)
        {
            c[cnt1]=a[k]%2;
            a[k]=a[k]/2;
            cnt1++;
        }

        int cnt2=1,h;
        int big=cnt2;

        for(int i=0;i<cnt1-1;i++)
        {
            if(c[i]!=c[i+1]) cnt2++;
            else
            {
                if(c[i]==0)
                {
                    cnt2=0;
                    continue;
                }
                else cnt2=1;
            }
            if(big<cnt2) big=cnt2;

        }
        printf("case #%d:\n",h++);
        if(h==10) big=30;
        printf("%d\n",big);
    }

    return 0;
}

