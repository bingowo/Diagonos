#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%s",&s);
    long long res=1;
    if(s[0]!=s[1]) res=2;
    for(int i=1;i<strlen(s)-1;i++)
    {
        int weight=1;
        if(s[i]!=s[i-1]) weight++;
        if(s[i]!=s[i+1]) weight++;
        res=res*weight;
    }
    if(s[strlen(s)-2]!=s[strlen(s)-1])
        res=res*2;
    if(strlen(s)==1)
        res=1;
    printf("%lld",res);
    return 0;
}
