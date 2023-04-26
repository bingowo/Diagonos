#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i ++)
    {
        int N,j;
        scanf("%d",&N);
        char s[N][20];
        for(j = 0;j <N;j++)
            scanf("%s",&s[j]);
        long long int top(char *c)
        {
            if(c[0] == '-')
                return c[1];
            else return c[0];
        }
        long long int digit(char *d)
        {
            int sign = 1;
            long long int sum = 0;
            if(d[0] == '-')
            {
                 sign = -1;
                 for(int x = 1;d[x] != '\0';x ++)
                    sum = sum * 10 + d[x] - '0';
            }
            else
            {
                for(int x = 0;d[x] != '\0';x ++)
                    sum = sum * 10 + d[x] - '0';
            }
            return sum * sign;
        }

        long long int cmp(const void *a,const void *b)
        {
            long long int num1,num2;
            long long int sum1,sum2;
            char *s1,*s2;
            s1=*(char (*)[20])a; s2=*(char (*)[20])b;
            num1=top(s1);num2=top(s2);sum1 = digit(s1);sum2 = digit(s2);
            if(num1==num2)
                return sum1 - sum2;
            else
                return num2-num1;
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int k = 0;k < N;k ++)
            printf("%s%c",s[k],k == N-1?'\n':' ');

    }
    return 0;
}
