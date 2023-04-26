#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,n;
    char s[100] = {0};
    char S[100] = {0};
    char *result;
    long ret;
    scanf("%d%s%d",&a,s,&n);
    ret = strtol(s,result,a);
    itoa(ret,S,n);
    printf("%s",S);
    return 0;
}