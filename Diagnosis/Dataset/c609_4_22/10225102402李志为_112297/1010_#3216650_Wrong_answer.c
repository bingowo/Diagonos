#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long a,b;
    int t,i=0;
    char z[20]={"0123456789ABCDEFGHIJ"};
    char s[100];
    scanf("%lld %lld",&a,&b);
    while(a){
        t=a%b;
        a=a/b;
        if(t<0) {
            t=t-b;
            a=a+1;
        }
        s[i]=z[t];
        i++;
    }
    i--;
    for(int j=i;j>=0;j--){
        printf("%c",s[j]);
    }

    return 0;
}