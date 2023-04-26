#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n=0;
    scanf("%d",&T);
    while (n<T)
    {
        char s[20];
        int i=0;
        long long int rs;
        while ((scanf("%c",s[i]))!='\n')
        {
            if (s[i]=='1') rs=(rs+1)*3;
            if (s[i]=='0') rs=(rs+0)*3;
            if (s[i]=='-') rs=(rs-1)*3;
            i++;
        }
        printf("case #%d:\n",n);
        printf("%lld\n",rs);
        n++;
    }
    return 0;
}
