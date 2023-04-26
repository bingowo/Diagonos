#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *c=(char *)a;
    char *d=(char *)b;
    return *c-*d;
}
int main()
{
    int T,i,r=0,j,k=0;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
    	char line[2000]={0};
    	char copy[2000]={0};
        gets(line);
        k=0;
        r=strlen(line);
        for(j=0;j<r;j++)
        {
            if(line[j] >= 'A' && line[j] <= 'Z')
                copy[k++]=line[j];
            else continue;
        }
        qsort(copy,strlen(copy),sizeof(copy[0]),cmp);
        k=0;
        printf("case #%d:\n",i);
        for(j=0;j<r;j++)
        {
            if(line[j] >= 'A' && line[j] <= 'Z')
                printf("%c",copy[k++]);
            else printf("%c",line[j]);
        }
        printf("\n");
    }
    return 0;
}