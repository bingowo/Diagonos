#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 1001
#define M 501

void str2dou(char a[],int b[])
{
    int i,len = strlen(a);
    int pos,l;
    for(pos = 0;pos < len;pos++)
    {
        if(a[pos] == '.')
            break;
    }
    for(i = pos + 1,l = M;i < len;i++)
    {
        b[l++] = a[i] - '0';
    }
    for(i = pos - 1,l = M;i >= 0;i--)
    {
        b[--l] = a[i] - '0';
    }
}

void DouSub(int ar1[],int ar2[],int N)
{
    int i,flag;
    for(i = 0;i < L;i++)
    {
        if(ar1[i] > ar2[i])
            flag = 1;
        else if(ar1[i] == ar2[i])
            continue;
        else
            flag = 0;
    }
    if(i == L)
        flag = 1;
    if(flag)
    {
        for(i = L - 1;i >= M + N;i--)
        {
            ar1[i] = ar1[i] - ar2[i];
            if(ar1[i] < 0)
            {
                ar1[i] += 10;
                ar1[i - 1]--;
            }
        }
        if(ar1[M + N] >= 5)
            ar1[M + N - 1]++;
        for(i = M + N - 1;i > 0;i--)
        {
            ar1[i] = ar1[i] - ar2[i];
            if(ar1[i] < 0)
            {
                ar1[i] += 10;
                ar1[i - 1]--;
            }           
        }
        ar1[0] = ar1[0] - ar2[0];
    }
    else
    {
        for(i = L - 1;i >= M + N;i--)
        {
            ar2[i] = ar2[i] - ar1[i];
            if(ar2[i] < 0)
            {
                ar2[i] += 10;
                ar2[i - 1]--;
            }
        }
        if(ar2[M + N] >= 5)
            ar2[M + N - 1]++;
        for(i = M + N - 1;i > 0;i--)
        {
            ar2[i] = ar2[i] - ar1[i];
            if(ar2[i] < 0)
            {
                ar2[i] += 10;
                ar2[i - 1]--;
            }           
        }
        ar2[0] = ar2[0] - ar1[0];
        memcpy(ar1,ar2,sizeof(int)*L);   
    }
}

int main()
{
    char s1[M],s2[M];
    int dou1[L] = {0},dou2[L] = {0};
    int N,i;
    scanf("%s %s %d",s1,s2,&N);
    str2dou(s1,dou1);
    str2dou(s2,dou2);
    DouSub(dou1,dou2,N);
    int flag = 1;
    for(i = 0;i < M + N;i++)
    {
        if(i == M - 1)
        {
            printf("%d",dou1[i]);
        }
        else if(flag && dou1[i] == 0)
            continue;
        else
        {
            flag = 0;
            printf("%d",dou1[i]);
        }
    }
    putchar('\n');
    return 0;
}


