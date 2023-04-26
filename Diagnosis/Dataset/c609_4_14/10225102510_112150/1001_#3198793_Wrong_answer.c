#include <stdio.h>
#include <stdlib.h>
int main()
{
    int b,T;
    long long int a;
    scanf("%d",&T);
    for(int o=0;o<T;o+=1)
    {
        scanf("%lld",&a);
        scanf("%d",&b);
        char s[32];
        int i=0,n=0;
        if(a<0)
        {
            s[i]="-";
            i=1;
            n=1;
            a=-a;
        }
        while(a!=0)
        {
            s[i]=a%b<10?a%b:(char)("A"+a%b-10);
            i=i+1;
            a=a/b;
        }
        char m;
        while(n<i)
        {
            m=s[i];
            s[i]=s[n];
            s[n]=m;
            i--;
            n++;
        }
        printf("%s\n",s);
    }
    return 0;
}
