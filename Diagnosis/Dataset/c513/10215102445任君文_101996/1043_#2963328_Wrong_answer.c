#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100
int main()
{
    int T;
    int temp=0;
    int i,j;
    int L;
    char c;
    int s1[M]={0};
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
    {
        j=0;
        L=0;
        while((c=getchar())!='\n')
        {
            temp=c-'A'+1;
            s1[j]=temp;
            j++;
        }
        s1[j]=0;
        L=j;
        printf("case #%d:\n",i);
        for(j=0;j<L;j++)
        {
            printf("%c",s1[j]+64);
            s1[j]=0;
        }
        printf("\n");
    }
    return 0;
}