#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100] = {};
    scanf("%s",s);
    long long A = 0, B = 0, C = 1;
    int i = 0;
    for (;s[i]&&s[i]!='.';i++)
    {
        if (s[i]!='2') A = A*3+s[i]-'0';
        else A = A*3-1;
    }
    if (strchr(s,'.'))
    {
        for (i++;s[i];i++)
        {
            if (s[i]!='2') B = B*3+s[i]-'0';
            else B = B*3-1;
            C *= 3;
        }
    }
    if (B*C<0&&A>0) {A--; B += C;}
    else if (B*C>0&&A<0) {A++; B = C-B;}
    if (A) printf("%lld ",A);
    if (B) printf("%lld %lld",B,C);
    if (A==0&&B==0) printf("0");
    printf("\n");
    return 0;
}