#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[1000001];
    int a[26] = {0};
    while(gets(s)!=NULL)
    {
    switch(s[0])
    {
        case 'I':a[s[3]-'A'] = atoi(s+6);break;
        case 'M':
            if(s[1]=='U')
            { if(strlen(s)==9) a[s[4]-'A'] *= a[s[7]-'A'];
            else a[s[4]-'A'] =a[s[7]-'A'] * a[s[10]-'A'];}
            else if(s[2]=='D')
            {
                if(strlen(s)== 9) a[s[4]-'A'] %= a[s[7]-'A'];
                else a[s[4]-'A'] = a[s[7]-'A'] % a[s[10]-'A'];
            }
            else {a[s[4]-'A'] = a[s[7]-'A'];}
            break;
        case 'O':
            if(s[1]=='U') printf("%d\n",a[s[4]-'A']);
            else  a[s[3]-'A'] = a[s[3]-'A']|a[s[6]-'A'];
            break;
        case 'D':
            if(strlen(s)==9) a[s[4]-'A'] /= a[s[7]-'A'];
            else a[s[4]-'A'] =a[s[7]-'A'] / a[s[10]-'A'];
            break;
        case 'S':
            if(strlen(s)==9) a[s[4]-'A'] -= a[s[7]-'A'];
            else a[s[4]-'A'] =a[s[7]-'A'] - a[s[10]-'A'];
            break;
        case 'A':
            if(s[1]=='D')
            {if(strlen(s)==9) a[s[4]-'A'] += a[s[7]-'A'];
            else a[s[4]-'A'] = a[s[7]-'A'] + a[s[10]-'A'];}
            else{
                a[s[4]-'A'] = a[s[4]-'A']&a[s[7]-'A'];
            }
            break;
        case 'X':
            if(s[1]=='C') {
                int t = a[s[5]-'A'];
                a[s[5]-'A'] = a[s[8]-'A'];
                a[s[8]-'A'] = t;
            }
            else a[s[4]-'A'] = a[s[4]-'A']^a[s[7]-'A'];
            break;
    }}
    return 0;
}

