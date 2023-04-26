#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double alpha[300]={0};

int cmp(const void*a ,const void* b)
{
    char x=*(char*) a;
    char y=*(char*) b;
    if(alpha[x]==alpha[y])
    {
        return y-x;
    }
    if(alpha[x]>alpha[y])
    {
        return -1;
    }
    return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%lf",&alpha['A'+j]);
            alpha['a'+j]=alpha['A'+j];
        }
        /*for(int j=0;j<26;j++)
        {
            printf("%f",alpha['A'+j]);
        }*/
        char str[101];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
}
