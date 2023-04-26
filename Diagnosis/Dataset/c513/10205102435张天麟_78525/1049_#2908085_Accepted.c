#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[501];
}danci;
int cmp(const void *a,const void *b)
{
    return strcmp(((danci*)a)->s,((danci*)b)->s);
}
int main()
{
    int T,n;
    char c;
    scanf("%d",&T);
    scanf("%c",&c);
    for(n=0;n<T;n++)
    {
        int i=0,j=0,k=0;
        danci dc[500];
        scanf("%c",&c);
        while(c!='\n')
        {
            if(c>='a'&&c<='z')
            {
                dc[i].s[j]=c;
                j++;
                k=1;
            }
            else
            {
                if(k!=0)
                {
                    dc[i].s[j]='\0';
                    j=0;
                    i++;
                    k=0;
                }
            }
            scanf("%c",&c);
        }
        if(k!=0)
        {
            dc[i].s[j]='\0';
            j=0;
            i++;
            k=0;
        }
        qsort(dc,i,sizeof(dc[0]),cmp);
        printf("case #%d:\n%s",n,dc[0].s);
        for(j=1;j<i;j++)
        {
            if(strcmp(dc[j].s,dc[j-1].s)!=0)printf(" %s",dc[j].s);
        }
        printf("\n");
    }
    return 0;
}
