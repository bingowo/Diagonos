#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
    char s[17];
    long long int val;
}str;

int cmp(const void*a, const void*b)
{
    str* pa = (str*)a;
    str* pb = (str*)b;
    if(pa->val > pb->val) return 1;
    else if(pa->val < pb->val) return -1;
    else return strcmp(pa->s, pb->s);
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    int arr[123] = {0};
    str s[10001] = {0};
    for(i = 0; i<T; i++)
    {
        scanf("%s", s[i].s);
        int j = 0;
        for(j = 0; j<123; j++)
        {
            arr[j] = -1;
        }
        int num = 0;
        int len = strlen(s[i].s);
        for(j = 0; j<len; j++)
        {
            if(arr[s[i].s[j]] == -1 && num == 0)
            {
                arr[s[i].s[j]] = 1;
                num++;
            }

            else if(arr[s[i].s[j]] == -1 && num == 1)
            {
                arr[s[i].s[j]] = 0;
                num++;
            }
            else if(arr[s[i].s[j]] == -1)
            {
                arr[s[i].s[j]] = num++;
            }
        }
        if(num<=1) num = 2;
        s[i].val = 0;
        for(j = 0; j<len; j++)
        {
            s[i].val = s[i].val * num + arr[s[i].s[j]];
        }
    }
    qsort(s, T, sizeof(s[0]), cmp);
    for(i = 0; i<T; i++)
    {
        printf("%s\n", s[i].s);
    }
    return 0;
}
