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

        for(int i=0;i<cnt1-1;i++)
        {
            if(c[i]!=c[i+1]) cnt2++;
            else if((cnt2<2)&&(c[i]==c[i+1]))
            {
                cnt2=1;
                continue;
            }

        }
        printf("case #%d\n",h++);
        printf("%d\n",cnt2);
    }

    return 0;
}