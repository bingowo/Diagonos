#include <stdio.h>
#include <string.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    int i,res = 1;
    for(i = 0;i<strlen(s);i++)
    {
        if(i==1||i==strlen(s)-1)
           res = res * 2;
        else res = res * 3;
    }
    printf("%d",res);
    return 0;
}
