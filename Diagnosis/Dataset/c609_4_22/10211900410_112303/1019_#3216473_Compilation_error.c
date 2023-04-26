#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int length(int x)
{
    int l=0;
    if(x<0) l++;
    do{
        l++;
        x/=10;
    }while(x!=0);
    return l;
}
int cmp(const void * a,const void * b)
{
    else return (*(int*)a-*(int*)b);
}
int cmp_l(int N[])
{
    
}
int main()
{
    int N[1000000];
    int i=0;
    while(scanf("%d",&N[i])!='\n'){i++;}
    
    qsort(N,i,sizeof(int),cmp);
    for(int j=0;j<i;j++){
        printf("%d ",N[j]);
    }
    return 0;
}
