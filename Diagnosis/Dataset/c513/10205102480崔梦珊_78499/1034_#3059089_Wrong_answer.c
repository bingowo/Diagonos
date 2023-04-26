#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double alpha[300]={0};
double alpha1[300]={0};
int cmp(const void*a ,const void* b)
{
    char x=*(char*) a;
    char y=*(char*) b;
    if(alpha[x]==alpha[y])
    {
        return alpha[x]-alpha[y];
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
            alpha1['a'+j]=j*2;
            alpha1['A'+j]=j+1;
        }
        /*for(int j=0;j<26;j++)
        {
            printf("%f",alpha['A'+j]);
        }*/
        char str[200];
        scanf("%s",str);
        str[strlen(str)]='\0';
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
}
