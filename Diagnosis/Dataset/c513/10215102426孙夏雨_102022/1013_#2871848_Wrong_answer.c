#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[31];
    scanf("%s",s);
    int i=0;
    int length=strlen(s);
    long long int A=0,B=0,C=1;
    while((s[i]!='.')&&(i<length)){
        int x=s[i]-'0';
        if(x==2) x=-1;
        A=A*3+x;
        i++;
    }
    if(i<length){
        i++;
        while(i<length){
            int y=s[i]-'0';
            if(y==2) y=-1;
            B=B*3+y;
            C=C*3;
            i++;
        }
    }
    if(B==0) printf("%lld",A);
    else if(B>0&&A>0) printf("%lld %lld %lld",A,B,C);
    else if(B>0&&A<0) printf("%lld %lld %lld",A+1,C-B,C);
    else printf("%lld %lld %lld",A-1,C+B,C);
    return 0;
}
