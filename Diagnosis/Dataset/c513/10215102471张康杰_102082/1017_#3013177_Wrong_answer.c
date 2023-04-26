#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define L 51

typedef unsigned long long int ULL;

int main()
{
    char input[L];
    scanf("%s",input);
    int table[128],len = strlen(input);
    ULL ar[50] = {0};
    int base = 1,cnt = 0,i;
    ULL temp[50];
    table['I'] = 1,table['V'] = 5,table['X'] = 10,table['L'] = 50;
    table['C'] = 100,table['D'] = 500,table['M'] = 1000;
    for(i = 0;i < len;i++)
    {
        if(input[i] == '(')
            base *= 1000;
        else if(input[i] == ')')
            base /= 1000;
        else
        {
            ar[cnt++] = table[input[i]] * base;
        }
    }
    memcpy(temp,ar,50*sizeof(ULL));
    for(i = cnt - 1;i >= 1;i--)
    {
        if(ar[i] > ar[i - 1])
            temp[i - 1] = temp[i] - temp[i - 1];
        else
            temp[i - 1] = temp[i - 1] + temp[i];
    }
    printf("%llu",temp[0]);
    return 0;
}
