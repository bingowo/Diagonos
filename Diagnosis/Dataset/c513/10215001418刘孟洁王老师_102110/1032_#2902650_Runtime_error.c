#include <stdio.h>
#include <stdlib.h>
#define N 1001
#define M 51
int cmp(const void*a,const void*b)
{
    int *s1=*(int**)a;
    int *s2=*(int**)b;
    int i=0;
    while(*(s1+i)!=-1&&*(s2+i)!=-1)
    {
        if(*(s1+i)<*(s2+i)){return 1;break;}
        else if(*(s1+i)>*(s2+i)){return -1;break;}
        else i++;
    }
    if(*(s1+i)==-1)return 1;
    else return -1;

}

int main()
{
    int n,i,cas,x,k,j;
    int **t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cas);
        t=(int**)malloc(n*sizeof(int*));
        k=0;
        for(j=0;j<cas;j++)
          while(scanf("%d",&t[j][k])!=-1)k++;
        qsort(t,cas,sizeof(t[0]),cmp);
        for(j=0;j<cas;j++)
            for(x=0;x<k;x++)printf("%d%c",t[j][x],x==k-1?'\n':' ');
    }
    free(t);
    return 0;
}

