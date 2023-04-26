#include <stdio.h>

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int x,n; scanf("%d %d",&x,&n);
        if (n==0) {printf("case #%d:\n1\n",i); continue;}
        int a[105] = {};
        a[0] = x;
        for (int j=1;j<n;j++)
        {
            for (int k=0;k<105;k++)
            {
                a[k] *= x;
            }
            for (int k=0;k<105;k++)
            {
                a[k+1] += a[k]/10;
                a[k] %= 10;
            }
        }
        int index = 104;
        while (a[index]==0) index--;
        printf("case #%d:\n",i);
        for (;index>=0;index--) printf("%d",a[index]);
        printf("\n");
    }
    return 0;
}