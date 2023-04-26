#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long myabs(long long a)
{
    if(a>=0)
        return a;
    else
        return -a;
}

int firstnum(long long a)
{
    long long b=myabs(a);
    while(b>=10)
        b=b/10;
    int c=b;
    //printf("%d no firstnum:%d\n",a,c);
    return c;
}

int cmpfuncup (const void * a, const void * b)
{
   int c=*(int*)a - *(int*)b ;
        return c;
}

int cmpfuncdown (const void * a, const void * b)
{
   int c=*(int*)b - *(int*)a ;
        return c;
}
int main()
{
    int quesnum;
    scanf("%d\n",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int yoko;
        scanf("%d",&yoko);
        int num0[1001][51]={0};
        int num[1001][51]={0};
        int kazu[1001]={0};
        for(int j=0;j<yoko;j++)
        {
            scanf("%d",&num0[j][0]);
            num[j][0]=num0[j][0];
            kazu[j]=1;
            while(num[j][kazu[j]-1]!=-1)
            {
                scanf("%d",&num0[j][kazu[j]]);
                num[j][kazu[j]]=num0[j][kazu[j]];
                kazu[j]++;
            }
            qsort(num[j],kazu[j]-1,sizeof(int),cmpfuncdown);
        }
        for(int j=0;j<yoko;j++)
        {
            int max=0;
            for(int k=0;k<yoko;k++)
            {if(max==k)
                    max++;
            int p=0;
            while(num[max][p]==num[k][p])
                p++;
            if(num[max][p]<num[k][p])
                max=k;}
            for(int k=0;k<kazu[max]-2;k++)
                printf("%d ",num0[max][k]);
            printf("%d\n",num0[max][kazu[max]-2]);
            num[max][0]=-1;
        }
    }

    return 0;
}
