#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long res =0;
    char s[200];
    long long num[200];
    scanf("%s",s);
    int cnt = 0;
    for(int i =0;i<strlen(s);i++)
    {
        switch (s[i])
        {
        case 'I':
            num[cnt++] = 1;
            break;
        case 'C':
            num[cnt++] = 100;
            break;
         case 'M':
            num[cnt++] =1000;
            break;
        case 'V':
            num[cnt++] = 5;
            break;
        case 'X':
            num[cnt++] =10;
            break;
        case 'L':
            num[cnt++] = 50;
            break;
        case 'D':
            num[cnt++] = 500;
            break;
        }
    }
    long long cou = 1;
    int co = strlen(s)-1;
    for(;co>=0;co--)
    {
        if(s[co] == ')')
        {
            cou*=1000;
            continue;
        }
        else if(s[co] == '(')
        {
            cou/=1000;
            continue;
        }
        else
        {
            int sym = 1;
            switch (s[co])
            {
            case 'I':
                if(res > 1)sym = -1;
                break;
            case 'C':
                if(res>100)sym=-1;
                break;
            case 'X':
                if(res>10)sym = -1;
                break;
            }
            res = res + sym* cou * num[--cnt];
        }
    }
    printf("%lld",res);
    return 0;
}
