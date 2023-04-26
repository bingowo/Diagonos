#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void *b)
{
    int aa=*(int *)a;
    int bb=*(int *)b;
    int a1=0,b1=0;
    for(int i=0;i<64;i++){
        a1+=(aa&1);
    aa>>=1;
    }
    for(int i=0;i<64;i++){
        b1+=(bb&1);
    bb>>=1;
    }
    if(a1==b1)return aa-bb;
    else return b1-a1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            int m;
        scanf("%d",&m);
    int app[m];
    for(int j=0;j<m;j++)scanf("%d",app+j);
    qsort(app,m,sizeof(int),cmp);
    printf("case #%d:\n",i);
    for(int j=0;j<m;j++){
        printf("%d",app[j]);
        j==m-1?printf("\n"):printf(" ");
    }
    }
    return 0;
}
