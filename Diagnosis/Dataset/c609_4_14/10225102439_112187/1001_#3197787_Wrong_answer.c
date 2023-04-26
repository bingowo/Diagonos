#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][2];
    for (int i=0;i<n;i++)
        scanf("%d%d",&a[i][0],&a[i][1]);
    for (int j=0;j<n;j++)
    {
        int x=a[j][0],y=a[j][1],m,t=0,n;
        char b[100000];
        if (x<0)
        {
            x=-x;
            n=1;
        }
        while (x!=0)
        {
            m=x%y;
            x/=y;
            if (m>=10)
            {
                b[t++]='A'+m-10;
                continue;
            }
            b[t++]='0'+m;
        }
        t--;
        if (n==1)
            printf("-");
        while (t>=0)
            printf("%c",b[t--]);
        printf("\n");
    }
    return 0;
}