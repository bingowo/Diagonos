#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a[4]={0};
        char s[101];
        scanf("%s",s);
        printf("case #%d:\n",i);
        int len= strlen(s);
        int r=len,b=len,y=len,g=len;
        for(int j=0;j<len;j++)
        {
            if (s[j]=='!')
                a[j%4]++;
            else
            {
                if(s[j]=='R')
                    r=j;
                if(s[j]=='B')
                    b=j;
                if(s[j]=='Y')
                    y=j;
                if(s[j]=='G')
                    g=j;
            }
        }
        if(r<len)
            printf("%d ",a[r%4]);
        else
            printf("%d ", a[6-b%4-y%4-g%4]);
        if(b<len)
            printf("%d ",a[b%4]);
        else
            printf("%d ", a[6-r%4-y%4-g%4]);
        if(y<len)
            printf("%d ",a[y%4]);
        else
            printf("%d ", a[6-r%4-b%4-g%4]);
        if(g<len)
            printf("%d\n",a[g%4]);
        else
            printf("%d\n", a[6-r%4-b%4-y%4]);
    }
    return 0;
}