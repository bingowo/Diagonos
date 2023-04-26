#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int n;
    scanf("%d",&n);
    char A[100];
    long long ans=0;
    for(;i<n;i++)
    {
        A[100]='0';
        scanf("%s",&A);
        int i;
        int a[128];
        for(i=0;i<128;i++) a[i]=-1;
        int digit=0,N=1,i;char *p=A;
        a[*p]=1;
        while(*++p)
            if(a[*p]==-1)
            {
                a[*p]=digit;digit=digit?digit+1:2;N++;
            }
        if(N<2) N=2;
        long long ans=0;
        p=s;while (*p) ans =ans*N+a[*p++];
        printf("%lld\n",ans);
        
    }
    
    
    
    
    return 0;
}
