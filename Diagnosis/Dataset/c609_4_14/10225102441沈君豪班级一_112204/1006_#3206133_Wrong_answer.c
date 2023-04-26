#include <stdio.h>
#include <string.h>

int main()
{
    int T,x,y;
    char s[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        x=strlen(s);
        y=1*x+0;
        for(int j=2;j<x;j++){
            y=y*x+j;
        }
        printf("case #%d:\n%d\n",i,y);
    }
    return 0;
}
