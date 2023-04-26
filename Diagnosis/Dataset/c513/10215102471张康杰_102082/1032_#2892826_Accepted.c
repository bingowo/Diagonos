#include <stdio.h>
#include <stdlib.h>
//sizeof(指针名)/sizeof(int)并不会返回数组长度！！！！！！！！！！！！！！
typedef struct{
    int ct[50];
    int len;
}NUM;
int cmp(const void*a,const void*b)
{
    NUM*st1,*st2;
    st1 = (NUM*)a,st2 = (NUM*)b;
    if(st1->len < st2->len)
    {
        for(int i = 0;i < st1->len - 1;i++)
        {
            if(st1->ct[i] != st2->ct[i])
                return st2->ct[i] - st1->ct[i];
        }
        return 1;
    }
    else// if(st1->len > st2->len)
    {
        for(int i = 0;i < st2->len - 1;i++)
        {
            if(st1->ct[i] != st2->ct[i])
                return st2->ct[i] - st1->ct[i];
        }
        return -1;
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N,j;
        scanf("%d",&N);
        NUM num[N];
        for(j = 0;j < N;j++)
        {
            int count = 0;
            while(scanf("%d",&num[j].ct[count++]))
            {
                if(num[j].ct[count - 1] == -1)
                {
                    num[j].len = count;
                    break;
                }
            }
        }
        qsort(num,N,sizeof(num[0]),cmp);
        for(j = 0;j < N;j++)
        {
            for(int k = 0;k < num[j].len - 1;k++)
                printf("%d%c",num[j].ct[k],(k == num[j].len - 2)?'\n':' ');

        }
    }
    return 0;
}
