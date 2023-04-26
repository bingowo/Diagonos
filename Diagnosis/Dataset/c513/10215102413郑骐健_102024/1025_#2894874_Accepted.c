#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char st[30];
    int n;
}str;

int cmp (const void*p1,const void *p2)
{
    str*p_1 = (str*)p1;
    str*p_2 = (str*)p2;
    if(p_1->n < p_2->n)return 1;
    else if(p_1->n == p_2->n)return strcmp(p_1->st,p_2->st);
    else return 0;
}
int main()
{
    int t;

    scanf("%d",&t);
    for(int i = 0;i < t ;i++)
    {
        int N;
        str s[200];
        scanf("%d",&N);
        for(int z = 0;z < N;z++ )
        {
            scanf("%s",s[z].st);
            s[z].n = 0;
            int a[26]= {0};
            for(int g =0;g<strlen(s[z].st);g++)
            {
                if(a[s[z].st[g] - 'A'] == 0)a[s[z].st[g] - 'A'] = 1;
            }

            for(int g=0;g < 26;g++)
            {
                if(a[g])s[z].n++;
            }
        }
        qsort(s,N,sizeof(str),cmp);
        printf("case #%d:\n",i);
            for(int q=0;q<N;q++)
            {
                printf("%s\n",s[q].st);
            }
    }



    return 0;
}
