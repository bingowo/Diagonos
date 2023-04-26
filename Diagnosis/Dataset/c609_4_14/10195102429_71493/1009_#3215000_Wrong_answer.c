#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}
int main()
{
    int t;
    int k=8;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[121];
        scanf("%s",s);
        int len=strlen(s);
        int count=0;
        for(int j=0;j<len;j++){
            char c=s[j];
            for(int m=0;m<8;m++){
                count+=c%2;
                c/=2;
            }
        }
        int g=gcd(count,k);
        int fz=count/g;
        int fm=k/g;
        printf("%d/%d",fz,fm);
    }
    return 0;
}
