#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define L 51

typedef long long int LLD;

int main()
{
    char input[L];
    scanf("%s",input);
    int table[128],ar[50] = {0},len = strlen(input);
    int base = 1,cnt = 0,i;
    int temp[50];
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
    memcpy(temp,ar,50*sizeof(int));
    for(i = cnt - 1;i >= 1;i--)
    {
        if(ar[i] > ar[i - 1])
            temp[i - 1] = temp[i] - temp[i - 1];
        else
            temp[i - 1] = temp[i - 1] + temp[i];
    }
    printf("%d",temp[0]);
    return 0;
}
