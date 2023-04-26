#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        int line[1000][51];
        int k,j;
        for(k=0; k<n; k++)
        {
            j=0;
            while(scanf("%d",&line[k][j])&&line[k][j]!=-1)
                j++;
        }

        qsort(line,n,sizeof(line[0]),cmp);
        for(k=0; k<n; k++)
        {
            for(j=0; line[k][j+1]!=-1; j++)
                printf("%d ",line[k][j]);
            printf("%d\n",line[k][j]);
        }

    }

    return 0;
}
