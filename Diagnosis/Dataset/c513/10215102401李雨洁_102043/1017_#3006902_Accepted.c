#include<stdio.h>
#include<string.h>

int main()
{
    int R[130];
    R['I'] = 1, R['V'] = 5, R['X'] = 10, R['L'] = 50, R['C'] = 100, R['D'] = 500, R['M'] = 1000;
    long long flag = 1;
    long long sum = 0;
    char s[1000];
    scanf("%s",s);
    int len = strlen(s);
    long long each[1000];
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case '(':
            flag *= 1000;
            break;
        case ')':
            flag /= 1000;
            break;

        default:
            each[count++] = flag * R[s[i]];
            break;
        }
    }
    for(int i = 0; i < count; i++)
    {
        if(i == count - 1)
            sum += each[i];

        else
            sum += ((each[i] < each[i + 1]) ? -each[i] : each[i]);
    }
    printf("%lld\n",sum);
    return 0;
}
