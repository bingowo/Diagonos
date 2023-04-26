#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double alpha[300];

int cmp(const void*a ,const void* b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    if(alpha[x]==alpha[y])
    {
        return y-x;
    }
    return alpha[y]-alpha[x];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%f",&alpha[65+j]);
            alpha[97+j]=alpha[65+j];
        }
        char str[101];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
}
