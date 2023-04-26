#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,j,k;
    int count=0;
    int num=0;
    scanf("%d",&m);
    char *org=(char*)malloc(sizeof(char)*100);
    int *aft=(int*)malloc(sizeof(int)*100);
    for(int i=0;i<m;i++)
    {
        *aft=1;
        printf("case #%d:\n",i);
        j=0;
        while(scanf("%c")!='\n')
            {
                scanf("%c",org+j);
                j++;
            }
        for(k=0;k<j+1;k++)
            for(i=0;i<k;i++)
            {
                if(*(org+i)==*(org+k)) break;
                if(i==k) count++;
            }
        for(k=1;k<j+1;k++)
            if(*(org+k)==*org) *(aft+k)=1;
        for(k=1;k<j+1;k++)
            if(*(org+k)!=*org) *(aft+k)=0;break;
        for(i=1;i<j+1;i++)
            if(*(org+i)==*(org+k)) *(aft+i)=0;
        for(int j=0;j<count-1;j++)
        {
            for()
        }
        while(g<count)
        {
            for(k=1;k<j+1;k++)
            if(*(org+k)!=1) *(aft+k)=0;break;
            g++;
        }
    }
    return 0;
}