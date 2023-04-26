#include <stdio.h>
#include <stdlib.h>
#define MXL 100

int gcd(int x, int y)
{ if (y)
        return gcd(y, x%y);
    else
        return x;
}

int main()
{
    char input[MXL];
    char* p=input;
    long long A=0,B=0,C=1;
    for (int i=0;i<MXL;i++)input[i]='\0';
    scanf("%s",input);
    if ( input[0]=='0' && input[1]=='\0' ){printf("0\n");return 0;}
    while(*p!='.' && *p!='\0'){
        A*=3;
        if(*p=='2'){
            A += (-1); p++;
        }
        else{
            A += (*p-'0'); p++;
        }
    }
    if(*p=='.'){
        p++;
        while(*p!='\0'){
            B*=3;C*=3;
            if(*p=='2'){
                B +=(-1);
                p++;
            }
            else{
                B += (*p-'0');
                p++;
            }
        }
        long long G=gcd(B,C);
        if(G<0)G=-G;
        B/=G;C/=G;
        if(B<0&&A>0){
            B+=C;
            A-=1;
        }
        if(B>0&&A<0){
            B=C-B;
            A+=1;
        }
        if (A==0)printf("%lld %lld\n",B,C);
        else printf("%lld %lld %lld\n",A,B,C);
    }
    else printf("%lld\n",A);
    return 0;
}
