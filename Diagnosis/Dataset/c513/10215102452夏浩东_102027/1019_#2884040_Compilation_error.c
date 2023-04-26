#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *A=(int*)a;
    int *B=(int*)b;
    return(*B-*A);
}
int main()
{
    int n=1,m=1;
    while(n!=0 && m!=0)
    {
        scanf("%d %d",&n,&m);
        int a=0,b=0,c=0;
        int *L=(int*)malloc(n*sizeof(int));
        for(int t=0;t<n;t++) L[t]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,%d,&c);
            if(c==1) {L[a]+=3;L[b]-=1;}
            else if(c==-1){L[a]-=1;L[b]+=3;}
            else {L[a]+=1;L[b]+=1;}
        }
        qsort(L,n,sizeof(int),cmp);
        for(int i=0;i<n;i++) i=n-1? printf("%d\n",L[i]):printf("%d ",L[i]);
        free(L);
    }
    return 0;
}