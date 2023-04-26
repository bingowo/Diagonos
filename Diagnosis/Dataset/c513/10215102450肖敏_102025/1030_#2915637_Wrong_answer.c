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
        int top(char *c)
        {
            if(c[0] == '-')
                return c[1];
            else return c[0];
        }

        int cmp(const void *a,const void *b)
        {
            int num1,num2;
            char *s1,*s2;
            s1=*(char (*)[20])a; s2=*(char (*)[20])b;
            num1=top(s1);num2=top(s2);
            if(num1==num2)
                return strcmp(s1,s2);
            else
                return num1-num2;
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int k = 0;k < N;k ++)
            printf("%s%c",s[k],k == N-1?'\n':' ');

    }
    return 0;
}
