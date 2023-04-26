#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n1,n2;
    char *result;
    char s[100] = {0};
    char S[100] = {0};
    scanf("%d %s %d",&n1,s,&n2);
    long long res = strtol(s,&result,n1);
    itoa(res,S,n2);
    printf("%s",S);
    return 0;
}