#include <stdio.h>
#include <stdlib.h>


int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int a[25]= {0};
    int i=0;
    for(int j=0; j<len; j++)
    {
        if(s[j]==',') i++;
        if(s[j]>='0' && s[j]<='9') a[i]=a[i]*10+s[j]-'0';
    }
    long long int ans=0;
    int b[15]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int x=0;
    for(int j=0; j<=i; j++)
    {
        x=1;
        for(int k=0;k<j;k++) x=x*b[k];
        printf("%d %d\n",x,a[i-j]);
        ans+=x*a[i-j];
    }
    printf("%lld\n",ans);
    return 0;
}
