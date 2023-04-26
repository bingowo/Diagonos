#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a,const void* b) //降序
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(a<b) return -1;
    else return 1;
}

int cmp2(const void* a,const void* b) //升序
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(a<b) return 1;
    else return -1;
}

int main()
{
    char c;
    scanf("%c",&c);
    int res[101]={'\0'};
    int i=0;
    for(i=0;scanf("%d",&res[i])!=EOF;i++);
    i--;
    int hash[101]={'\0'};
    int m=0;
    for(int j=0;j<i;j++)
    {
        if(res[j]!='\0')
        for(int k=j;k<j;k++)
        {
            if(res[k]==res[j])
            {
                res[k]='\0';
                break;
            }
            hash[m]=res[j];
            m++;
        }
    }
    m--;
    if(c=='D')
        qsort(hash,m,sizeof(hash[0]),cmp1);
    else
        qsort(hash,m,sizeof(hash[0]),cmp2);
    printf("%d",hash[0]);
    for(int k=1;k<m+1;k++)
    {
        printf("%d ",hash[k]);
    }
    return 0;
}
