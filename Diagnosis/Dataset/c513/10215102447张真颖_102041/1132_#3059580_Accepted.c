#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        long long int n;
        int r;
        scanf("%lld%d",&n,&r);
        int sum=0;
        while(n>0)
        {
            sum+=n%r;
            n/=r;
        }
        char s[40]={0};
        int i=0;
        while(sum>0)
        {
            int tmp=sum%r;
            if(tmp>=10) s[i]=tmp-10+'A';
            else s[i]=tmp+'0';
            sum/=r;
            i++;
        }
        printf("case #%d:\n",cas);
        for(int i=strlen(s)-1;i>=0;i--)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;

}