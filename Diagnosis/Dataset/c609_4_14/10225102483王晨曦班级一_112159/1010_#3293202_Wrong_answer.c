#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

void interchange(int a,int b)
{
    char c[N],h[N]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int cnt=0,r;
            while(a!=0)
            {
                r=a%b;
                a=a/b;
                if(r<0)
                {
                    r=r-b;
                    a++;
                }
                c[cnt]=h[r];
                cnt++;
            }
            for(int i=(cnt-1);i>=0;i--) printf("%c",c[i]);
            printf("\n");
}

int main()
{
    int n,m; scanf("%d %d",&n,&m);
    interchange(n,m);
    return 0;
}