#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEF";

void trans(long long int N, int R)
{
    if(N>0)
    {
        trans(N/R,R);
        printf("%c",table[N%R]);
    }
}

int main()
{
    int A,B;
    long long int n=0;
    char s[50];
    scanf("%d",&A);
    scanf("%s",s);
    scanf("%d",&B);
    for(int i=0; s[i]; i++)
    {
        int t;
        if(s[i]<='9')
            t=s[i]-'0';
        else if(s[i]>='A'&&s[i]<='Z')
            t=s[i]-'A'+10;
        else
            t=s[i]-'a'+10;
        n=n*A+t;
    }
    if(n==0)
        printf("0");
    else
        trans(n,B);
    return 0;
}
