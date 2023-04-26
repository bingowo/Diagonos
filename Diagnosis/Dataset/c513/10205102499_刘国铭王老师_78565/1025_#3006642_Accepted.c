#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[21];
    int diffchar;
}Line;

int cmp(const void *a,const void *b)
{
    if((*(Line *)a).diffchar!=(*(Line *)b).diffchar)
        return (*(Line *)a).diffchar<(*(Line *)b).diffchar;
    else
        return strcmp((*(Line *)a).s,(*(Line *)b).s);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int num;
        scanf("%d",&num);
        Line line[101];
        for(int j=0;j<num;j++)
        {
            scanf("%s",line[j].s);
            line[j].diffchar=0;
        }
        /* for(int j=0;j<num;j++)
        {
            printf("%s\n",line[j].s);
        }*/
        for(int j=0;j<num;j++)
        {
            int cha[26]={0};
            int len=strlen(line[j].s);
            for(int k=0;k<len;k++)
            {
                char c=line[j].s[k];
                if(cha[c-65]==0)
                {
                    cha[c-65]=1;
                    line[j].diffchar++;
                }
                else
                    continue;
            }
        }
         /*for(int j=0;j<num;j++)
        {
            printf("%d ",line[j].diffchar);
        }
        printf("\n");*/
        qsort(line,num,sizeof(Line),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<num;j++)
            printf("%s\n",line[j].s);
    }
    return 0;
}
