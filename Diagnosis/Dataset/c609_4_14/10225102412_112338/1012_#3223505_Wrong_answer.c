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
            n += (s[j]-'0')*pow(8,1-j);
        }
        printf("case #%d:\n%lf\n",i,n);
    }
    return 0;
}