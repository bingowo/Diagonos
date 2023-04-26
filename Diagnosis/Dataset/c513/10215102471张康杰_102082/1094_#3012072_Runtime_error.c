#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 121

typedef struct 
{
    int v[L],cnt,signal;
}BIGINT;

int cmp(const void*a,const void*b);

BIGINT sub(BIGINT S,BIGINT T);

BIGINT sub1(BIGINT S,BIGINT T);

BIGINT add(BIGINT S,BIGINT T);

int cmp1(BIGINT S,BIGINT T);

int main()
{
    int n,i;
    char input[L];
    scanf("%d",&n);
    BIGINT pos[n];
    for(i = 0;i < n;i++)
    {
        scanf("%s",input);
        int len = strlen(input);
        if(input[0] == '-')
        {
            pos[i].signal = -1;
            for(int j = len - 1;j >= 1;j--)
                pos[i].v[j - 1] = input[j] - '0';
            pos[i].cnt = len - 1;
        }
        else
        {
            pos[i].signal = 1;
            for(int j = len - 1;j >= 0;j--)
                pos[i].v[j] = input[j] - '0';
            pos[i].cnt = len;
        }
    }
    qsort(pos,n,sizeof(BIGINT),cmp);
    BIGINT R = sub(pos[n - 1],pos[0]);
    if(R.signal == 1);
    else if(R.signal == -1)
        putchar('-');
    else
    {
        printf("0\n");
        return 0;
    }
    for(i = R.cnt - 1;i >= 0;i--)
        printf("%d",R.v[i]);
    putchar('\n');
    return 0;
}

int cmp(const void*a,const void*b)
{
    BIGINT*st1,*st2;
    st1 = *(BIGINT**)a,st2 = *(BIGINT**)b;
    if(st1->signal > st2->signal)
        return 1;
    else if(st1->signal < st2->signal)
        return -1;
    else
    {
        if(st1->signal > 0)
        {
            if(st1->cnt < st2->cnt)
                return -1;
            else if(st1->cnt > st2->cnt)
                return 1;
            else
            {
                for(int i = st1->cnt - 1;i >= 0;i--)
                {
                    if(st1->v[i] > st2->v[i])
                        return 1;
                    else if(st1->v[i] < st1->v[i])
                        return -1;
                    else
                        continue;
                }
                return 0;
            }
        }
        else if(st1->signal < 0)
        {
            if(st1->cnt < st2->cnt)
                return 1;
            else if(st1->cnt > st2->cnt)
                return -1;
            else
            {
                for(int i = st1->cnt - 1;i >= 0;i--)
                {
                    if(st1->v[i] > st2->v[i])
                        return -1;
                    else if(st1->v[i] < st1->v[i])
                        return 1;
                    else
                        continue;
                }
                return 0;
            }
        }
        else
            return 0;
    }
}

int cmp1(BIGINT S,BIGINT T)
{
    if(S.cnt > T.cnt)
        return 1;
    else if(S.cnt < T.cnt)
        return -1;
    else
    {
        for(int i = S.cnt - 1;i >= 0;i--)
        {
            if(S.v[i] > T.v[i])
                return 1;
            else if(S.v[i] < T.v[i])
                return -1;
            else
                continue;
        }
        return 0;
    }
}

BIGINT sub(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},1,0};
    if(cmp1(S,T) > 0)
    {
        if(S.signal == 1 && T.signal == 1)
        { 
            R = sub1(S,T);
            R.signal = 1;
        }
        else if(S.signal == 1 && T.signal == -1)
        {
            R = add(S,T);
            R.signal = 1;
        }
        else if(S.signal == -1 && T.signal == 1)
        {
            R = add(S,T);
            R.signal = -1;
        }
        else if(S.signal == -1 && T.signal == -1)
        {
            R = sub1(S,T);
            R.signal = -1;
        }
    }   
    else if(cmp1(S,T) < 0)
    {
        if(S.signal == 1 && T.signal == 1)
        {
            R = sub1(T,S);
            R.signal = -1;
        }    
        else if(S.signal == 1 && T.signal == -1)
        {
            R = add(S,T);
            R.signal = 1;
        }    
        else if(S.signal == -1 && T.signal == 1)
        {
            R = add(S,T);
            R.signal = -1;
        }
        else if(S.signal == -1 && T.signal == -1)
        {
            R = sub1(T,S);
            R.signal = 1;
        }
    } 
    else
    {
        if(S.signal == 1 && T.signal == 1)
        { 
            R = sub1(S,T);
            R.signal = 0;
        }
        else if(S.signal == 1 && T.signal == -1)
        {
            R = add(S,T);
            R.signal = 1;
        }
        else if(S.signal == -1 && T.signal == 1)
        {
            R = add(S,T);
            R.signal = -1;
        }
        else if(S.signal == -1 && T.signal == -1)
        {
            R = sub1(S,T);
            R.signal = 0;
        }
    }
    return R;
}

BIGINT sub1(BIGINT S,BIGINT T)
{
    int i;
    BIGINT R = {{0},S.cnt,0};
    for(i = 0;i < S.cnt;i++)
    {
        R.v[i] = S.v[i] - T.v[i] + R.v[i];
        if(R.v[i] < 0)
        {
            R.v[i] += 10;
            R.v[i + 1]--;
        }
    }
    for(i = R.cnt - 1;i >= 0;i--)
    {
        if(R.v[i] == 0)
            R.cnt--;
    }
    return R;
}

BIGINT add(BIGINT S,BIGINT T)
{
    BIGINT R = {{0},1,0};
    int i,carry = 0;
    int len_max = (S.cnt > T.cnt)?S.cnt:T.cnt;
    for(i = 0;i < len_max;i++)
    {
        R.v[i] = R.v[i] + S.v[i] + T.v[i] + carry;
        carry = R.v[i] / 10;
        R.v[i] %= 10;
    }
    if(carry)
    {
        R.v[i] += carry;
        R.cnt = len_max + 1;
    }
    return R;
}