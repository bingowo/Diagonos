#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long long cnt;
    int flag;
    char s[105];
    char str[105];
}number;

/*long long ati(char* s)
{
    long long cnt = 0;
    long long ten = 1;
    int i = 0;
    if(s[0]=='+'||s[0]=='-')
        i = 1;
    while(s[i]!='.'&&s[i]!=0)
    {
        ten *= 10;
        i++;
    }
    ten /= 10;
    if(s[0]=='+'||s[0]=='-')
        i = 1;
    else
        i = 0;
    while(ten > 0)
    {
        cnt += (s[i]-'0')*ten;
        i++;
        ten /= 10;
    }
    if(s[0] == '-')
        cnt *= -1;

    return cnt;
}*/

int cmp(const void* a, const void* b)
{
    number p = *(number*)a, q = *(number*)b;
    int i1 = p.flag;
    int i2 = q.flag;
    if(strcmp(p, q))
    {
        while(p.s[i] == q.s[i]);
        return -1;
    }
    if(p.cnt == q.cnt)
    {
        while(p.s[i1] == q.s[i1])
            i1++;
        if(p.cnt >= 0)
        {
            if(p.s[i1]-'0' <= q.s[i1] - '0')
                return -1;
            return 1;
        }
        else
        {
            if(p.s[i1]-'0' <= q.s[i1] - '0')
                return 1;
            return -1;
        }
    }
}

int main()
{
    number num[100];
    int n, i;

    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        int j = 0;
        scanf("%s", &num[i].s);
        //num[i].cnt = ati(num[i].s);
        num[i].flag = 0;

        /*long long ten = 1;
        if(num[i].s[j]=='+'||num[i].s[j]=='-')
            j++;
        while(num[i].s[j]!='.'&&num[i].s[j]!=0)
        {
            if(num[i].s[0]=='+'||num[i].s[0]=='-')
                str[j-1] = num[i].s[j];
            else
                str[j] = num[i].s[j];
            j++;
        }
        num[i].cnt = atoi(str);*/
        int len = strlen(num[i].s);
        for(j=0; j<=len; j++)
        {
            if(j==len)
                num[i].flag = 0;
            if(num[i].s[j]=='.')
            {
                j++;
                num[i].flag = j;
                break;
            }
            num[i].str[j] = num[i].s[j];
        }
    }
    //printf("%d %d\n", num[0].cnt, num[1].cnt);

    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0; i<n; i++)
        printf("%s\n", num[i].s);

    return 0;
}
