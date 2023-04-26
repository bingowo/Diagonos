#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a,s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1!=*s2) {s1++,s2++;}
    return *s2-*s1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int num=0;
        scanf("%d",&num);
        int line_data[1000][51]={0};
        for(int j=0;j<num;j++)
        {
            int k=0;
            while(scanf("%d",&line_data[j][k])&&line_data[j][k]!=-1) k++;
        }
        qsort(line_data,num,sizeof(line_data[0]),cmp);
        for(int l=0;l<num;l++)
        {
            int k;
            for(k=0;line_data[l][k+1]!=-1;k++)
            {
                printf("%d ",line_data[l][k]);
            }
            printf("%d\n",line_data[l][k]);
        }
    }
    return 0;
}
