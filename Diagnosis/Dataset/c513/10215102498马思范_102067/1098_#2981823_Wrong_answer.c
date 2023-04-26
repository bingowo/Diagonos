#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a[5]={0};
        int q,w,e,r;
        char s[101];
        scanf("%s",s);
        printf("case #%d:\n",i);
        for(int j=0;j<strlen(s);j++)
        {
            if (s[j] == '!')
                a[j%4]++;
            else
            {
                if(s[j]=='R')
                    q=j;
                if(s[j]=='B')
                    w=j;
                if(s[j]=='Y')
                    e=j;
                if(s[j]=='G')
                    r=j;
            }
        }
        printf("%d %d %d %d\n",a[q%4],a[w%4],a[e%4],a[r%4]);
    }
    return 0;
}