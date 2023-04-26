#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char m[52];
    int cnt=1,max=1;
    scanf("%s",m);
    for(int i=1;i<strlen(m);i++){
        if(m[i]!=m[i-1])cnt++;
        else {
            if(cnt>max){max=cnt;}cnt=1;
        }
    }
    if(cnt>max)max=cnt;
    printf("%d\n",max);
    return 0;
}