#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void *b)
{
    long long int aa=*(long long int *)a;
    long long int bb=*(long long int *)b;
    int a1=0,b1=0;
    for(int i=0;i<64;i++){
        a1+=(aa&1);
    aa>>=1;
    }
    for(int i=0;i<64;i++){
        b1+=(bb&1);
    bb>>=1;
    }
    if(a1==b1){
        if(aa>bb)return 1;
        else return -1;
    }
    else return b1-a1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            int m;
        scanf("%d",&m);
    long long int  app[m];
    for(int j=0;j<m;j++)scanf("%lld",app+j);
    qsort(app,m,sizeof(long long int),cmp);
    printf("case #%d:\n",i);
    for(int j=0;j<m;j++){
        printf("%lld",app[j]);
        j==m-1?printf("\n"):printf(" ");
    }
    }
    return 0;
}
