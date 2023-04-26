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
    int s[M]={0};
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
    {
        j=1;
        L=0;
        s[0]=getchar();
        while((c=getchar())!='\n')
        {
            temp=c-'A'+1;
            if(s[j-1]==temp)
            {
                s[j-1]=temp;
            }
            else if(s[j-1]!=temp)
            {
                s[j]=temp;
                j++;
            }
        }
        s[j]=0;
        L=j-1;
        printf("case #%d:\n",i);
        for(j=0;j<L;j++)
        {
            printf("%c",s[j]+64);
            s[j]=0;
        }
        printf("\n");
    }
    return 0;
}