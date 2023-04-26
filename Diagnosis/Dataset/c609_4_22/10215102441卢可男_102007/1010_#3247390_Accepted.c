#include <stdio.h>
#include <stdlib.h>
char s[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'
,'F','G','H','I','J','K','L','M','N'};
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    int a[100]={0};
    int i=0;
    if(n==0)
    {
        printf("0");
        return 0 ;
    }
    while(n)
    {
        int tem=n%r;
        n/=r;
        if(tem<0)
        {
            tem-=r;
            n++;
        }
        a[i++]=tem;
    }
    for(int k=i-1;k>=0;k--)
    {
        printf("%c",s[a[k]]);
    }
    //ptintf("\n");
    return 0;
}
