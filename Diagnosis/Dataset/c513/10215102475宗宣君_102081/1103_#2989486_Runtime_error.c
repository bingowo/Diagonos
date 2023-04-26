#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100];
    int a[4] = {0},i = 0;
    while(i<500000)
    {
    if(gets(s)==NULL) break;
    switch(s[0])
    {
        case 'I':a[s[3]-'A'] = atoi(s+6);break;
        case 'M':
            if(s[1]=='U') a[s[4]-'A'] *= a[s[7]-'A'];
            else {int t = a[s[4]-'A'];a[s[4]-'A'] = a[s[7]-'A'];a[s[7]-'A']=t;}
            break;
        case 'O':printf("%d\n",a[s[4]-'A']);break;
        case 'D':a[s[4]-'A'] /= a[s[7]-'A'];break;
        case 'S':a[s[4]-'A'] -= a[s[7]-'A'];break;
        case 'A':a[s[4]-'A'] += a[s[7]-'A'];break;
    }i++;
    }
    return 0;
}
