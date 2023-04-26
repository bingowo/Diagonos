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
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[131];
        scanf("%s",s);
        int len=strlen(s);
        int count=0;
        for(int j=0;s[j]!='\0';j++){
            unsigned char c=s[j];
            while(c){
                if(c%2) count++;
                c>>=1;
            }
        }
        int size = 8*strlen(s);
        int g=gcd(count,size);
        int fz=count/g;
        int fm=size/g;
        printf("%d/%d\n",fz,fm);
    }
    return 0;
}
