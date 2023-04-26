#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long s[30];
        long long n;
        scanf("%lld",&n);
        int j=0;
        do {
            s[j++] = n % 2333;
            n /= 2333;
        }
        while(n);
        if(j>0)
        {
            for(int i=j-1;i>=0;i--)
            {
                printf("%lld",s[i]);
                printf("%s",i==0?"\n":" ");
            }
        }
        else
        {
            printf("%lld\n",n);
        }

    }
    return 0;
}