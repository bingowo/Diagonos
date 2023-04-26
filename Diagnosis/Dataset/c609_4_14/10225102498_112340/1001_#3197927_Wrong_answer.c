#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,t,r;
    int i,p;
    int j;
    char s[100];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        int m = 0;
        scanf("%d%d",&n,&r);
        if(n<0)
        {
            s[m] = '-';
            m++;
            n = -n;
        }
        while(n>0)
        {
            p = n%r;
            if(p<10)
            {
                s[m] = '0'+p;
                m++;
            }
            else
            {
                s[m] = 'A'+p-10;
                m++;
            }
            n /= r;
        }
        for(j=m-1; j>=0; j--)
            printf("%c",s[j]);
    }
    return 0;
}
