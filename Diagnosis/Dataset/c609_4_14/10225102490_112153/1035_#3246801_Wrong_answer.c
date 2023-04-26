#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int p;
    int cnt;
} Candidate;

int cmp(Candidate *a,Candidate *b)
{
    return b->cnt - a->cnt;
}

int main()
{
    int T;
    scanf("%d",&T);
    int flag1,flag2;
    for (int p = 0; p < T; p++)
    {
        char *s1 = (char*)malloc(sizeof(char) * 101);
        char *s2 = (char*)malloc(sizeof(char) * 101);
        scanf("%s",s1);
        int ori = strlen(s1);
        //printf("%s\n",s1);
        do
        {
            int i, j;
            flag1 = 0;
            for (i = 0, j = 0; i < strlen(s1);i++)
            {
                flag2 = 0;
                char c = s1[i];
                while (c == s1[i+1])
                {
                    i++;
                    flag1 = 1;
                    flag2 = 1;
                }
                if (flag2 == 1)
                {
                    //printf("*i=%d ",i);
                    continue;
                }
                if (s1[i] != s1[i+1])
                {
                    s2[j] = s1[i];
                    j++;
                }
                //printf("i=%d ",i);
            }
            s2[j] = '\0';
            //printf("%s\n",s2);
            if (s2[0] == '\0')
            {
                printf("%d",ori+1);
                return 0;
            }
            strcpy(s1,s2);
            //printf("%s\n",s1);
            memset(s2,0,101);
        } while (flag1 == 1);
        Candidate *d = (Candidate *)malloc(sizeof(Candidate) * strlen(s1));
        int i,j;
        for (i = 1, j = 0;i < strlen(s1)-1; i++)
        {
            if (s1[i-1] == s1[i+1])
            {
                d[j].p = i;
                j++;
            }
        }
        for (int i = 0; i < j; i++)
        {
            //printf("%d ",d[i].p);
        }
        for (int i = 0; i < j; i++)
        {
            d[i].cnt = 0;
        }
        //printf("\n");
        for (int i = 0; i < j; i++)
        {
            int u = 1;
            while (d[i].p-u >=0 && s1[d[i].p-u] == s1[d[i].p+u])
            {
                d[i].cnt++;
                u++;
            }
            //u--;
            //printf("%d %d %d\n",i,d[i].p-u,d[i].p+u);
        }
        for (int i = 0; i < j; i++)
        {
            //printf("%d ",d[i].cnt);
        }
        //printf("\n");

        qsort(d,j,sizeof(Candidate),cmp);
        printf("case #%d:\n",p);
        if (d[0].cnt == 0)
            printf("%d\n",ori-strlen(s1)+(d[0].cnt+1)*2);
        else
            printf("%d\n",ori-strlen(s1)+3);
        free(s1);free(s2);free(d);
    }
}