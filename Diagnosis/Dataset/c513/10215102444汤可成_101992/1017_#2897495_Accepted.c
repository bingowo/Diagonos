#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int convert(char* s, int len)
{
    int n[100] = {0};
    int i = 0;
    n['I'] = 1;
    n['V'] = 5;
    n['X'] = 10;
    n['L'] = 50;
    n['C'] = 100;
    n['D'] = 500;
    n['M'] = 1000;
    long long num = 0;
    while(i<len)
    {
        if(s[i] != 'I' && s[i] != 'X' && s[i] != 'C')
        {
            num += n[s[i]];
            i++;
        }
        else
        {
            if(n[s[i+1]]>n[s[i]])
            {
                num += (n[s[i+1]]-n[s[i]]);
                i += 2;
            }
            else
            {
                num += n[s[i]];
                i++;
            }
        }
    }
    return num;
}


int main()
{
    char s[50] = {0};
    long long int mul = 1;
    long long num = 0;
    scanf("%s", s);
    int len = strlen(s);
    int i = 0;
    int ss = 0;
    int flag = 0;
    while(i<len)
    {
        while(s[i] != '(' && i<len)
        {
            i++;
        }
        if(i == len)
        {
            if(num>=convert(s+ss, len-ss))
            {
                flag = 0;
                printf("%lld", convert(s+ss, len-ss)+num);
            }
            else
            {
                flag = 0;
                printf("%lld", convert(s+ss, len-ss)-num);
            }
            break;
        }
        else
        {
            flag = 1;
            if(ss != i) num += convert(s+ss,i-ss);
            ss = i;
            while(s[i]=='(')
            {
                mul *= 1000;
                i++;
                ss++;
            }
            int j = 0;
            while(s[i] != ')')
            {
                j++;
                i++;
            }
            if(num<convert(s+ss, j)*mul) num =convert(s+ss, j)*mul - num ;
            while(s[ss] != ')') ss++;
            while(s[ss+1]==')')ss++;
            ss++;
            i = ss;
        }
    }
    if(flag == 1)printf("%lld", num);
    return 0;
}
