#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    for (int j=0;j<n;j++)
    {
        int x=a[j],m,p,q=0,cnt=1;
        p=x%2;
        x/=2;
        while (x!=0)
        {
            m=x%2;
            x/=2;
            if (m!=p) cnt++;
            if (m==p)
            {
                if (cnt>q) q=cnt;
                cnt=1;
            }
            p=m;
        }
        if (cnt>q) q=cnt;
        printf("case #%d:\n",j);
        printf("%d\n",q);
    }
    return 0;
}
