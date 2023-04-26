#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n=0;
    scanf("%d",&T);
    while (n<T)
    {
        char ch;
        long long int rs;
        while ((scanf("%c",&ch))!='\n')
        {
            if (ch=='1') rs=(rs+1)*3;
            if (ch=='0') rs=(rs+0)*3;
            if (ch=='-') rs=(rs-1)*3;
        }
        printf("case #%d:\n",n);
        printf("%lld\n",rs);
        n++;
    }
    return 0;
}