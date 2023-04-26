#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    while(a%b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    char s[100];
    scanf("%s",s);
    int len = strlen(s);
    int i = 0;
    while(s[i] != '.') i++;
    int sum = 0;
    for(int j = 0;j < i;j++)
    {
        if(s[j] == '2')
            sum = sum * 3 - 1;
        else
            sum = sum * 3 + s[j] - '0';
    }
    int a = 0,b = 1;
    for(int j = 0;j < strlen - i;j++)
    {
        a = a * 3 + s[j+i+1];
        b *= 3;
    }
    int c = gcd(b,a);
    if(strchr(s,'.') == 0)
        printf("%d",sum);
    else
        printf("%d %d %d",sum,a/c,b/c);
    return 0;
}
