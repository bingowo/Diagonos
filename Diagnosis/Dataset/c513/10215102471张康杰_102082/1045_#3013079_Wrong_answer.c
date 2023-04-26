#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 101

typedef struct
{
    char origin[L],temp[L];
    int pos[L],len;
}STR;

void delete(STR*S)
{
    int i,len,cnt = 0;
    int cnt1 = 1;
    len = strlen(S->origin);
    S->temp[cnt] = S->origin[0];
    for(i = 1;i < len;i++)
    {
        if(S->origin[i] == S->origin[i - 1])
        {
            cnt1++;
        }
        else
        {
            S->pos[cnt] = cnt1;
            cnt1 = 1;
            cnt++;
            S->temp[cnt] = S->origin[i];
        }
    }
    S->pos[cnt] = cnt1;
    cnt++;
    S->len = cnt;
    S->temp[cnt] = '\0';
}

int cmp(const void*a,const void*b)
{
    static int i = 0;
    STR*st1,*st2;
    st1 = (STR*)a,st2 = (STR*)b;
    int out = st1->pos[i] - st2->pos[i];
    i++;
    return out;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    STR input[n];
    for(i = 0;i < n;i++)
    {
        scanf("%s",input[i].origin);
        delete(&input[i]);
    }
    for(i = 1;i < n;i++)
    {
        if(strcmp(input[i].temp,input[i - 1].temp) == 0)
            continue;
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    int steps = 0;
    for(i = 0;i < input[0].len;i++)
    {
        qsort(input,n,sizeof(STR),cmp);
        if(n % 2 == 1)
        {
            for(int j = 0;j < n;j++)
            {
                steps += abs(input[n / 2].pos[i] - input[j].pos[i]);
            }
        }
        else
        {
            int temp = (input[n / 2].pos[i] + input[n / 2 - 1].pos[i]) / 2;
            for(int j = 0;j < n;j++)
            {
                steps += abs(input[j].pos[i] - temp);
            }
        }
    }
    printf("%d",steps);
    return 0;
}