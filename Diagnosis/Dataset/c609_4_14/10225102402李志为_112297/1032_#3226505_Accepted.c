#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    int t,num=1,res=1;
    scanf("%s",s);
    t=strlen(s);
    for(int i=1;i<t;i++){
        if(s[i]==s[i-1]) {
            num = 1;
        }
        else num++;
        if(res<num) res=num;
    }
    printf("%d",res);
    return 0;
}