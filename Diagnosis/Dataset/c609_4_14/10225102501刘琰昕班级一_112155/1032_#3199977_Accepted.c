#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50]={0},*p=s;
    scanf("%s",s);
    int ans=1,n=1;
    while(*(p+1))
    {
        if(*p!=*(p+1))n++;
        else
        {
            if(ans<n)ans=n;
            n=1;
        }
        p++;
    }
    if(ans<n)ans=n;
    printf("%d",ans);
}
