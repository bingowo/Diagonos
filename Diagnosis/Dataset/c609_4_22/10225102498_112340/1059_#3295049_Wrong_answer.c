#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long long cnt;
    int flag;
    char s[105];
}number;

int cmp(const void* a, const void* b)
{
    number p = *(number*)a, q = *(number*)b;
    int i1 = p.flag;
    int i2 = q.flag;
    if(p.cnt != q.cnt)
    {
        if(p.cnt >= q.cnt)
            return 1;
        return -1;
    }
    if(p.cnt == q.cnt)
    {
        if(i1 != i2)
            return i2 - i1;
        while(p.s[i1] != q.s[i1])
            i1++;
        if(p.cnt >= 0)
        {
            if(p.s[i1]-'0' >= q.s[i1] - '0')
                return -1;
            return 1;
        }
        else
        {
            if(p.s[i1]-'0' >= q.s[i1] - '0')
                return 1;
            return -1;

        }

    }
}


int main()
{
    number num[100];
    int n, i;
    int j = 1;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &num[i].s);
        num[i].cnt = 0;
        num[i].flag = 0;
        long long ten = 1;
        while(num[i].s[j]!='.'&&num[i].s[j]!=0)
        {
            num[i].cnt += (num[i].s[j] - '0')*ten;
            ten *= 10;
            j++;
        }
        if(num[i].s[j]=='.')
        {
            j++;
            num[i].flag = j;
        }
        if(num[i].s[0] == '-')
            num[i].cnt *= -1;
        j=1;
    }

    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0; i<n; i++)
        printf("%s\n", num[i].s);

    return 0;
}
