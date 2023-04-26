#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int flag;
    char s[105];
    char str[105];
}number;

int cmp(const void* a, const void* b)
{
    number p = *(number*)a, q = *(number*)b;
    int i1 = p.flag;
    int i2 = q.flag;
    int i = 0;
    int lep = strlen(p.str), leq = strlen(q.str);
    if(strcmp(p.str,q.str))
    {
        if(p.s[0]!='-'&&q.s[0]=='-')
            return 1;
        if(p.s[0]=='-'&&q.s[0]!='-')
            return -1;
        
        while(p.str[i] == q.str[i])
            i++;
                
        if(p.s[0]!='-'&&q.s[0]!='-')
        {
            if(lep > leq)
                return 1;
            if(lep < leq)
                return -1;
            while(p.str[i] == q.str[i])
                i++;
            if(p.str[i] > q.str[i])
                return 1;
            return -1;
        }
        
        if(p.s[0]=='-'&&q.s[0]=='-')
        {
            
            if(lep > leq)
                return -1;
            if(lep < leq)
                return 1;
            while(p.str[i] == q.str[i])
                i++;
            if(p.str[i] > q.str[i])
                return -1;
            return 1;
        }
    }

    while(p.s[i1] == q.s[i1])
        i1++;
    if(p.s[0] != '-')
    {
        if(p.s[i1] <= q.s[i1])
            return -1;
        return 1;
    }
    else
    {
        if(p.s[i1] <= q.s[i1])
            return 1;
        return -1;
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
        num[i].flag = 0;
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
            if(num[i].s[j]!='+' && num[i].s[j]!='-')
                num[i].str[j] = num[i].s[j];
        }
    }

    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0; i<n; i++)
        printf("%s\n", num[i].s);

    return 0;
}
