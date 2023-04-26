#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,t,r;
    int i,p;
    int m=0;
    char s[100];
    char k;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&n,&r);
        if(n<0)
        {
            s[m] = '-';
            m++;
            n = -n;
        }
        while(n>0)
        {
            if( p<10 )
            {
                s[m] = (char)p;
                m++;
            }
            else
            {
                s[m] = 'A'+p-10;
                m++;
            }
            n /= r;
            printf("%s",s);
        }
    }
    return 0;
}
