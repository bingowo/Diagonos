#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int T,i,j;char s[100];double n=0;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%s",s);
        int len=strlen(s);
        for (j=2;j<len;j++){
            n += (s[j]-'0')/pow(8,j-1);
        }
        printf("case #%d:\n%.3*(len-2)f\n",i,n);
    }
    return 0;
}