#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i,j;
    char s[51];
    int c[51];
    scanf("s",s);
    c[0]=1;
    for(i=1;s[i]!=EOF;i++){
        if(s[i-1]!=s[i]) c[i]=c[i-1]+1;
        else c[i]=1;

    }
    int n=1;
     for(j=1;j<i;j++){
        if(c[i-1]<c[i])  n=c[i];

    }
    printf("%d",n);
    return 0;

}